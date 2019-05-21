#include <stdlib.h>
#include <string>
#include <esp_http_server.h>

#include <esp_http_client.h>
#include <esp_log.h>
#include <Storage/Storage.h>

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
}