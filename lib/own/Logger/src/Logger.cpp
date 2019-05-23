
#include <stdio.h>
#include <string.h>
#include <esp_log.h>
#include "Logger.h"

/*
	Ein Logeintrag mit folgenden Parametern wird zum Server geschickt:
	topic: Topic, für das der LogEntry ausgelöst wurde
	type: Typ der Logmessage (Info - Fatalerror)
	time: Unix-Timecode
	message: Logtext
*/

// int espLogDelegate(const char *format, va_list arg){
// 	char loggerMessage[300];
// 	sprintf(loggerMessage, format, arg);
// 	printf("---- %s\n", loggerMessage);
// 	// printf("++++++++++++++++\n");
// 	return 1;
// }

void LoggerClass::init(const char *name)
{
	strcpy(_name, name);
	printf("TH* Logger init with name: %s ", _name);
	// esp_log_set_vprintf(&espLogDelegate);
}
void LoggerClass::verbose(const char *tag, const char *message)
{
	log(LOG_LEVEL_VERBOSE, tag, message);
}

void LoggerClass::debug(const char *tag, const char *message)
{
	log(LOG_LEVEL_DEBUG, tag, message);
}

void LoggerClass::info(const char *tag, const char *message)
{
	log(LOG_LEVEL_INFO, tag, message);
}

void LoggerClass::warning(const char *tag, const char *message)
{
	log(LOG_LEVEL_WARNING, tag, message);
}

void LoggerClass::error(const char *tag, const char *message)
{
	log(LOG_LEVEL_ERROR, tag, message);
}

void LoggerClass::log(int logLevel, const char *tag, const char *message)
{
	for (std::list<LoggerTarget *>::iterator it = _logger.begin(); it != _logger.end(); ++it)
	{
		// Serial.print(F("*NO: refresh, Sensor: "));
		// Serial.print(it->first);
		// Serial.print(F(", last Value: "));
		// Serial.println(it->second->getLastMeasurement());
		LoggerTarget *loggerTarget = *it;
		if (logLevel >= loggerTarget->getLogLevel())
		{
			loggerTarget->log(_logLevelTexts[logLevel], tag, message);
		}
	}
}

bool LoggerClass::addLoggerTarget(LoggerTarget *loggerTarget)
{
	char loggerMessage[LENGTH_LOGGER_MESSAGE];
	if (getLoggerTarget(loggerTarget->getName()) != nullptr)
	{
		sprintf(loggerMessage, "Logger %s already exists!", loggerTarget->getName());
		Logger.error("Logger;addLoggerTarget()", loggerMessage);
		return false;
	}
	_logger.push_back(loggerTarget);
	sprintf(loggerMessage, "LoggerTarget %s registered", loggerTarget->getName());
	Logger.error("Logger;addLoggerTarget()", loggerMessage);
	return true;
}

const char *LoggerClass::getLogLevelText(int logLevel)
{
	if (logLevel > 4)
	{
		return "?";
	}

	return _logLevelTexts[logLevel];
}

LoggerTarget *LoggerClass::getLoggerTarget(const char *name)
{
	for (std::list<LoggerTarget *>::iterator it = _logger.begin(); it != _logger.end(); ++it)
	{
		// Serial.print(F("*NO: refresh, Sensor: "));
		// Serial.print(it->first);
		// Serial.print(F(", last Value: "));
		// Serial.println(it->second->getLastMeasurement());
		LoggerTarget *logger = *it;
		if (strcmp(logger->getName(), name) == 0)
		{
			return logger;
		}
	}
	return nullptr;
}

char *LoggerClass::getName()
{
	return _name;
}

LoggerClass Logger;
