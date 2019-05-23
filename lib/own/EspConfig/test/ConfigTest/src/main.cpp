#include <stdio.h>
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <esp_log.h>

#include "Logger.h"
#include <LoggerTarget.h>
#include <SerialLoggerTarget.h>
#include <EspAp.h>
#include <HttpServer.h>
#include <EspConfig.h>

extern "C"
{
  void app_main(void);
}

const char *SERIAL_LOGGER_TAG = "SLT";

void app_main()
{
  printf("===========\n");
  printf("Config Test\n");
  printf("===========\n");
  EspConfig.init();
  Logger.init("ConfigTest");
  SerialLoggerTarget *serialLoggerTarget = new SerialLoggerTarget(SERIAL_LOGGER_TAG, LOG_LEVEL_VERBOSE);
  Logger.addLoggerTarget(serialLoggerTarget);
  EspAp.init();
  while (!EspAp.isApStarted())
  {
    vTaskDelay(1 / portTICK_PERIOD_MS);
  }
  HttpServer.init();
  Logger.info("EspConfig, app_main()", "AP started");

  char loggerMessage[LENGTH_LOGGER_MESSAGE];
  EspConfig.getConfig(loggerMessage, LENGTH_LOGGER_MESSAGE-1);
  Logger.info("EspConfig, Config", loggerMessage);
}
