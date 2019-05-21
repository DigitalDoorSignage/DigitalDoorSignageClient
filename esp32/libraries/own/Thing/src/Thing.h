#pragma once

#include <list>
#include <IotSensor.h>
#include <IotActor.h>


/*
	Der Thing (Singleton) verwaltet seine Sensoren und Actoren.
	In der Hauptschleife werden die Sensor und Aktorwerte der Devices 
	zyklisch (< 1ms) aktualisiert.
*/
class ThingClass
{
public:

	/*
		Thing initialisieren (Sensorliste und Actorliste anlegen)
		Callback für Aktualisierung anlegen
	*/
	void init();

	/*
		Die Sensoren und Aktoren der Devices werden aktualisiert.
		Dabei werden gesetzte und aktuelle Werte synchronisiert und die
		aktuellen Werte neu gelesen.
	*/
	void refreshSensorsAndActors();
	void addSensor(IotSensor* sensor);
	void addActor(IotActor* actor);
	IotActor* getActorByName(char* name);
	IotSensor* getSensorByName(char* name);
	void getAllSensorName(char* names);
	void getAllActorName(char* names);
private:

	std::list<IotSensor*> _sensors;
	std::list<IotActor*> _actors;

	/*
		Callbackroutine mit der sich der Thing beim CommandInterpreter für Befehle
		zum Setzen von Aktoren registriert
	*/
	void registerThingConfigCommandCallback();


};

extern ThingClass Thing;  // Singleton
