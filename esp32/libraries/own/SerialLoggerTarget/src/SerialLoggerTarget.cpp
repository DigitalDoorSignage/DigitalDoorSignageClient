#include <stdio.h>
#include <time.h>
#include "SerialLoggerTarget.h"
#include <Logger.h>



SerialLoggerTarget::SerialLoggerTarget(const char* name, int logLevel)
    :LoggerTarget(name, logLevel){
    printf("*LOG: SerialLogger for thing %s initialized!\n", Logger.getName());
}

void SerialLoggerTarget::log(const char* logLevelText, const char* tag, const char* message){
    id++;
    time_t t;
    time(&t);
    printf("%s;%ld;%ld;%s;%s;%s\n", logLevelText, t, id, Logger.getName(),  tag, message);
}
