
#include "esp_partition.h"
#include "esp_err.h"
#include "nvs_flash.h"
#include <stdio.h>
#include <string.h>

#include <Constants.h>
#include <EspConfig.h>
#include <Logger.h>

void EspConfigClass::init()
{
	char loggerMessage[LENGTH_LOGGER_MESSAGE];
	esp_err_t err = nvs_flash_init();
	if (err != ESP_OK)
	{
		sprintf(loggerMessage, "nvs_flash_init() ERROR: %d", err);
		Logger.error("EspConfig, init()", loggerMessage);
		return;
	}
	err = nvs_open("storage", NVS_READWRITE, &_nvsHandle);
	if (err != ESP_OK)
	{
		sprintf(loggerMessage, "nvs_open() ERROR: %d", err);
		Logger.error("EspConfig, init()", loggerMessage);
		return;
	}
	Logger.info("EspConfig, init()", "OK!");
}

void EspConfigClass::getNvsStringValue(const char *key, char* value)
{
	size_t stringSize;
	esp_err_t err = nvs_get_str(_nvsHandle, key, NULL, &stringSize);
	if (err != ESP_OK || stringSize == 0)
	{
		value[0] = 0;
	}
	else
	{
		err = nvs_get_str(_nvsHandle, key, value, &stringSize);
	}
}

int EspConfigClass::getNvsIntValue(const char *key)
{
	int value;
	esp_err_t err = nvs_get_i32(_nvsHandle, key, &value);
	if (err != ESP_OK)
	{
		value = 0;
	}
	return value;
}

void EspConfigClass::setNvsStringValue(const char *key, const char *value)
{
	char loggerMessage[LENGTH_LOGGER_MESSAGE];
	esp_err_t err = nvs_set_str(_nvsHandle, key, value);
	if (err != ESP_OK)
	{
		sprintf(loggerMessage, "nvs_set_str() ERROR: %d", err);
		Logger.error("EspConfig, setNvsStringValue()", loggerMessage);
		return;
	}
	err = nvs_commit(_nvsHandle);
	if (err != ESP_OK)
	{
		sprintf(loggerMessage, "nvs_commit() ERROR: %d", err);
		Logger.error("EspConfig, setNvsStringValue()", loggerMessage);
		return;
	}
	sprintf(loggerMessage, "Key: %s, Value: %s", key, value);
	Logger.info("EspConfig, setNvsStringValue(), string stored:", loggerMessage);
}

void EspConfigClass::setNvsIntValue(const char *key, int value)
{
	char loggerMessage[LENGTH_LOGGER_MESSAGE];
	esp_err_t err = nvs_set_i32(_nvsHandle, key, value);
	if (err != ESP_OK)
	{
		sprintf(loggerMessage, "nvs_set_i32() ERROR: %d", err);
		Logger.error("EspConfig, setNvsIntValue()", loggerMessage);
		return;
	}
	err = nvs_commit(_nvsHandle);
	if (err != ESP_OK)
	{
		sprintf(loggerMessage, "nvs_commit() ERROR: %d", err);
		Logger.error("EspConfig, setNvsIntValue()", loggerMessage);
		return;
	}
	sprintf(loggerMessage, "Key: %s, Value: %d", key, value);
	Logger.info("EspConfig, setNvsIntValue(), int stored:", loggerMessage);
}

/**
 * Key wird aus der Konfiguration entfernt
 */
void EspConfigClass::deleteKey(const char *key)
{
	char loggerMessage[LENGTH_LOGGER_MESSAGE];
	esp_err_t err = nvs_erase_key(_nvsHandle, key);
	if (err != ESP_OK)
	{
		sprintf(loggerMessage, "deleteKey() ERROR: %d", err);
		Logger.error("EspConfig, nvs_erase_key()", loggerMessage);
		return;
	}
	err = nvs_commit(_nvsHandle);
	if (err != ESP_OK)
	{
		sprintf(loggerMessage, "nvs_commit() ERROR: %d", err);
		Logger.error("EspConfig, deleteKey()", loggerMessage);
		return;
	}
	sprintf(loggerMessage, "Key: %s", key);
	Logger.info("EspConfig, deleteKey(), Key deleted", loggerMessage);
}

void EspConfigClass::clearConfig()
{
	char loggerMessage[LENGTH_LOGGER_MESSAGE];
	const esp_partition_t *nvs_partition =
		esp_partition_find_first(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_DATA_NVS, NULL);
	if (!nvs_partition)
	{
		sprintf(loggerMessage, "esp_partition_find_first() ERROR: No NVS partition found");
		Logger.error("EspConfig, clearConfig()", loggerMessage);
		return;
	}
	esp_err_t err = (esp_partition_erase_range(nvs_partition, 0, nvs_partition->size));
	if (err != ESP_OK)
	{
		sprintf(loggerMessage, "esp_partition_erase_range() ERROR: %d", err);
		Logger.error("EspConfig, clearConfig()", loggerMessage);
		return;
	}
	Logger.info("EspConfig, clearConfig()", "OK!");
}

void EspConfigClass::getConfig(char *buffer, int size)
{
	snprintf(buffer, size - 1, "thingname=%s,ssid=%s,mqttbroker=%s,mqttport=%d", getThingName(), getSsid(), getMqttBroker(), getMqttBrokerPort());
}

char *EspConfigClass::getSsid() { getNvsStringValue("ssid", _ssid); return _ssid; }
char *EspConfigClass::getPassword() { getNvsStringValue("password", _password); return _password; }
char *EspConfigClass::getThingName() { getNvsStringValue("thingname", _thingname); return _thingname; }
char *EspConfigClass::getMqttBroker() { getNvsStringValue("mqttbroker", _mqttbroker); return _mqttbroker; }
int EspConfigClass::getMqttBrokerPort()
{
	getNvsStringValue("mqttport", _mqttport);
	if (strlen(_mqttport) == 0)
	{
		return 0;
	}
	return atoi(_mqttport);
}

EspConfigClass EspConfig;
