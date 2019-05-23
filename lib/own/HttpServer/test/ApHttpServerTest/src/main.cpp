#include <stdio.h>
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <esp_log.h>

#include "Logger.h"
#include <LoggerTarget.h>
#include <SerialLoggerTarget.h>
#include <EspAp.h>
#include <EspConfig.h>
#include <HttpServer.h>

extern "C"
{
  void app_main(void);
}

const char *SERIAL_LOGGER_TAG = "SLT";

void app_main()
{
  printf("=======================\n");
  printf("HttpServer with AP Test\n");
  printf("=======================\n");
  EspConfig.init();
  Logger.init("HttpServerTest");
  SerialLoggerTarget *serialLoggerTarget = new SerialLoggerTarget(SERIAL_LOGGER_TAG, LOG_LEVEL_INFO);
  Logger.addLoggerTarget(serialLoggerTarget);
  EspAp.init();
  while (!EspAp.isApStarted())
  {
    vTaskDelay(1 / portTICK_PERIOD_MS);
  }
  Logger.info("HttpServer, app_main()", "AP started");
  HttpServer.init();
}
