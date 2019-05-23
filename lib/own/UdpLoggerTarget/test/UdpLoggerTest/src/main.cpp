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
#include <UdpLoggerTarget.h>

extern "C"
{
  void app_main(void);
}

#define HTTP_OK 200


const char *SERIAL_LOGGER_TAG = "SLT";

void app_main()
{
  printf("==============\n");
  printf("UdpLogger Test\n");
  printf("==============\n");
  EspConfig.init();
  const char *thingName = EspConfig.getThingName();
  Logger.init("UdpLoggerTest");
  SerialLoggerTarget *serialLoggerTarget = new SerialLoggerTarget(SERIAL_LOGGER_TAG, LOG_LEVEL_VERBOSE);
  Logger.addLoggerTarget(serialLoggerTarget);
  SystemService.init();
  EspStation.init();
  Logger.info("UdpLoggerTest, app_main()", "Waiting for connection!");
  while (!EspStation.isStationOnline())
  {
    vTaskDelay(1 / portTICK_PERIOD_MS);
  }
  HttpServer.init();
  Logger.info("UdpLoggerTest, app_main()", "HttpServer started");
  EspTime.init();
  EspMqttClient.init(thingName);
  EspUdp.init();
  char loggerMessage[LENGTH_LOGGER_MESSAGE];
  EspConfig.getConfig(loggerMessage, LENGTH_LOGGER_MESSAGE - 1);
  Logger.info("UdpLoggerTest, Config", loggerMessage);
  Logger.info("UdpLoggerTest, app_main()", "Udp-Sender and UDP-Receiver running!");

  while (true)
  {
    SystemService.checkSystem();
    vTaskDelay(1);
  }
}
