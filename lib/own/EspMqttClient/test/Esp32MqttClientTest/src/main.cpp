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

extern "C"
{
  void app_main(void);
}

MqttSubscription exampleSubscription;
char subTopic[] = "echoTopic";

/**
 * Beispiel Callback für eine Mqtt-Subscription
 */
static void subscribeCallback(const char *topic, const char *payload)
{
  char loggerMessage[LENGTH_LOGGER_MESSAGE];
  sprintf(loggerMessage, "Topic: %s, Payload: %s", topic, payload);
  Logger.info("MqttTest, subscribeCallback()", loggerMessage);
}

const char *SERIAL_LOGGER_TAG = "SLT";

void app_main()
{
  printf("============\n");
  printf("EspMqtt Test\n");
  printf("============\n");
  EspConfig.init();
  Logger.init("EspMqttTest");
  SerialLoggerTarget *serialLoggerTarget = new SerialLoggerTarget(SERIAL_LOGGER_TAG, LOG_LEVEL_VERBOSE);
  Logger.addLoggerTarget(serialLoggerTarget);
  
  char loggerMessage[LENGTH_LOGGER_MESSAGE];
  EspConfig.getConfig(loggerMessage, LENGTH_LOGGER_MESSAGE - 1);
  Logger.info("EspMqttTest, Config", loggerMessage);

  EspStation.init();
  Logger.info("EspMqttTest, app_main()", "Waiting for connection!");
  while (!EspStation.isStationOnline())
  {
    vTaskDelay(1 / portTICK_PERIOD_MS);
  }
  HttpServer.init();
  Logger.info("EspMqttTest, app_main()", "HttpServer started");

  EspTime.init();
  EspMqttClient.init(EspConfig.getThingName());
  exampleSubscription.topic = subTopic;
  exampleSubscription.subscriberCallback = subscribeCallback;
  EspMqttClient.addSubscription(&exampleSubscription);
  int nextPublish = 1000;  // alle 5 Sekunden
  while (true)
  {
    if (nextPublish <= 0)
    {
      EspMqttClient.publish("echoTopic/command", "loop");
      nextPublish = 1000;
    }
    nextPublish--;
    vTaskDelay(1);
  }
}
