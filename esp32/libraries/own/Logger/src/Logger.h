// Logger.h
#pragma once

// #include <WiFiUdp.h>
#include <list>
#include <Constants.h>
#include <LoggerTarget.h>

#define LOG_LEVEL_VERBOSE 0
#define LOG_LEVEL_DEBUG 1
#define LOG_LEVEL_INFO 2
#define LOG_LEVEL_WARNING 3
#define LOG_LEVEL_ERROR 4
#define LOG_LEVEL_NONE 5

class LoggerClass
{
public:
	/*
		Ein Logeintrag mit folgenden Parametern wird zum Server geschickt:
		topic: Topic, für das der LogEntry ausgelöst wurde
		logLevel: Level der Logmessage (Info - Fatalerror)
		time: Unix-Timecode
		message: Logtext
	*/

	void init(const char* name);
	void verbose(const char* tag, const char* message);
	void debug(const char* tag, const char* message);
	void info(const char* tag, const char* message);
	void warning(const char* tag, const char* message);
	void error(const char* tag, const char* message);

	bool addLoggerTarget(LoggerTarget* logger);
	LoggerTarget* getLoggerTarget(const char* name);
	char* getName();
	char* getThingName();

	const char* getLogLevelText(int logLevel);

private:
	void log(int logLevel, const char* tag, const char* message);
	char _name[LENGTH_SHORT_TEXT];
	std::list<LoggerTarget*> _logger;
	const char* _logLevelTexts[5] = {"V", "D", "I",  "W", "E"};
};
extern LoggerClass Logger;
