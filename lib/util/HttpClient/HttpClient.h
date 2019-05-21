#include <string>
#include <stdlib.h>
#include <esp_http_client.h>
#include <esp_log.h>

struct Response{
    std::string body;
};

class HttpClient{
    private:
    public:
    char* get(std::string url);
};