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

#include <GxEPD.h>
#include <GxGDEW042T2/GxGDEW042T2.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>


#define TAG "HTTP CLIENT"

extern "C"
{
    void app_main(void);
}

// GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/17, /*RST=*/16); // arbitrary selection of 17, 16
// GxEPD_Class display(io, /*RST=*/16, /*BUSY=*/4);		// arbitrary selection of (16), 4
char* room;
Storage storage;

static void writeLessonToDisplay(char* newClass, char* newTeacher, char* newSubject)
{
	int x, y = 0;
	boolean classChanged = klass.compare(newClass) != 0;
	boolean teacherChanged = teacher.compare(newTeacher) != 0;
	boolean subjectChanged = subject.compare(newSubject) != 0;

	if (classChanged || teacherChanged || subjectChanged)
	{
		display.fillScreen(GxEPD_WHITE);
	}
	// top left text
	if (classChanged)
	{
		x = 5 + calculateCenteredXOfText(newClass, 240);
		y = 63;
		display.setCursor(x, y);
		display.print(newClass);
		display.updateWindow(8, 6, 230, 95, false);
	}
	// middle text
	if (teacherChanged)
	{
		x = 5 + calculateCenteredXOfText(newTeacher, 390);
		y = 160;
		display.setCursor(x, y);
		display.print(newTeacher);
		display.updateWindow(8, 102, 385, 95, false);
	}
	// bottom text
	if (subjectChanged)
	{
		x = 5 + calculateCenteredXOfText(newSubject, 390);
		y = 257;
		display.setCursor(x, y);
		display.print(newSubject);
		display.updateWindow(8, 198, 385, 95, false);
	}
}


int calculateWidthOfText(char* text)
{
    return strlen(text) * 21 - 3;
}

int calculateCenteredXOfText(char* text, int width)
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