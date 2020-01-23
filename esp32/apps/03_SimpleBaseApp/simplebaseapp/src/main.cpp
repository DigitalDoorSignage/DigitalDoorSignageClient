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

#include <HTTPClient.h>


GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/17, /*RST=*/16); // arbitrary selection of 17, 16
GxEPD_Class display(io, /*RST=*/16, /*BUSY=*/4);		// arbitrary selection of (16), 4
MqttSubscription sub = MqttSubscription();
std::string room;
std::string encodedRoom;
std::string teacher;
std::string subject;
std::string klass;
std::string version;
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
		x = 5 + calculateCenteredXOfText(newClass, 200);
		y = 63;
		display.setCursor(x, y);
		display.print(newClass.c_str());
		display.updateWindow(8, 6, 180, 95, false);
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

static void callback(const char *payload)
{
	printf("in callback payload: %s\n", payload);
	DynamicJsonBuffer jsonBuffer;
	JsonObject &root = jsonBuffer.parseObject(payload);
	std::string newTeacher;
	//std::string newTeacher = root["teachers"][0]["shortName"].as<String>().c_str();
	JsonArray& array = root["teachers"].as<JsonArray>();
	int count = 0;
	for(JsonVariant v : array) {
		if(count == 0){
			newTeacher = v["shortName"].as<String>().c_str();
		}
		else
		{
			newTeacher = newTeacher + ", " + v["shortName"].as<String>().c_str();
		}
		count++;
	}
	std::string newClass = root["klass"]["name"].as<String>().c_str();
	std::string newSubject = root["subject"]["name"].as<String>().c_str();
	if(newClass.empty()){
		writeLessonToDisplay("-", "-", "-");
	}
	else{
		writeLessonToDisplay(newClass, newTeacher, newSubject);
	}
	teacher = newTeacher;
	klass = newClass;
	subject = newSubject;
}

void writeRoomToDisplay(){

	// top right text
	if(room.find(" ") != std::string::npos){
		int spaceIndex = room.find(" ");
		std::string partOne = room.substr(0, spaceIndex);

		display.setCursor(205 + calculateCenteredXOfText(partOne, 185), 43);

		display.print(partOne.c_str());

		std::string partTwo = room.substr(spaceIndex, room.length());

		display.setCursor(205 + calculateCenteredXOfText(partTwo, 175), 73);

		display.print(partTwo.c_str());
	}
	else
	{
		display.setCursor(205 + calculateCenteredXOfText(room, 175), 63);
		display.print(room.c_str());
	}
	
	display.updateWindow(209, 8, 170, 86, false);
}

void writeStaticDataToDisplay()
{
	// top left
	display.drawRect(5, 5, 200, 97, GxEPD_BLACK);
	// top right
	display.drawRect(204, 5, 191, 97, GxEPD_BLACK);
	// middle
	display.drawRect(5, 101, 390, 97, GxEPD_BLACK);
	// bottom
	display.drawRect(5, 197, 390, 97, GxEPD_BLACK);

	display.updateWindow(0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, false);
	writeRoomToDisplay();
	writeLessonToDisplay("-", "-", "-");
}

static void handleRoomRequest()
{
	if (HttpServer.args() == 1)
	{
		room = HttpServer.arg(0).c_str();
		encodedRoom = room.c_str();

		if(room.find(" ") != std::string::npos){
			encodedRoom.replace(encodedRoom.find(" "), sizeof(" ")-1, "%20");
		}
		
		ThingConfig.setValue("room", room.c_str());
		//writeStaticDataToDisplay();
		writeRoomToDisplay();
	}

	HttpServer.send(200, "text/plain", room.c_str());
}

void setupDisplay()
{
	display.init(115200);
	display.setFont(&FreeMonoBold18pt7b);
	display.setTextColor(GxEPD_BLACK);
	display.fillScreen(GxEPD_WHITE);
	display.update();
}

void setup()
{
	Serial.begin(115200); //Initialisierung der seriellen Schnittstelle
	while(!Serial);
	ThingConfig.readConfig();
	HttpServer.init();
	HttpServer.on("/room", handleRoomRequest);
	room = ThingConfig.getValue("room");
	printf("before c_str()\n");
	encodedRoom = room.c_str();
	printf("after c_str()\n");
	if(room.find(" ") != std::string::npos){
		encodedRoom.replace(encodedRoom.find(" "), sizeof(" ")-1, "%20");
		printf("after replace\n");
	}
	setupDisplay();
	writeStaticDataToDisplay();
}

void loop()
{
	//printf("start\n");
	HttpServer.handleClient();
	//printf("after httpServer.handleClient\n");
	HTTPClient httpUpdated;
	HTTPClient httpData;
	// printf(room.c_str());
	// printf("after room.c_str()\n");
	if(!room.empty()){
		std::string updatedUrl = "http://10.42.0.1:8080/webuntisclient-1.0-SNAPSHOT/api/updatedAt?room=" + encodedRoom;
		std::string stateUrl = "http://10.42.0.1:8080/webuntisclient-1.0-SNAPSHOT/api/state?room=" + encodedRoom;
		httpUpdated.begin(updatedUrl.c_str()); //HTTP
		printf("[HTTP] GET %s\n", updatedUrl.c_str());
		// start connection and send HTTP header
		int httpCode = httpUpdated.GET();

		// httpCode will be negative on error
		if(httpCode > 0) {
			// HTTP header has been send and Server response header has been handled
			Serial.printf("[HTTP] GET...Version code: %d\n", httpCode);

			// file found at server
			if(httpCode == HTTP_CODE_OK) {
				String payload = httpUpdated.getString();
				printf("version: %s payload: %s\n", version.c_str(), payload.c_str());
				if(!payload.equals(version.c_str())){
					printf("in if now\n");
					strcpy((char*)version.c_str(), payload.c_str());
					
					httpData.begin(stateUrl.c_str());
					printf("[HTTP] GET %s\n", stateUrl.c_str());
					// start connection and send HTTP header
					int httpCodeData = httpData.GET();

					// httpCode will be negative on error
					if(httpCodeData > 0) {
						// HTTP header has been send and Server response header has been handled
						Serial.printf("[HTTP] GET...Data code: %d\n", httpCodeData);

						// file found at server
						if(httpCodeData == HTTP_CODE_OK) {
							String payload = httpData.getString();
							callback(payload.c_str());
						}
					} else {
						Serial.printf("[HTTP] GET...Data failed, error: %s\n", httpData.errorToString(httpCodeData).c_str());
					}

					httpData.end();
				}
			}
		} else {
			Serial.printf("[HTTP] GET...Version failed, error: %s\n", httpUpdated.errorToString(httpCode).c_str());
		}
		httpUpdated.end();
		delay(5000);
	}
		//one round every minute
}