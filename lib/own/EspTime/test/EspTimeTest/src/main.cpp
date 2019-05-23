#include <stdio.h>
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <esp_log.h>

#include "Logger.h"
#include <LoggerTarget.h>
#include <SerialLoggerTarget.h>
#include <EspStation.h>
#include <HttpServer.h>
#include <EspConfig.h>
#include <EspTime.h>

extern "C"
{
  void app_main(void);
}

const char *SERIAL_LOGGER_TAG = "SLT";

void loop()
{
  char loggerMessage[LENGTH_LOGGER_MESSAGE];
  char dateString[LENGTH_SHORT_TEXT];
  char timeString[LENGTH_SHORT_TEXT];
  while (true)
  {
    sprintf(loggerMessage, "Seconds since 1970: %ld", EspTime.getTime());
    Logger.info("EspTimeTest, loop()", loggerMessage);
    EspTime.getDateString(dateString);
    EspTime.getTimeString(timeString);
    sprintf(loggerMessage, "Date: %s, Time: %s", dateString , timeString);
    Logger.info("EspTimeTest, loop()", loggerMessage);
    vTaskDelay(3000 / portTICK_RATE_MS);
  }
}

void app_main()
{
  printf("============\n");
  printf("EspTime Test\n");
  printf("============\n");
  EspConfig.init();
  Logger.init("EspTimeTest");
  SerialLoggerTarget *serialLoggerTarget = new SerialLoggerTarget(SERIAL_LOGGER_TAG, LOG_LEVEL_VERBOSE);
  Logger.addLoggerTarget(serialLoggerTarget);
  EspStation.init();
  Logger.info("EspTimeTest, app_main()", "Waiting for connection!");
  while (!EspStation.isStationOnline())
  {
    vTaskDelay(1 / portTICK_PERIOD_MS);
  }
  HttpServer.init();
  Logger.info("EspTimeTest, app_main()", "HttpServer started");

  char loggerMessage[LENGTH_LOGGER_MESSAGE];
  EspConfig.getConfig(loggerMessage, LENGTH_LOGGER_MESSAGE - 1);
  Logger.info("EspTimeTest, Config", loggerMessage);
  EspTime.init();
  loop();
}
