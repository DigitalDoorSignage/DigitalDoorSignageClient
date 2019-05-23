#pragma once

#include <Constants.h>
#include <EspMqttClient.h>
/*
	Die Klasse Actor dient als abstrakte Basisklasse für beliebige Typen von Aktoren.
	Jeder Actor hat einen aktuellen Zustand, der als Sensor behandelt wird.
	Weiters gibt es einen Wert, auf den der Actor gesetzt werden soll. Nach endlicher Zeit
	stimmen die beiden Werte überein, sofern der Actor korrekt funktioniert.
	Beispiel PowerSwitch:
				Der aktuelle Wert repräsentiert den Zustand des Schalters (1 für ein, 0 für aus)
				Der zu setzende Wert gibt den Zielzustand an. Wird dieser Wert per Commando umgesetzt, 
				wird innerhalb einiger Millisekunden das SSR geschaltet und auch der aktuelle Wert angepasst.
	Beispiel Rollladenschalter:
				Der aktuelle Wert zwischen 0 und 1 repräsentiert die Stellung des Rollladens (0 geschlossen, 0,5
				halb offen, 1 offen). Wird der Zielwert neu gesetzt, dauert es natürlich einige Sekunden, bis
				der aktuelle Wert den Zielwert erreicht.

	Alle speziellen Aktoren (z.B. Powerswitch) leiten von dieser Basisklasse ab initialisieren ihren 
	zugehörigen Sensor (z.B. PowerSwitchSensor) und überschreiben die Methode syncValue(), die dafür sorgt,
	dass der aktuelle Aktorwert mit dem gesetzten übereinstimmt.
*/
class IotActor
{
  public:
	/*
		Der Aktor wird mit seinen Stammdaten initialisiert. Die Parameter
		unit und threashold werden an den Messwert (Sensor) des Aktors 
		weiter gereicht.
	 */
	IotActor(const char *thingName, const char *name);
	char *getName();

	/**
	 * Ein eingehendes Mqtt-Kommando wird ausgewertet und in einen Kommandowert übersetzt 
	 */
	void setStateByMqtt(const char *payload);
	void setState(const char *stateText);
	char *getSettedState();
	char *getCurrentState();
	void sync();

  protected:

	// muss vom konkreten Aktor implementiert werden
	virtual void setActor(const char* newState)=0; // Pure virtual function makes this class Abstract class.

	char _thingName[LENGTH_THING_NAME];
	char _name[LENGTH_THING_NAME];
	long _time;
	char _currentState[LENGTH_STATE];

  private:
	MqttSubscription _actorSubscription;
	char _actorTopic[LENGTH_TOPIC];
	char _settedState[LENGTH_STATE];
	char _lastReportedState[LENGTH_STATE];
	
};
