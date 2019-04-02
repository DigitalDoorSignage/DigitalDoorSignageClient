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

GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/17, /*RST=*/16); // arbitrary selection of 17, 16
GxEPD_Class display(io, /*RST=*/16, /*BUSY=*/4);		// arbitrary selection of (16), 4
MqttSubscription sub = MqttSubscription();
std::string room;
std::string teacher;
std::string subject;
std::string klass;
char topic[30] = "room/";

int calculateWidthOfText(std::string text)
{
	return text.length() * 21 - 3;
}

int calculateCenteredXOfText(std::string text, int width)
{
	return (width - calculateWidthOfText(text)) / 2;
}

static void writeLessonToDisplay(std::string newClass, std::string newTeacher, std::string newSubject)
{
	int x, y = 0;
	boolean classChanged = klass.compare(newClass) != 0;
	boolean teacherChanged = teacher.compare(newTeacher) != 0;
	boolean subjectChanged = subject.compare(newSubject) != 0;

	if (classChanged || teacherChanged || subjectChanged)
	{
		display.fillScreen(GxEPD_WHITE);
	}
	// top left text
	if (classChanged)
	{
		x = 5 + calculateCenteredXOfText(newClass, 240);
		y = 63;
		display.setCursor(x, y);
		display.print(newClass.c_str());
		display.updateWindow(8, 6, 230, 95, false);
	}
	// middle text
	if (teacherChanged)
	{
		x = 5 + calculateCenteredXOfText(newTeacher, 390);
		y = 160;
		display.setCursor(x, y);
		display.print(newTeacher.c_str());
		display.updateWindow(8, 102, 385, 95, false);
	}
	// bottom text
	if (subjectChanged)
	{
		x = 5 + calculateCenteredXOfText(newSubject, 390);
		y = 257;
		display.setCursor(x, y);
		display.print(newSubject.c_str());
		display.updateWindow(8, 198, 385, 95, false);
	}
}

static void callback(const char *topic, const char *payload)
{
	DynamicJsonBuffer jsonBuffer;
	JsonObject &root = jsonBuffer.parseObject(payload);
	std::string newTeacher = root["teacher"].as<String>().c_str();
	std::string newClass = root["class"].as<String>().c_str();
	std::string newSubject = root["subject"].as<String>().c_str();
	writeLessonToDisplay(newClass, newTeacher, newSubject);
	teacher = newTeacher;
	klass = newClass;
	subject = newSubject;
}

static void handleRoomRequest()
{
	if (HttpServer.args() == 1)
	{
		room = HttpServer.arg(0).c_str();
		ThingConfig.setValue("room", room.c_str());
	}

	HttpServer.send(200, "text/plain", room.c_str());
}

void writeStaticDataToDisplay()
{
	// top left
	display.drawRect(5, 5, 240, 97, GxEPD_BLACK);
	// top right
	display.drawRect(244, 5, 151, 97, GxEPD_BLACK);
	// middle
	display.drawRect(5, 101, 390, 97, GxEPD_BLACK);
	// bottom
	display.drawRect(5, 197, 390, 97, GxEPD_BLACK);
	// top right text
	display.setCursor(245 + calculateCenteredXOfText(room, 151), 63);
	display.print(room.c_str());
	display.updateWindow(0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, false);
	writeLessonToDisplay("-", "-", "-");
}

void setupDisplay()
{
	display.init(115200);
	display.setFont(&FreeMonoBold18pt7b);
	display.setTextColor(GxEPD_BLACK);
	display.fillScreen(GxEPD_WHITE);
	display.update();
}

void setupMqtt()
{
	MqttClient.init("/");
	room = ThingConfig.getValue("room");
	strcat(topic, room.c_str());
	sub.topic = topic;
	sub.subscriberCallback = callback;
	MqttClient.addSubscription(&sub);
	MqttClient.subscribeToBroker();
}

void setup()
{
	Serial.begin(115200); //Initialisierung der seriellen Schnittstelle
	ThingConfig.readConfig();
	HttpServer.init();
	HttpServer.on("/room", handleRoomRequest);
	room = ThingConfig.getValue("room");
	setupMqtt();
	setupDisplay();
	writeStaticDataToDisplay();
}

void loop()
{
	HttpServer.handleClient();
	MqttClient.doLoop();
	//delay(1);
}