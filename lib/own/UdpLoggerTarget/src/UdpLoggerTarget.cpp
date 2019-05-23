#include "UdpLoggerTarget.h"
#include <Constants.h>
#include <EspConfig.h>
#include <EspTime.h>
#include <Logger.h>
#include <string.h>
#include <EspUdp.h>


UdpLoggerTarget::UdpLoggerTarget(const char *ipAddress, int logLevel )
	: LoggerTarget(ipAddress, logLevel)
{
	strcpy(_ipAddress, ipAddress);
	char loggerMessage[LENGTH_LOGGER_MESSAGE];
	sprintf(loggerMessage, "Udp-TargetAddress: %s, Port: %d created", _ipAddress, _port);
	Logger.info("Udplogger Constructor", loggerMessage);
}

void UdpLoggerTarget::log(const char *logLevelText, const char *tag, const char *message)
{
	_id++;
	char logMessage[LENGTH_LOGGER_MESSAGE];
	// char timeText[LENGTH_MIDDLE_TEXT];
	long time = EspTime.getTime();
	// Serial.printf("*ULT Thingname: %s\n", Logger.getThingName());
	sprintf(logMessage, "%ld;%ld;%s;%s;%s;%s", time, _id, EspConfig.getThingName(), logLevelText, tag, message);
	
	if (!EspUdp.sendUdpMessage(_ipAddress, _port, logMessage))
	{
		printf("!!!! ULT, Error in endPacket()!");
		return;
	}
	else
	{
		//printf("!!!! ULT Sent Udp-Logmessage to %s:%d, Text: %s\n", _ipAddress, _port, logMessage); //No Logger else infinity loop
	}
}

int UdpLoggerTarget::getPort()
{
	return _port;
}