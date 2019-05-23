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
#include <EspMqttClient.h>
#include <SystemService.h>
#include <EspUdp.h>

#define HOST_IP_ADDR "192.168.0.23"
#define CLIENTPORT 41234

extern "C"
{
  void app_main(void);
}

const char *SERIAL_LOGGER_TAG = "SLT";

void app_main()
{
  printf("===========\n");
  printf("EspUdp Test\n");
  printf("===========\n");
  EspConfig.init();
  const char *thingName = EspConfig.getThingName();
  Logger.init("EspUdpTest");
  SerialLoggerTarget *serialLoggerTarget = new SerialLoggerTarget(SERIAL_LOGGER_TAG, LOG_LEVEL_VERBOSE);
  Logger.addLoggerTarget(serialLoggerTarget);
  SystemService.init();
  EspStation.init();
  Logger.info("EspUdpTest, app_main()", "Waiting for connection!");
  while (!EspStation.isStationOnline())
  {
    vTaskDelay(1 / portTICK_PERIOD_MS);
  }
  HttpServer.init();
  Logger.info("EspUdpTest, app_main()", "HttpServer started");

  char loggerMessage[LENGTH_LOGGER_MESSAGE];
  EspConfig.getConfig(loggerMessage, LENGTH_LOGGER_MESSAGE - 1);
  Logger.info("EspUdpTest, Config", loggerMessage);
  EspTime.init();
  EspMqttClient.init(thingName);
  EspUdp.init();
  Logger.info("EspUdpTest, app_main()", "Udp-Sender and UDP-Receiver running!");
  while (true)
  {
    SystemService.checkSystem();
    vTaskDelay(1);
    // Logger.info("EspUdpTest;app_main()", "loop");
  }
}
