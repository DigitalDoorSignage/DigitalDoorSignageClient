#include <stdio.h>
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <esp_log.h>

#include "Logger.h"
#include <LoggerTarget.h>
#include <SerialLoggerTarget.h>

extern "C" {
	void app_main(void);
}

const char* SERIAL_LOGGER_TAG = "SLT";

// static const char* TAG = "Log-Tag";

void loop()
{
  LoggerTarget *serialLogger = Logger.getLoggerTarget(SERIAL_LOGGER_TAG);
  int logLevel = serialLogger->getLogLevel();
  printf("Actual minimum Loglevel set: %s\n", Logger.getLogLevelText(logLevel));
  Logger.verbose("main, loop()", "Verbose");
  Logger.debug("main, loop()", "Debug");
  Logger.info("main, loop()",  "Info");
  Logger.warning("main, loop()", "Warning");
  Logger.error("main, loop()", "Error");
  if (logLevel == LOG_LEVEL_ERROR)
  {
    logLevel = LOG_LEVEL_VERBOSE;
    serialLogger->setLogLevel(logLevel);
    printf("-----------------------------------------------------------------------\n");
  }
  else
  {
    logLevel++;
    serialLogger->setLogLevel(logLevel);
    printf("\n");
  }
  // ESP_LOGI(TAG, "Message for Level: %i", logLevel);
  vTaskDelay(1000/ portTICK_PERIOD_MS);
}

void app_main()
{
  printf("===========\n");
  printf("Logger Test\n");
  printf("===========\n");
  Logger.init("LoggerTest");
  printf("Sends a logmessage for each loglevel in a loop\n\n");
  SerialLoggerTarget* serialLoggerTarget = new SerialLoggerTarget(SERIAL_LOGGER_TAG, LOG_LEVEL_INFO);
  Logger.addLoggerTarget(serialLoggerTarget);
  while (true)
  {
    loop();
  }
}
