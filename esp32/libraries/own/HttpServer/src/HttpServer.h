#pragma once

#include <esp_http_server.h>
#include <WebServer.h>

class HttpServerClass : WebServer
{
    public:
        void init();
        void addRoute(const httpd_uri* httpdUri);
        
    private:
    httpd_handle_t startWebserver();
    httpd_handle_t _server;
};
extern HttpServerClass HttpServer;
