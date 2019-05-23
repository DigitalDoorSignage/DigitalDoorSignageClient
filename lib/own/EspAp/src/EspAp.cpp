#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include <EspAp.h>

// Event group
static EventGroupHandle_t event_group;
const int STA_CONNECTED_BIT = BIT0;
const int STA_DISCONNECTED_BIT = BIT1;

static bool _isApStarted = false;

// AP event handler
static esp_err_t event_handler(void *ctx, system_event_t *event)
{
    switch (event->event_id)
    {

    case SYSTEM_EVENT_AP_START:
        printf("Access point started\n");
        _isApStarted = true;
        break;

    case SYSTEM_EVENT_AP_STACONNECTED:
        xEventGroupSetBits(event_group, STA_CONNECTED_BIT);
        break;

    case SYSTEM_EVENT_AP_STADISCONNECTED:
        xEventGroupSetBits(event_group, STA_DISCONNECTED_BIT);
        break;

    default:
        break;
    }

    return ESP_OK;
}

// print the list of connected stations
void printStationList()
{
    printf(" Connected stations:\n");
    printf("--------------------------------------------------\n");

    wifi_sta_list_t wifi_sta_list;
    tcpip_adapter_sta_list_t adapter_sta_list;

    memset(&wifi_sta_list, 0, sizeof(wifi_sta_list));
    memset(&adapter_sta_list, 0, sizeof(adapter_sta_list));

    ESP_ERROR_CHECK(esp_wifi_ap_get_sta_list(&wifi_sta_list));
    ESP_ERROR_CHECK(tcpip_adapter_get_sta_list(&wifi_sta_list, &adapter_sta_list));

    for (int i = 0; i < adapter_sta_list.num; i++)
    {

        tcpip_adapter_sta_info_t station = adapter_sta_list.sta[i];
        printf("%d - mac: %.2x:%.2x:%.2x:%.2x:%.2x:%.2x - IP: %s\n", i + 1,
               station.mac[0], station.mac[1], station.mac[2],
               station.mac[3], station.mac[4], station.mac[5],
               ip4addr_ntoa(&(station.ip)));
    }

    printf("\n");
}

// Monitor task, receive Wifi AP events
void monitor_task(void *pvParameter)
{
    while (1)
    {

        EventBits_t staBits = xEventGroupWaitBits(event_group, STA_CONNECTED_BIT | STA_DISCONNECTED_BIT, pdTRUE, pdFALSE, portMAX_DELAY);
        if ((staBits & STA_CONNECTED_BIT) != 0)
            printf("New station connected\n\n");
        else
            printf("A station disconnected\n\n");
    }
}

// Station list task, print station list every 10 seconds
void station_list_task(void *pvParameter)
{
    while (1)
    {

        printStationList();
        vTaskDelay(10000 / portTICK_RATE_MS);
    }
}

void getSsidText(char ssidText[])
{
    uint8_t mac[6];
    esp_err_t ok = esp_efuse_mac_get_default(mac);
    if (ok != ESP_OK)
    {
        sprintf(ssidText, "MAC_ERR_%d", ok);
        return;
    }
    sprintf(ssidText, "ESP_%02X%02X%02X%02X%02X%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

wifi_config_t wifi_config = {};
wifi_ap_config_t wifi_ap_config = {};

EspApClass::EspApClass()
{
}
bool EspApClass::isApStarted(){
    return _isApStarted;
}

void EspApClass::init()
{
    // disable the default wifi logging
    //esp_log_level_set("wifi", ESP_LOG_NONE);

    // create the event group to handle wifi events
    event_group = xEventGroupCreate();

    // initialize NVS
    ESP_ERROR_CHECK(nvs_flash_init());

    // initialize the tcp stack
    tcpip_adapter_init();

    // stop DHCP server
    ESP_ERROR_CHECK(tcpip_adapter_dhcps_stop(TCPIP_ADAPTER_IF_AP));

    // assign a static IP to the network interface
    tcpip_adapter_ip_info_t info;
    memset(&info, 0, sizeof(info));
    IP4_ADDR(&info.ip, 192, 168, 10, 1);
    IP4_ADDR(&info.gw, 192, 168, 10, 1);
    IP4_ADDR(&info.netmask, 255, 255, 255, 0);
    ESP_ERROR_CHECK(tcpip_adapter_set_ip_info(TCPIP_ADAPTER_IF_AP, &info));

    // start the DHCP server
    ESP_ERROR_CHECK(tcpip_adapter_dhcps_start(TCPIP_ADAPTER_IF_AP));

    // initialize the wifi event handler
    ESP_ERROR_CHECK(esp_event_loop_init(event_handler, NULL));

    // initialize the wifi stack in AccessPoint mode with config in RAM
    wifi_init_config_t wifi_init_config = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&wifi_init_config));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_AP));

    char ssidText[32];
    for (int i = 0; i < 32; i++)
        ssidText[i] = 0;
    getSsidText(ssidText);
    printf("SSID: %s, Len: %d\n", ssidText, strlen(ssidText));
    //  wifi_ap_config_t wifi_ap_config;
    // for (int i = 0; i < 32; i++)
    // {
    //  wifi_ap_config.ssid[i] = ssidText[i];
    // }
    memcpy(wifi_ap_config.ssid, ssidText, strlen(ssidText));
    wifi_ap_config.ssid_len = strlen(ssidText);
    //memcpy(wifi_ap_config.ssid, "AP01", 4);
    //wifi_ap_config.ssid_len = 4;
    // memcpy(wifi_ap_config.password, "3101",4);
    wifi_ap_config.channel = 0;
    //wifi_ap_config.authmode = WIFI_AUTH_WPA2_PSK;
    wifi_ap_config.beacon_interval = 100;
    wifi_ap_config.max_connection = 4;
    // wifi_ap_config.ssid_hidden = 0;
    //wifi_config_t wifi_config = {};
    wifi_config.ap = wifi_ap_config;
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_AP, &wifi_config));

    // start the wifi interface
    ESP_ERROR_CHECK(esp_wifi_start());
    printf("Starting access point, SSID=%s\n", wifi_ap_config.ssid);

    // start the main task
    xTaskCreate(&monitor_task, "monitor_task", 2048, NULL, 5, NULL);
    xTaskCreate(&station_list_task, "station_list_task", 2048, NULL, 5, NULL);
}

EspApClass EspAp;