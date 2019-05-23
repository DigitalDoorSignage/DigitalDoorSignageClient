#pragma once

#include "nvs.h"
#include <Constants.h>

class EspConfigClass
{

public:
	void init();
	void clearConfig();
	void getConfig(char* buffer, int size);
	void getNvsStringValue(const char* key, char* value);
	int getNvsIntValue(const char *key);
	void setNvsStringValue(const char* key, const char* value);
	void setNvsIntValue(const char *key, int value);
	void deleteKey(const char* key);
	char* getSsid();
	char* getPassword();
	char* getThingName();
	char* getMqttBroker();
	int getMqttBrokerPort();


private:
	nvs_handle _nvsHandle;
	char _ssid[LENGTH_SHORT_TEXT];
	char _password[LENGTH_SHORT_TEXT];
	char _mqttbroker[LENGTH_MIDDLE_TEXT];
	char _mqttport[LENGTH_SHORT_TEXT];
	char _thingname[LENGTH_SHORT_TEXT];
	
};

extern EspConfigClass EspConfig;


