#include <stdio.h>
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <esp_log.h>

#include <stdlib.h>
#include <string>

//util
#include <Storage/Storage.h>
#include <HttpClient/HttpClient.h>
//own
#include <EspConfig.h>
#include <EspStation.h>
#include <HttpServer.h>
#include <EspWifiManager.h>
#include <EspAp.h>


#define TAG "HTTP CLIENT"

extern "C"
{
    void app_main(void);
}

// GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/17, /*RST=*/16); // arbitrary selection of 17, 16
// GxEPD_Class display(io, /*RST=*/16, /*BUSY=*/4);		// arbitrary selection of (16), 4
std::string room;
Storage storage;

int calculateWidthOfText(std::string text)
{
    return text.length() * 21 - 3;
}

int calculateCenteredXOfText(std::string text, int width)
{
    return (width - calculateWidthOfText(text)) / 2;
}

void main_task(void *param){
    printf("start\n");
    fflush(stdout);
    EspConfig.init();
    //EspAp.init();
    EspStation.init();
    HttpServer.init();

    HttpClient temp;
    temp.get("http://localhost:8080/webuntisclient-1.0-SNAPSHOT/api/state?room=E23"); 
    

    while(1){
        vTaskDelay(10);
        // printf("loop");
        // HttpClient temp;
        // temp.get("http://localhost:8080/webuntisclient-1.0-SNAPSHOT/api/state?room=E23"); 
        // printf("test\n");
        // fflush(stdout);
    }
}

void app_main()
{
    xTaskCreate(&main_task, "main_task", 4096, NULL, 5, NULL);
}