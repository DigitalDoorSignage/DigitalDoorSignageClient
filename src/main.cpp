#include <stdlib.h>
#include <string>

//util
#include <Storage/Storage.h>
//own
#include <EspConfig.h>
#include <EspStation.h>
#include <HttpServer.h>

#define TAG "HTTP CLIENT"

extern "C"
{
    void app_main(void);
}

// GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/17, /*RST=*/16); // arbitrary selection of 17, 16
// GxEPD_Class display(io, /*RST=*/16, /*BUSY=*/4);		// arbitrary selection of (16), 4
std::string room;
Storage storage;

int calculateWidthOfText(std::string text)
{
    return text.length() * 21 - 3;
}

int calculateCenteredXOfText(std::string text, int width)
{
    return (width - calculateWidthOfText(text)) / 2;
}

void app_main()
{
    
    EspConfig.init();
    EspStation.init();
    HttpServer.init();
    while(1){
        printf("test");
    }
    // HttpClient temp;
    // temp.get("http://localhost:8080/webuntisclient-1.0-SNAPSHOT/api/state?room=E23");    
}