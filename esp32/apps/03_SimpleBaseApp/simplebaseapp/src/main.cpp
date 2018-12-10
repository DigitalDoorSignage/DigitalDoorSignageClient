#include <Arduino.h>
#include <variants/mhetesp32minikit/pins_arduino.h>
#include <ThingConfig.h>
#include <Thing.h>
#include <HttpServer.h>
#include <MqttClient.h>
#include <GxEPD.h>
#include <GxGDEW042T2/GxGDEW042T2.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16); // arbitrary selection of 17, 16
GxEPD_Class display(io, /*RST=*/ 16, /*BUSY=*/ 4); // arbitrary selection of (16), 4
MqttSubscription sub = MqttSubscription();
char topic[5] = "test";

static void callback(const char* topic, const char* payload){
	Serial.printf("%s: %s\n", topic, payload);
	display.fillScreen(GxEPD_WHITE);
	display.update();
	display.setTextColor(GxEPD_BLACK);
	display.setFont(&FreeMonoBold9pt7b);
	display.setCursor(5, 5);
	display.println(payload);
	display.update();
}

void setup() {
	Serial.begin(115200);                 //Initialisierung der seriellen Schnittstelle
	Serial.println();
	Serial.println();
	Serial.println(F("*BA BaseApp"));
	Serial.println(F("*BA ======="));
	ThingConfig.readConfig();
	HttpServer.init();
	MqttClient.init("/");
	sub.topic = topic;
	sub.subscriberCallback = callback;
	MqttClient.addSubscription(&sub);
	MqttClient.subscribeToBroker();
}

void loop() {
	HttpServer.handleClient();
	MqttClient.doLoop();
	delay(1);
}