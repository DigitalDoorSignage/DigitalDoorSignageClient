#include <string.h>
#include <sys/param.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "tcpip_adapter.h"

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include <lwip/netdb.h>

#include <EspUdp.h>
#include <Constants.h>
#include <Logger.h>
#include <UdpLoggerTarget.h>

#define SERVERPORT 41235

static void udp_server_task(void *pvParameters)
{
    char loggerMessage[LENGTH_LOGGER_MESSAGE];
    char ipAddressText[128];
    char addr_str[128];
    int addr_family;
    int ip_protocol;

    while (1)
    {

        struct sockaddr_in dest_addr;
        dest_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(SERVERPORT);
        addr_family = AF_INET;
        ip_protocol = IPPROTO_IP;
        inet_ntoa_r(dest_addr.sin_addr, addr_str, sizeof(addr_str) - 1);

        int sock = socket(addr_family, SOCK_DGRAM, ip_protocol);
        if (sock < 0)
        {
            sprintf(loggerMessage, "Unable to create socket: errno %d", errno);
            Logger.error("EspUdp; udp_server_task()", loggerMessage);
            break;
        }
        Logger.info("EspUdp; udp_server_task()", "Socket created");

        int err = bind(sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
        if (err < 0)
        {
            sprintf(loggerMessage, "Socket unable to bind: errno %d", errno);
            Logger.error("EspUdp; udp_server_task()", loggerMessage);
            break;
        }
        sprintf(loggerMessage, "Socket bound, port %d", SERVERPORT);
        Logger.info("EspUdp; udp_server_task()", loggerMessage);

        while (1)
        {
            Logger.info("EspUdp; udp_server_task()", "Waiting for data");
            struct sockaddr_in6 source_addr; // Large enough for both IPv4 or IPv6
            socklen_t socklen = sizeof(source_addr);
            int len = recvfrom(sock, ipAddressText, sizeof(ipAddressText) - 1, 0, (struct sockaddr *)&source_addr, &socklen);

            // Error occurred during receiving
            if (len < 0)
            {
                sprintf(loggerMessage, "recvfrom failed: errno %d", errno);
                Logger.error("EspUdp; udp_server_task()", loggerMessage);
                break;
            }
            // Data received
            else
            {
                // Get the sender's ip address as string
                if (source_addr.sin6_family == PF_INET)
                {
                    inet_ntoa_r(((struct sockaddr_in *)&source_addr)->sin_addr.s_addr, addr_str, sizeof(addr_str) - 1);
                }
                else if (source_addr.sin6_family == PF_INET6)
                {
                    inet6_ntoa_r(source_addr.sin6_addr, addr_str, sizeof(addr_str) - 1);
                }

                ipAddressText[len] = 0; // Null-terminate whatever we received and treat like a string...
                sprintf(loggerMessage, "Received %d bytes from %s: %s", len, addr_str, ipAddressText);
                Logger.info("EspUdp; udp_server_task()", loggerMessage);

                // int err = sendto(sock, ipAddressText, len, 0, (struct sockaddr *)&source_addr, sizeof(source_addr));
                if (err < 0)
                {
                    sprintf(loggerMessage, "Error occurred during sending: errno %d", errno);
                    Logger.error("EspUdp; udp_server_task()", loggerMessage);
                    break;
                }
                else
                {
                    LoggerTarget *target = Logger.getLoggerTarget(ipAddressText);
                    if (target == nullptr) // erste Anfrage des Udp-Clients
                    {
                        target = new UdpLoggerTarget(ipAddressText, LOG_LEVEL_INFO);
                        Logger.addLoggerTarget(target);
                        sprintf(loggerMessage, "Logger registered:%s", ipAddressText);
                        Logger.info("EspUdp; udp_server_task()", loggerMessage);
                    }
                    sprintf(loggerMessage, "%s;%d", ipAddressText, target->getLogLevel());
                    Logger.info("EspUdp;online", loggerMessage);
                }
            }
        }

        if (sock != -1)
        {
            sprintf(loggerMessage, "Shutting down socket and restarting...");
            Logger.error("EspUdp; udp_server_task()", loggerMessage);
            shutdown(sock, 0);
            close(sock);
        }
    }
    vTaskDelete(NULL);
}

bool EspUdpClass::sendUdpMessage(const char *ipAddress, const int port, const char *message)
{
    //printf("EspUdp; sendUdpMessage(); Start");
    char addr_str[128];
    // int addr_family;
    // int ip_protocol;

    char loggerMessage[LENGTH_LOGGER_MESSAGE];
    struct sockaddr_in dest_addr;
    dest_addr.sin_addr.s_addr = inet_addr(ipAddress);
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    // addr_family = AF_INET;
    // ip_protocol = IPPROTO_IP;

    if (_clientSocket < 0)
    {
        printf("!!!! EspUdp; udp_client_task();clientSocket lower 0");
    }

    inet_ntoa_r(dest_addr.sin_addr, addr_str, sizeof(addr_str) - 1);

    int err = sendto(_clientSocket, message, strlen(message), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (err < 0)
    {
        printf(loggerMessage, "!!!! EspUdp; udp_client_task();Error occurred during sending: errno %d", errno);
        return false;
    }
    //printf("EspUdp; udp_client_task(); Message sent: %s", message);
    return true;
}

void EspUdpClass::init()
{
    int addr_family;
    int ip_protocol;
    char loggerMessage[LENGTH_LOGGER_MESSAGE];
    addr_family = AF_INET;
    ip_protocol = IPPROTO_IP;

    xTaskCreate(udp_server_task, "udp_server", 4096, NULL, 5, NULL);

    _clientSocket = socket(addr_family, SOCK_DGRAM, ip_protocol);
    if (_clientSocket < 0)
    {
        sprintf(loggerMessage, "Unable to create socket: errno %d", errno);
        Logger.error("EspUdp; init()", loggerMessage);
        return;
    }
    sprintf(loggerMessage, "Clientsocket created!");
    Logger.info("EspUdp; init()", loggerMessage);
}

EspUdpClass EspUdp;