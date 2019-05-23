#pragma once

class EspUdpClass
{
public:
  void init();
  bool sendUdpMessage(const char *ipAddress, const int port, const char *message);
private:
  int _clientSocket=-1;
};

extern EspUdpClass EspUdp;
