// EspMqttClient.h
#pragma once

// #include <WiFi.h>
#include "mqtt_client.h"
#include <list>
#include <Constants.h>


#define TOPIC_LENGTH 200
#define PAYLOAD_LENGTH 200

/*
	Definition des Typs des Functionpointers als Callback
	//! Sollte auch Methoden einer Klasse unterstützen (Readme.md updaten)
*/
typedef void(*SubscriberCallback)(const char *topic, const char *payload);

/*
	Zentrale Datenstruktur bei der Kommandobearbeitung
*/
struct MqttSubscription
{
	char *topic;
	SubscriberCallback subscriberCallback;
};

class EspMqttClientClass
{
  public:
	void init(const char *mainTopic);
	void addSubscription(MqttSubscription* subscriptionPtr);
	bool publish(const char *topic,const char *payLoad);
	void notifySubscribers(char* topic, char *payload);
	void addSubscriptionsToBroker();
	void subscribeToBroker();

	const char* getMainTopic();
	const char* getLastWillTopic();
	const char* getMqttThingName();
	const char *getMqttServer();
	int getMqttPort();

	
  private:
	std::list<MqttSubscription *> _mqttSubscriptions;
	char _mainTopic[LENGTH_TOPIC];
	char _lastWillTopic[LENGTH_TOPIC];
	char _mqttUserName[LENGTH_SHORT_TEXT];
	char _mqttPassword[LENGTH_SHORT_TEXT];
	char* _mqttBroker;
	int _mqttPort; 
	char* _thingName;

	// esp_mqtt_client_handle_t _client;
};
extern EspMqttClientClass EspMqttClient;
