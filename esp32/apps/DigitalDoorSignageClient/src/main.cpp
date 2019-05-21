#include <stdlib.h>
#include <string>
#include <esp_http_server.h>

#include <esp_http_client.h>
#include <esp_log.h>

#define TAG "HTTP CLIENT"


extern "C"{
    void app_main(void);
}

// GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/17, /*RST=*/16); // arbitrary selection of 17, 16
// GxEPD_Class display(io, /*RST=*/16, /*BUSY=*/4);		// arbitrary selection of (16), 4
std::string room;

esp_err_t _http_event_handler(esp_http_client_event_t *evt)
{
    switch(evt->event_id) {
        case HTTP_EVENT_ERROR:
            ESP_LOGD(TAG, "HTTP_EVENT_ERROR");
            break;
        case HTTP_EVENT_ON_CONNECTED:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_CONNECTED");
            break;
        case HTTP_EVENT_HEADER_SENT:
            ESP_LOGD(TAG, "HTTP_EVENT_HEADER_SENT");
            break;
        case HTTP_EVENT_ON_HEADER:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key, evt->header_value);
            break;
        case HTTP_EVENT_ON_DATA:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
            if (!esp_http_client_is_chunked_response(evt->client)) {
                // Write out data
                // printf("%.*s", evt->data_len, (char*)evt->data);
            }

            break;
        case HTTP_EVENT_ON_FINISH:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH");
            break;
        case HTTP_EVENT_DISCONNECTED:
            ESP_LOGD(TAG, "HTTP_EVENT_DISCONNECTED");
            break;
    }
    return ESP_OK;
}

void http_rest_with_url()
{
    esp_http_client_config_t config = {
        // .url = "http://httpbin.org/get",
        // .event_handler = _http_event_handler,
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);

    // GET
    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK) {
        ESP_LOGI(TAG, "HTTP GET Status = %d, content_length = %d",
                esp_http_client_get_status_code(client),
                esp_http_client_get_content_length(client));
    } else {
        ESP_LOGE(TAG, "HTTP GET request failed: %s", esp_err_to_name(err));
    }
}


// int calculateWidthOfText(std::string text)
// {
// 	return text.length() * 21 - 3;
// }

// int calculateCenteredXOfText(std::string text, int width)
// {
// 	return (width - calculateWidthOfText(text)) / 2;
// }

// static void writeLessonToDisplay(std::string newClass, std::string newTeacher, std::string newSubject)
// {
// 	int x, y = 0;
// 	boolean classChanged = klass.compare(newClass) != 0;
// 	boolean teacherChanged = teacher.compare(newTeacher) != 0;
// 	boolean subjectChanged = subject.compare(newSubject) != 0;

// 	if (classChanged || teacherChanged || subjectChanged)
// 	{
// 		display.fillScreen(GxEPD_WHITE);
// 	}
// 	// top left text
// 	if (classChanged)
// 	{
// 		x = 5 + calculateCenteredXOfText(newClass, 240);
// 		y = 63;
// 		display.setCursor(x, y);
// 		display.print(newClass.c_str());
// 		display.updateWindow(8, 6, 230, 95, false);
// 	}
// 	// middle text
// 	if (teacherChanged)
// 	{
// 		x = 5 + calculateCenteredXOfText(newTeacher, 390);
// 		y = 160;
// 		display.setCursor(x, y);
// 		display.print(newTeacher.c_str());
// 		display.updateWindow(8, 102, 385, 95, false);
// 	}
// 	// bottom text
// 	if (subjectChanged)
// 	{
// 		x = 5 + calculateCenteredXOfText(newSubject, 390);
// 		y = 257;
// 		display.setCursor(x, y);
// 		display.print(newSubject.c_str());
// 		display.updateWindow(8, 198, 385, 95, false);
// 	}
// }

// static void callback(const char *topic, const char *payload)
// {
// 	DynamicJsonBuffer jsonBuffer;
// 	JsonObject &root = jsonBuffer.parseObject(payload);
// 	std::string newTeacher = root["teacher"].as<String>().c_str();
// 	std::string newClass = root["class"].as<String>().c_str();
// 	std::string newSubject = root["subject"].as<String>().c_str();
// 	writeLessonToDisplay(newClass, newTeacher, newSubject);
// 	teacher = newTeacher;
// 	klass = newClass;
// 	subject = newSubject;
// }

// static void handleRoomRequest()
// {
// 	if (HttpServer.args() == 1)
// 	{
// 		room = HttpServer.arg(0).c_str();
// 		ThingConfig.setValue("room", room.c_str());
// 	}

// 	HttpServer.send(200, "text/plain", room.c_str());
// }

// void writeStaticDataToDisplay()
// {
// 	// top left
// 	display.drawRect(5, 5, 240, 97, GxEPD_BLACK);
// 	// top right
// 	display.drawRect(244, 5, 151, 97, GxEPD_BLACK);
// 	// middle
// 	display.drawRect(5, 101, 390, 97, GxEPD_BLACK);
// 	// bottom
// 	display.drawRect(5, 197, 390, 97, GxEPD_BLACK);
// 	// top right text
// 	display.setCursor(245 + calculateCenteredXOfText(room, 151), 63);
// 	display.print(room.c_str());
// 	display.updateWindow(0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, false);
// 	writeLessonToDisplay("-", "-", "-");
// }

// void setupDisplay()
// {
// 	display.init(115200);
// 	display.setFont(&FreeMonoBold18pt7b);
// 	display.setTextColor(GxEPD_BLACK);
// 	display.fillScreen(GxEPD_WHITE);
// 	display.update();
// }

// void setupMqtt()
// {
// 	MqttClient.init("/");
// 	room = ThingConfig.getValue("room");
// 	strcat(topic, room.c_str());
// 	sub.topic = topic;
// 	sub.subscriberCallback = callback;
// 	MqttClient.addSubscription(&sub);
// 	MqttClient.subscribeToBroker();
// }

// // void setup()
// // {
// // 	Serial.begin(115200); //Initialisierung der seriellen Schnittstelle
// // 	ThingConfig.readConfig();
// // 	HttpServer.init();
// // 	HttpServer.on("/room", handleRoomRequest);
// // 	room = ThingConfig.getValue("room");
// // 	setupMqtt();
// // 	setupDisplay();
// // 	writeStaticDataToDisplay();
// // }

// // void loop()
// // {
// // 	HttpServer.handleClient();
// // 	MqttClient.doLoop();
// // 	//delay(1);
// // }

// void app_main(){
// 	Serial.begin(115200); //Initialisierung der seriellen Schnittstelle
// 	ThingConfig.readConfig();
// 	HttpServer.init();
// 	HttpServer.on("/room", handleRoomRequest);
// 	room = ThingConfig.getValue("room");
// 	setupMqtt();
// 	setupDisplay();
// 	writeStaticDataToDisplay();

// 	while(1){
// 		HttpServer.handleClient();
// 		MqttClient.doLoop();
// 	}
// }


void app_main(){

}