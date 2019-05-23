#pragma once

/*
 Der EspWifiManager ist für den Wifi-Zugriff des ESP verantwortlich. Er versucht, 
 mit den gespeicherten Credentials eine Verbindung herzustellen. Gelingt das nicht,
 wird ein eigener AP (mit der Mac-Adresse als SSID) geöffnet. Unter der Adresse 192.168.4.1
 wartet dann ein Webserver auf die Konfigurationdes gesamten ESP (Wifi, MQTT, NTP, ...)
*/
class EspWifiManagerClass
{
  public:
	bool startWifi();
	// bool connectWithSavedCredentials();
	// void startWithConfigPage();
	void getIpAddress(char *ipAddress);
	// bool reconnectWifi();

  private:
};

extern EspWifiManagerClass EspWifiManager;
