#pragma once

#include <LoggerTarget.h>
#include <Constants.h>

class UdpLoggerTarget : public LoggerTarget
{
public:
    UdpLoggerTarget(const char *ipAddress, int logLevel);
    int getPort();

    virtual void log(const char *logLevelText, const char *tag, const char *message);

private:
    char _ipAddress[LENGTH_SHORT_TEXT];
    int _port = 41234;
    long _id = 0;
};
