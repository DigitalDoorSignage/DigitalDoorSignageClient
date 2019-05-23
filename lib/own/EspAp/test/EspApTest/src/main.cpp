#include <stdio.h>
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <esp_log.h>

#include "Logger.h"
#include <LoggerTarget.h>
#include <SerialLoggerTarget.h>
#include <EspAp.h>

extern "C" {
	void app_main(void);
}

const char* SERIAL_LOGGER_TAG = "SLT";

void app_main()
{
  printf("====================\n");
  printf("Esp Accesspoint Test\n");
  printf("====================\n");
  Logger.init("EspApTest");
  SerialLoggerTarget* serialLoggerTarget = new SerialLoggerTarget(SERIAL_LOGGER_TAG, LOG_LEVEL_INFO);
  Logger.addLoggerTarget(serialLoggerTarget);
  EspAp.init();
}
