#include <esp_task_wdt.h>
#include <rom/rtc.h>

#include "SystemService.h"
#include <EspConfig.h>
#include <Logger.h>
#include <EspMqttClient.h>
#include <Constants.h>
#include <EspTime.h>

// #include <UdpLoggerTarget.h>

long SystemServiceClass::getMicros()
{
    return esp_timer_get_time();
}

long SystemServiceClass::getMillis()
{
    return esp_timer_get_time() / 1000;
}

/**
 * Initialisiert den Systemzustand (ertser Reset, Restarts, ...) und alarmiert Abschaltung, 
 * falls in letzter Zeit zu viele Restarts aufgetreten sind.
 */
void SystemServiceClass::init()
{
    int resetReasonCore0 = rtc_get_reset_reason(0);
    int resetReasonCore1 = rtc_get_reset_reason(1);
    char loggerMessage[LENGTH_LOGGER_MESSAGE];
    sprintf(loggerMessage, "Reset reasons, core 0: %s, core 1: %s", getResetReasonString(resetReasonCore0), getResetReasonString(resetReasonCore1));
    Logger.info("System Service;init()", loggerMessage);
    _errors = 0; // Errors rücksetzen
    EspConfig.setNvsStringValue("restartreason", getResetReasonString(resetReasonCore0));
    _startHeapSize = esp_get_free_heap_size();
    if (resetReasonCore0 == 1) // PowerOn-Reset
    {
        Logger.info("SystemService;init()", "PowerON, reset restarts ==> 0");
        EspConfig.setNvsStringValue("lasterror", "PowerON");
        _restarts = 0;
        EspConfig.setNvsIntValue("restarts", _restarts);
    }
    else // Restart
    {
        EspConfig.getNvsStringValue("lasterror", loggerMessage);
        Logger.info("System Service;init();lasterror", loggerMessage);
        _restarts = EspConfig.getNvsIntValue("restarts");
        _restarts++;
        EspConfig.setNvsIntValue("restarts", _restarts);
        _lastRestartTime = EspTime.getTime();
        sprintf(loggerMessage, "Restart counter is on: %i and last Restart time is: %ld", _restarts, _lastRestartTime);
        Logger.info("System Service;init()", loggerMessage);
        if (_restarts >= 5) // System hängt ==> Alarmsignal über Mqtt, Logger und LED-Stripe
        {
            char topic[LENGTH_TOPIC];
            strcpy(topic, EspConfig.getThingName());
            strcat(topic, "/error");
            EspMqttClient.publish(topic, "Too many restarts");
            Logger.error("System Service;init()", "Too many restarts");
            while (1)
            {
            }
        }
    }
    enableWatchdog(30); // 30 Sekunden Watchdogzeit
}

/**
 * Schwerwiegender Fehler ist aufgetreten oder die Anzahl normaler Fehler häuft sich. System wird neu gestartet
 **/
void SystemServiceClass::pushFatalError(const char *errorMessage)
{
    EspConfig.setNvsStringValue("lasterror", errorMessage);
    char loggerMessage[LENGTH_LOGGER_MESSAGE];
    sprintf(loggerMessage, "FATAL ERROR: %s, time is: %ld", errorMessage, _lastRestartTime);
    Logger.error("System Service;pushFatalError()", loggerMessage);
    esp_restart();
}

/**
 * Ein "normaler" Fehler ist aufgetreten. Der Fehlerzähler wird erhöht und bei Erreichen
 * eines kritischen Zählerstandes wird ein FatalError ausgelöst
 */
void SystemServiceClass::pushError(const char *errorMessage)
{
    _errors++;
    if (_errors >= 5)
    {
        SystemService.pushFatalError("Too many errors");
        return;
    }
    char loggerMessage[LENGTH_LOGGER_MESSAGE];
    sprintf(loggerMessage, "Error: %s, counter is on: %i", errorMessage, _errors);
    Logger.error("System Service;pushError()", loggerMessage);
    _lastErrorTime = EspTime.getTime();
}

