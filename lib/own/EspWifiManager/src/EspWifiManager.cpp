#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#include <Logger.h>
#include "EspWifiManager.h"

#define EXAMPLE_ESP_WIFI_SSID      "A1-B5035B"
#define EXAMPLE_ESP_WIFI_PASS      "52809766B6"
#define EXAMPLE_ESP_MAXIMUM_RETRY  5


/* FreeRTOS event group to signal when we are connected*/
static EventGroupHandle_t s_wifi_event_group;

/* The event group allows multiple bits for each event, but we only care about one event 
 * - are we connected to the AP with an IP? */
const int WIFI_CONNECTED_BIT = BIT0;

static const char *TAG = "wifi station";

static int s_retry_num = 0;

static esp_err_t event_handler(void *ctx, system_event_t *event)
{
    switch(event->event_id) {
    case SYSTEM_EVENT_STA_START:
        esp_wifi_connect();
        break;
    case SYSTEM_EVENT_STA_GOT_IP:
        ESP_LOGI(TAG, "got ip:%s",
                 ip4addr_ntoa(&event->event_info.got_ip.ip_info.ip));
        s_retry_num = 0;
        xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
        break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
        {
            if (s_retry_num < EXAMPLE_ESP_MAXIMUM_RETRY) {
                esp_wifi_connect();
                xEventGroupClearBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
                s_retry_num++;
                ESP_LOGI(TAG,"retry to connect to the AP");
            }
            ESP_LOGI(TAG,"connect to the AP fail\n");
            break;
        }
    default:
        break;
    }
    return ESP_OK;
}


/**
 * Hilfsmethode zum Loggen von Resultcodes von Wifi-Functions
 */
void logResultCodeForFunction(const char *module, const char *functionName, esp_err_t resultCode)
{
	char loggerMessage[LENGTH_LOGGER_MESSAGE];
	sprintf(loggerMessage, "Module: %s, Function: %s, result: %d", module, functionName, resultCode);
}

/**
 * Aktuelle IP-Adresse des ESP in übergebenes char[] speichern
 */
void EspWifiManagerClass::getIpAddress(char *ipAddress)
{
	tcpip_adapter_ip_info_t ipInfo;
	logResultCodeForFunction("getIpAddress", "tcpip_adapter_get_ip_info", tcpip_adapter_get_ip_info(TCPIP_ADAPTER_IF_STA, &ipInfo));
	sprintf(ipAddress, "%d.%d.%d.%d", IP2STR(&ipInfo.ip));
}

// /**
//  * Eventhandler für Wifi-Events. Werden teilweise verwendet, um den Status der Verbindung zu verwalten.
//  */
// static esp_err_t wifi_event_handler(void *ctx, system_event_t *event)
// {
// 	char loggerMessage[LENGTH_LOGGER_MESSAGE];
// 	switch (event->event_id)
// 	{
// 	case SYSTEM_EVENT_STA_START:
// 		esp_wifi_connect();
// 		Logger.info("EspWifiManager, wifi_event_handler()", "SYSTEM_EVENT_STA_START");
// 		break;
// 	case SYSTEM_EVENT_STA_GOT_IP:
// 		xEventGroupSetBits(wifi_event_group, CONNECTED_BIT);
// 		sprintf(loggerMessage, "**** SYSTEM_EVENT_STA_GOT_IP: %s *****\n", ip4addr_ntoa(&event->event_info.got_ip.ip_info.ip));
// 		Logger.info("EspWifiManager, wifi_event_handler()", loggerMessage);
// 		isWifiConnected = true; // ab jetzt kann übertragen werden
// 		break;
// 	case SYSTEM_EVENT_STA_DISCONNECTED:
// 		//esp_wifi_connect();
// 		xEventGroupClearBits(wifi_event_group, CONNECTED_BIT);
// 		Logger.info("EspWifiManager, wifi_event_handler()", "SYSTEM_EVENT_STA_DISCONNECTED");
// 		isWifiConnected = false;
// 		break;
// 	default:
// 		break;
// 	}
// 	return ESP_OK;
// }

// /**
//  * Versuch sich mit den im ESP intern gespeicherten Credentials anzumelden.
//  */
// bool EspWifiManagerClass::connectWithSavedCredentials()
// {
// 	// nvs_flash_init();
// 	tcpip_adapter_init();
// 	wifi_event_group = xEventGroupCreate();
// 	wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
// 	// wifi_config_t wifi_config = {};
// 	// wifi_sta_config_t wifi_sta_config = {};
// 	// memcpy(wifi_sta_config.ssid, WIFI_SSID, strlen(WIFI_SSID));
// 	// memcpy(wifi_sta_config.password, WIFI_PASSWORD, strlen(WIFI_PASSWORD));
// 	// wifi_config.sta = wifi_sta_config;

// 	logResultCodeForFunction("connectWithSavedCredentials", "esp_event_loop_init", esp_event_loop_init(wifi_event_handler, NULL));
// 	logResultCodeForFunction("connectWithSavedCredentials", "esp_wifi_init", esp_wifi_init(&cfg));
// 	logResultCodeForFunction("connectWithSavedCredentials", "esp_wifi_set_storage", esp_wifi_set_storage(WIFI_STORAGE_RAM));
// 	logResultCodeForFunction("connectWithSavedCredentials", "esp_wifi_set_mode", esp_wifi_set_mode(WIFI_MODE_STA));
// 	//	logResultCodeForFunction("connectWithSavedCredentials", "esp_wifi_set_config", esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));
// 	logResultCodeForFunction("connectWithSavedCredentials", "esp_wifi_start", esp_wifi_start());

// 	Logger.info("EspWifiManager, connectWithSavedCredentials()", "Waiting for wifi");
// 	//xEventGroupWaitBits(wifi_event_group, CONNECTED_BIT, false, true, portMAX_DELAY);
// 	int maxDelayConnectionMs = 3000;
// 	while (maxDelayConnectionMs > 0 && !isWifiConnected)
// 	{
// 		vTaskDelay(1000 / portTICK_PERIOD_MS);
// 		maxDelayConnectionMs -= 1;
// 	}
// 	return maxDelayConnectionMs > 0;
// }

/**
 * Versuch, Wifi zu starten. Ist das Flag HasToStartWithConfigPage gesetzt (J) wird die Konfigurationsseite
 * des WiFiManagers aufgerufen.
 * Sonst wird versucht, sich mit gespeicherten Credentials anzumelden. Im Fehlerfall wird das Flag
 * HasToStartWithConfigPage gesetzt und neu gestartet.
 */
bool EspWifiManagerClass::startWifi()
{
    s_wifi_event_group = xEventGroupCreate();

    tcpip_adapter_init();
    ESP_ERROR_CHECK(esp_event_loop_init(event_handler, NULL) );

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
	// wifi_sta_config_t stationConfig;
	// stationConfig.ssid="EXAMPLE_ESP_WIFI_SSID";
	// stationConfig.password = EXAMPLE_ESP_WIFI_PASS;
    // wifi_config_t wifi_config = { };
	// wifi_config.sta = stationConfig;

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA) );
    // ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config) );
    ESP_ERROR_CHECK(esp_wifi_start() );

    ESP_LOGI(TAG, "wifi_init_sta finished.");
    ESP_LOGI(TAG, "connect to ap SSID:%s password:%s",
             EXAMPLE_ESP_WIFI_SSID, EXAMPLE_ESP_WIFI_PASS);
			 return true;
}


EspWifiManagerClass EspWifiManager;
