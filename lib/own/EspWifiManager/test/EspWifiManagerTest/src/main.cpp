#include <stdio.h>
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <esp_log.h>

#include <EspWifiManager.h>
#include "Logger.h"
#include <LoggerTarget.h>
#include <SerialLoggerTarget.h>

extern "C"
{
  void app_main(void);
}

const char *SERIAL_LOGGER_TAG = "SLT";

void app_main()
{
  printf("==================\n");
  printf("EsWifiManager Test\n");
  printf("==================\n");
  Logger.init("EsWifiManagerTest");

  SerialLoggerTarget *slt = new SerialLoggerTarget("Serial", 0);
  Logger.addLoggerTarget(slt);
  Logger.info("Main", "EspWifiManagerTest");

  printf("Sends a logmessage for each loglevel in a loop\n\n");
  SerialLoggerTarget *serialLoggerTarget = new SerialLoggerTarget(SERIAL_LOGGER_TAG, LOG_LEVEL_INFO);
  Logger.addLoggerTarget(serialLoggerTarget);
  if (EspWifiManager.startWifi())
  {
    Logger.info("Main", "NORMAL START");
    char ipAddress[30];
    EspWifiManager.getIpAddress(ipAddress);
    Logger.info("Main, app_main(), getIpAddress()", ipAddress);
  }
  else{
    Logger.error("Main, app_main", "NO CONNECTION TO WiFi");
  }

}
