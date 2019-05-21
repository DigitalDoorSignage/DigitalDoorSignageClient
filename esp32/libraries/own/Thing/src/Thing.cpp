#include "Thing.h"
#include <EspMqttClient.h>
#include <EspConfig.h>
//#include <HttpServer.h>
#include <Logger.h>

// /**
//  * Aktorwert kann per Get-Request gesetzt werden. 
//  * Implementiert von Ferdinand Hell (Htl Wels)
//  */
// void handleSetActorRequest()
// {
// 	printf("*TH: handleSetActorRequest()");
// 	String actorName = HttpServer.arg("actor");
// 	String actorValue = HttpServer.arg("value");
// 	if (actorName != NULL && actorValue != NULL)
// 	{
// 		IotActor *actor = Thing.getActorByName((char *)(actorName.c_str()));
// 		char response[50];
// 		if (actor == NULL)
// 		{
// 			sprintf(response, "Actor %s not found!", actorName.c_str());
// 			HttpServer.send(200, "text/html", response); //Returns the HTTP response
// 		}
// 		else
// 		{
// 			actor->setState(actorValue.c_str());
// 			sprintf(response, "Changed Actor's %s value %.2f", actorName.c_str(), atof(actorValue.c_str()));
// 			char loggerMessage[150];
// 			sprintf(loggerMessage, "Response: %s", response);
// 			Logger.info("Thing Set Actor", loggerMessage);
// 			HttpServer.send(200, "text/html", response); //Returns the HTTP response
// 		}
// 	}
// 	else if (actorName == NULL)
// 	{
// 		HttpServer.send(200, "text/html", "Parametername actor fehlt"); //Returns the HTTP response
// 	}
// 	else
// 	{
// 		HttpServer.send(200, "text/html", "Parametername value fehlt"); //Returns the HTTP response
// 	}
// }

// /**
//  * Sensorwert per Http-Get-Request abfragen
//  */
// void handleGetSensorRequest()
// {
// 	Serial.println(F("*TH: handleGetSensorRequest()"));
// 	String sensorName = HttpServer.arg("sensor");
// 	if (sensorName != NULL)
// 	{
// 		IotSensor *sensor = Thing.getSensorByName((char *)(sensorName.c_str()));
// 		char response[50];
// 		if (sensor == NULL)
// 		{
// 			sprintf(response, "Sensor %s not found!", sensorName.c_str());
// 			HttpServer.send(200, "text/html", response); //Returns the HTTP response
// 		}
// 		else
// 		{
// 			float measurement = sensor->getLastMeasurement();
// 			sprintf(response, "Sensor's %s value %.2f", sensorName.c_str(), measurement);
// 			char loggerMessage[100];
// 			sprintf(loggerMessage, "Response: %s", response);
// 			Logger.info("Thing Get Sensor", loggerMessage);
// 			HttpServer.send(200, "text/html", response); //Returns the HTTP response
// 		}
// 	}
// 	else 
// 	{
// 		HttpServer.send(200, "text/html", "Parametername sensor fehlt"); //Returns the HTTP response
// 	}
// }


/*
 * Thing wird initialisiert und Routen zum Lesen von Sensorwerten, bzw. Setzen
 * von Aktorwerten werden registriert.
 */
void ThingClass::init()
{
	Logger.info("Thing, init(), name: ", EspConfig.getThingName());
	char loggerMessage[LENGTH_LOGGER_MESSAGE];
	sprintf(loggerMessage, "Thing init with name: %s", EspConfig.getThingName());
	Logger.info("ThingClass Init", loggerMessage);
	// HttpServer.on("/setactor", handleSetActorRequest);
	// HttpServer.on("/getsensor", handleGetSensorRequest);

}

void ThingClass::addSensor(IotSensor *sensorPtr)
{
	_sensors.push_back(sensorPtr);
}

void ThingClass::addActor(IotActor *actorPtr)
{
	_actors.push_back(actorPtr);
}

void ThingClass::refreshSensorsAndActors()
{
	for (std::list<IotSensor *>::iterator it = _sensors.begin(); it != _sensors.end(); ++it)
	{
		// Serial.print(F("*NO: refresh, Sensor: "));
		// Serial.print(it->first);
		// Serial.print(F(", last Value: "));
		// Serial.println(it->second->getLastMeasurement());
		IotSensor *sensorPtr = *it;
		sensorPtr->measure();
	}
	for (std::list<IotActor *>::iterator it = _actors.begin(); it != _actors.end(); ++it)
	{
		// Serial.print(F("*NO: refresh, Actor: "));
		// Serial.print(it->first);
		// Serial.print(F(", last Value: "));
		// Serial.println(it->second->getLastMeasurement());
		(*it)->sync();
	}
}

IotActor *ThingClass::getActorByName(char *name)
{
	for (std::list<IotActor *>::iterator it = _actors.begin(); it != _actors.end(); ++it)
	{
		// Serial.print(F("*NO: refresh, Sensor: "));
		// Serial.print(it->first);
		// Serial.print(F(", last Value: "));
		// Serial.println(it->second->getLastMeasurement());
		IotActor *actorPtr = *it;
		if (strcmp(actorPtr->getName(), name) == 0)
		{
			return actorPtr;
		}
	}
	return nullptr;
}

IotSensor *ThingClass::getSensorByName(char *name)
{
	for (std::list<IotSensor *>::iterator it = _sensors.begin(); it != _sensors.end(); ++it)
	{
		IotSensor *sensorPtr = *it;
		if (strcmp(sensorPtr->getName(), name) == 0)
		{
			return sensorPtr;
		}
	}
	return nullptr;
}

void ThingClass::getAllSensorName(char* names){
	bool x = false;
	for (std::list<IotSensor *>::iterator it = _sensors.begin(); it != _sensors.end(); ++it)
	{
		x = true;
		IotSensor *sensorPtr = *it;
		strcat(names, sensorPtr->getName());
		strcat(names, ";");
	}
	if(x){
		Logger.info("Thing Get Sensor Name", names);
	} else {
		Logger.info("Thing Get Sensor Name", "No Sensors");
	}

}

void ThingClass::getAllActorName(char* names){
	bool x = false;
	for (std::list<IotActor *>::iterator it = _actors.begin(); it != _actors.end(); ++it)
	{
		x = true;
		IotActor *actorPtr = *it;
		strcat(names, actorPtr->getName());
		strcat(names, ";");
	}
	if(x) {
		Logger.info("Thing Get Actor Name", names);
	} else {
		Logger.info("Thing Get Actor Name", "No Actor");
	}
}

ThingClass Thing;