void SystemServiceClass::checkSystem()
{
    feedWatchdog();

    char loggerMessage[LENGTH_LOGGER_MESSAGE];
    int heapSize = esp_get_free_heap_size();
    ;
    int nextNotificationHeapSize = _startHeapSize * _nextHeapSizeQuoteForNotification;
    sprintf(loggerMessage, "Loosing heapsize: %i", heapSize);
    if (getMillis() > _nextMessageTime)
    {
        _nextMessageTime = getMillis() + 5000;
        sprintf(loggerMessage, "Heapsize: %i;Startheapsize: %i;limit: %i;quote: %f", heapSize, _startHeapSize, nextNotificationHeapSize, _nextHeapSizeQuoteForNotification);
        Logger.info("SystemService;checkSystem()", loggerMessage);
    }

    if (_nextHeapSizeQuoteForNotification <= 0.3)
    {
        pushFatalError(loggerMessage);
        return;
    }
    if (heapSize < nextNotificationHeapSize)
    {
        pushError(loggerMessage);
        _nextHeapSizeQuoteForNotification -= 0.1;
    }
    if (_restarts > 0 && EspTime.getTime() > _lastRestartTime + 10 * 60 * 1000) // Selbstheilung nach 10 Minuten
    {
        _restarts = 0;
        EspConfig.setNvsIntValue("restarts", 0);
        Logger.info("System Service;checkSystem()", "restarts ==> 0");
    }
    if (_errors > 0 && EspTime.getTime() > _lastErrorTime + 10 * 60 * 1000) // Selbstheilung nach 10 Minuten
    {
        _errors = 0;
        Logger.info("System Service;checkSystem()", "errors ==> 0");
    }
}

void SystemServiceClass::enableWatchdog(uint8_t seconds)
{
    esp_task_wdt_init(seconds, true);
    esp_task_wdt_add(xTaskGetCurrentTaskHandle());
}

void SystemServiceClass::disableWatchdog()
{
    esp_task_wdt_delete(nullptr);
}

void SystemServiceClass::feedWatchdog()
{
    esp_err_t result = esp_task_wdt_reset();
    if (result != ESP_OK)
    {
        char loggerMessage[LENGTH_LOGGER_MESSAGE];
        sprintf(loggerMessage, "Reset Watchdog Error: %d", result);
        Logger.error("System Service;feedWatchdog()", loggerMessage);
    }
}

const char *SystemServiceClass::getResetReasonString(int reasonCode)
{
    switch (reasonCode)
    {
    case 1:
        return "POWERON_RESET";
        break; /**<1, Vbat power on reset*/
    case 3:
        return "SW_RESET";
        break; /**<3, Software reset digital core*/
    case 4:
        return "OWDT_RESET";
        break; /**<4, Legacy watch dog reset digital core*/
    case 5:
        return "DEEPSLEEP_RESET";
        break; /**<5, Deep Sleep reset digital core*/
    case 6:
        return "SDIO_RESET";
        break; /**<6, Reset by SLC module, reset digital core*/
    case 7:
        return "TG0WDT_SYS_RESET";
        break; /**<7, Timer Group0 Watch dog reset digital core*/
    case 8:
        return "TG1WDT_SYS_RESET";
        break; /**<8, Timer Group1 Watch dog reset digital core*/
    case 9:
        return "RTCWDT_SYS_RESET";
        break; /**<9, RTC Watch dog Reset digital core*/
    case 10:
        return "INTRUSION_RESET";
        break; /**<10, Instrusion tested to reset CPU*/
    case 11:
        return "TGWDT_CPU_RESET";
        break; /**<11, Time Group reset CPU*/
    case 12:
        return "SW_CPU_RESET";
        break; /**<12, Software reset CPU*/
    case 13:
        return "RTCWDT_CPU_RESET";
        break; /**<13, RTC Watch dog Reset CPU*/
    case 14:
        return "EXT_CPU_RESET";
        break; /**<14, for APP CPU, reseted by PRO CPU*/
    case 15:
        return "RTCWDT_BROWN_OUT_RESET";
        break; /**<15, Reset when the vdd voltage is not stable*/
    case 16:
        return "RTCWDT_RTC_RESET";
        break; /**<16, RTC Watch dog reset digital core and rtc module*/
    default:
        return "NO_MEAN";
    }
}

SystemServiceClass SystemService;