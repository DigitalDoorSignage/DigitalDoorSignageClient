#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "lwip/apps/sntp.h"
#include "esp_err.h"
#include <stdlib.h>

#include <EspTime.h>
#include <Constants.h>
#include <Logger.h>
#include <EspConfig.h>

static char NTP_SERVER_ADDRESS[] = "0.at.pool.ntp.org"; // "pool.ntp.org"

void EspTimeClass::getTimeString(char *buffer)
{
	struct tm timeinfo;
	time_t now;
	time(&now);
	localtime_r(&now, &timeinfo);
	strftime(buffer, LENGTH_SHORT_TEXT, "%H:%M:%S", &timeinfo);
}

void EspTimeClass::getDateString(char *buffer)
{
	struct tm timeinfo;
	time_t now;
	time(&now);
	localtime_r(&now, &timeinfo);
	strftime(buffer, LENGTH_SHORT_TEXT, "%d.%m.%Y", &timeinfo);
}

long EspTimeClass::getTime()
{
	time_t actTime;
	time(&actTime);
	return actTime;
}

void EspTimeClass::init()
{
	char loggerMessage[LENGTH_LOGGER_MESSAGE];
	sntp_setoperatingmode(SNTP_OPMODE_POLL);
	char ntpServerAddress[LENGTH_MIDDLE_TEXT];
	EspConfig.getNvsStringValue("ntpserver", ntpServerAddress);
	if (strlen(ntpServerAddress) == 0)
	{
		strcpy(ntpServerAddress, NTP_SERVER_ADDRESS);
	}
	sprintf(loggerMessage,"ntpserver: %s", ntpServerAddress);;
	Logger.info("EspTime;init()",loggerMessage);
	sntp_setservername(0, ntpServerAddress); //  "0.at.pool.ntp.org"	sntp_init();
	sntp_init();
	// wait for the service to set the time
	time_t now;
	struct tm timeinfo;
	time(&now);
	localtime_r(&now, &timeinfo);
	int round = 0;
	while (round < 6 && timeinfo.tm_year < (2016 - 1900))
	{
		Logger.info("EspTime, init()", "Time not set, waiting...");
		vTaskDelay(5000 / portTICK_PERIOD_MS);
		time(&now);
		localtime_r(&now, &timeinfo);
		round++;
	}
	// change the timezone to MEZ
	setenv("TZ", "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00", 1);
	tzset();
}

EspTimeClass EspTime;
