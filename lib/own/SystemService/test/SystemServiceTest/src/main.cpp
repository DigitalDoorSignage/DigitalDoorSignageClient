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

extern "C"
{
  void app_main(void);
}

class MemoryBlock
{
private:
  int hugeArray[5000];

public:
  MemoryBlock(/* args */);
  ~MemoryBlock();
};

MemoryBlock::MemoryBlock(/* args */)
{
}

MemoryBlock::~MemoryBlock()
{
}

#define HTTP_OK 200

static esp_err_t pushfatalerrorrequestHandler(httpd_req_t *req)
{
  Logger.info("SystemServiceClient;pushfatalerrorrequestHandler()", "Start");
  const char *errorText = "Fatalerror from Request!";
  SystemService.pushFatalError(errorText);
  httpd_resp_send(req, errorText, strlen(errorText));
  return ESP_OK;
}

static const httpd_uri_t pushfatalerrorrequest = {
    .uri = "/pushfatalerror",
    .method = HTTP_GET,
    .handler = pushfatalerrorrequestHandler,
    .user_ctx = nullptr};

static esp_err_t pusherrorrequestHandler(httpd_req_t *req)
{
  Logger.info("SystemServiceClient;pusherrorrequestHandler()", "Start");
  const char *errorText = "Error from Request!";
  SystemService.pushError(errorText);
  httpd_resp_send(req, errorText, strlen(errorText));
  return ESP_OK;
}

static const httpd_uri_t pusherrorrequest = {
    .uri = "/pusherror",
    .method = HTTP_GET,
    .handler = pusherrorrequestHandler,
    .user_ctx = nullptr};

static esp_err_t allocatefromheapHandler(httpd_req_t *req)
{
  Logger.info("SystemServiceClient;allocatefromheapHandler()", "Start");
  const char *errorText = "Memoryblock allocated!";
  new MemoryBlock();
  httpd_resp_send(req, errorText, strlen(errorText));
  return ESP_OK;
}

static const httpd_uri_t allocatefromheaprequest = {
    .uri = "/allocatefromheap",
    .method = HTTP_GET,
    .handler = allocatefromheapHandler,
    .user_ctx = nullptr};

bool isFeedWatchdogEnabled = true;
static esp_err_t stopfeedwatchdogHandler(httpd_req_t *req)
{
  Logger.info("SystemServiceClient;stopfeedwatchdogHandler()", "Start");
  const char *errorText = "Watchdog feed disabled!";
  isFeedWatchdogEnabled = false;
  httpd_resp_send(req, errorText, strlen(errorText));
  return ESP_OK;
}

static const httpd_uri_t stopfeedwatchdogrequest = {
    .uri = "/stopfeedwatchdog",
    .method = HTTP_GET,
    .handler = stopfeedwatchdogHandler,
    .user_ctx = nullptr};

const char *SERIAL_LOGGER_TAG = "SLT";

void app_main()
{
  printf("==================\n");
  printf("SystemService Test\n");
  printf("==================\n");
  EspConfig.init();
  Logger.init("SystemServiceTest");
  SerialLoggerTarget *serialLoggerTarget = new SerialLoggerTarget(SERIAL_LOGGER_TAG, LOG_LEVEL_VERBOSE);
  Logger.addLoggerTarget(serialLoggerTarget);
  SystemService.init();
  char loggerMessage[LENGTH_LOGGER_MESSAGE];
  EspConfig.getConfig(loggerMessage, LENGTH_LOGGER_MESSAGE - 1);
  Logger.info("SystemServiceTest;app_main()", loggerMessage);

  EspStation.init();
  Logger.info("SystemServiceTest;app_main()", "Waiting for connection!");
  while (!EspStation.isStationOnline())
  {
    vTaskDelay(1 / portTICK_PERIOD_MS);
  }
  HttpServer.init();
  Logger.info("SystemServiceTest;app_main()", "HttpServer started");

  EspTime.init();
  //EspMqttClient.init(thingName);
  Logger.info("SystemServiceTest;app_main()", "Add service-routes");
  HttpServer.addRoute(&pushfatalerrorrequest);
  HttpServer.addRoute(&pusherrorrequest);
  HttpServer.addRoute(&allocatefromheaprequest);
  HttpServer.addRoute(&stopfeedwatchdogrequest);

  while (true)
  {
    if (isFeedWatchdogEnabled)
    {
      SystemService.checkSystem();
    }
    vTaskDelay(1);
  }
}
