#include "IotSensor.h"
#include <EspTime.h>
#include <EspMqttClient.h>
#include <EspConfig.h>
#include <string.h>
#include <Logger.h>

IotSensor::IotSensor(const char *thingName, const char *name, const char *unit, float threshold, int maxIntervall)
{
	strcpy(_thingName, thingName);
	strcpy(_name, name);
	strcpy(_unit, unit);
	_threshold = threshold;
	_maxIntervall=maxIntervall;
	_measurement = 0;
	_lastMeasurement = 0;
	_time = EspTime.getTime();
	char loggerMessage[LENGTH_LOGGER_MESSAGE];
	sprintf(loggerMessage, "Sensor initialized: %s", name);
	Logger.debug("Sensor Constructor", loggerMessage);
}

/**
 * Der konkrete Sensor meldet einen Messwert. 
 * Es wird überprüft, ob der Messwert gemeldet werden muss (Zeitablauf, Änderung)
 * und bei Bedarf per MQTT gemeldet.
 */
void IotSensor::setMeasurement(float value)
{
	_lastMeasurement = value;
	float delta = value - _measurement;
	if(delta < 0.0) delta = delta * -1.0;
	long time = EspTime.getTime();
	if (delta >= _threshold || time > _time + _maxIntervall)
	{
		_measurement = value;
		_time = time;
		char loggerMessage[LENGTH_LOGGER_MESSAGE];
		sprintf(loggerMessage, "Neuer Messwert fuer %s: %.1f %s, Time: %ld", _name, _measurement, _unit, _time);
		Logger.info("Sensor set Measurement", loggerMessage);
		char fullTopic[LENGTH_TOPIC];
		//!sprintf(fullTopic, "%s/%s", Thing.getName(), _name);
		//Serial.println(_thingName);
		sprintf(fullTopic, "%s/state", _name);
		char payload[LENGTH_TOPIC];
		getMqttPayload(payload, value);
		sprintf(loggerMessage, "Topic: %s, Payload: %s", fullTopic, payload);
		Logger.debug("Sensor set Measurement", loggerMessage);
		EspMqttClient.publish(fullTopic, payload);
		sprintf(loggerMessage, "%s: %.1f%s,Time: %ld",_name, _measurement, _unit, _time);
		Logger.debug("Sensor set Measurement", loggerMessage);
	}
}

float IotSensor::getLastMeasurement()
{
	return _lastMeasurement;
}

void IotSensor::measure()
{
}

char *IotSensor::getName()
{
	return _name;
}

void IotSensor::getMqttPayload(char *payload, float measurement)
{
	sprintf(payload, "{\"timestamp\":%ld,\"value\":%.2f}", EspTime.getTime(), measurement);
}

//void IotSensor::measure(){}
