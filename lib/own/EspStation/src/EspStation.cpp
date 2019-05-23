#include "EspStation.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include <string.h>

#include <EspConfig.h>
#include <Logger.h>

// Event group
static EventGroupHandle_t wifi_event_group;
const int CONNECTED_BIT = BIT0;
bool _isStationOnline = false;

// Wifi event handler
static esp_err_t event_handler(void *ctx, system_event_t *event)
{
    // char loggerMessage[LENGTH_LOGGER_MESSAGE];
    switch (event->event_id)
    {

    case SYSTEM_EVENT_STA_START:
        Logger.info("EspStation, eventHandler()", "SYSTEM_EVENT_STA_START");
        esp_wifi_connect();
        break;

    case SYSTEM_EVENT_STA_GOT_IP:
        xEventGroupSetBits(wifi_event_group, CONNECTED_BIT);
        Logger.info("EspStation, eventHandler()", "SYSTEM_EVENT_STA_GOT_IP");
        _isStationOnline = true;
        break;

    case SYSTEM_EVENT_STA_DISCONNECTED:
        xEventGroupClearBits(wifi_event_group, CONNECTED_BIT);
        Logger.error("EspStation, eventHandler()", "SYSTEM_EVENT_STA_DISCONNECTED !!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        esp_wifi_connect();  //! reconnect
        _isStationOnline = false;
        break;

    default:
        break;
    }

    return ESP_OK;
}

void EspStationClass::init()
{
    // create the event group to handle wifi events
	wifi_event_group = xEventGroupCreate();

    char loggerMessage[LENGTH_LOGGER_MESSAGE];
    char *ssid = EspConfig.getSsid();
    if (strlen(ssid) == 0)
    {
        Logger.error("EspStation, init()", "SSID empty!");
    }
    char *password = EspConfig.getPassword();
    if (strlen(password) == 0)
    {
        Logger.error("EspStation, init()", "PASSWORD empty!");
    }

    tcpip_adapter_init();
    esp_err_t err = esp_event_loop_init(event_handler, NULL);
    if (err != ESP_OK)
    {
        sprintf(loggerMessage, "esp_event_loop_init() ERROR: %d", err);
        Logger.error("EspStation, init()", loggerMessage);
        return;
    }
    // initialize the wifi stack in STAtion mode with config in RAM
    wifi_init_config_t wifi_init_config = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&wifi_init_config));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));

    // configure the wifi connection and start the interface
    wifi_sta_config_t staConfig ={};  // die beiden Klammern sind notwendig!
    memcpy(staConfig.ssid, ssid, strlen(ssid));
    memcpy(staConfig.password, password, strlen(password));
    staConfig.ssid[strlen(ssid)] = 0;
    staConfig.password[strlen(password)] = 0;
    wifi_config_t wifi_config = {
        .sta = staConfig};
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());
    sprintf(loggerMessage, "Connecting to %s\n", wifi_config.sta.ssid);
    Logger.info("EspStation, init()", loggerMessage);

    // wait for connection
    xEventGroupWaitBits(wifi_event_group, CONNECTED_BIT, false, true, portMAX_DELAY);
    Logger.info("EspStation, init()", "Connected");
    tcpip_adapter_ip_info_t ip_info;
    ESP_ERROR_CHECK(tcpip_adapter_get_ip_info(TCPIP_ADAPTER_IF_STA, &ip_info));
    sprintf(loggerMessage, "************** IP Address:  %s ******************", ip4addr_ntoa(&ip_info.ip));
    Logger.info("EspStation, event_handler(), GotIp:", loggerMessage);
}

bool EspStationClass::isStationOnline()
{
    return _isStationOnline;
}

EspStationClass EspStation;