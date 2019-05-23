#include <EspWifiManager.h>
#include <Logger.h>
#include <SerialLoggerTarget.h>
#include <Watchdog.h>
#include <HttpServer.h>

void setup()
{

	Serial.begin(115200);

	Serial.printf("!!! setup() running on core %d ", xPortGetCoreID());
	Serial.println();
	Serial.print("* Resetreason Core 0: ");
	Watchdog.printResetReason(0);
	Serial.println("* Resetreason Core 1: ");
	Watchdog.printResetReason(1);

	Serial.println();
	Serial.println(F("*EspWifiManager Test"));
	Serial.println(F("*==================="));

	Logger.init("EspWifiManagerTest");
	SerialLoggerTarget *slt = new SerialLoggerTarget("Serial", 0);
	Logger.addLoggerTarget(slt);
	Logger.info("Main", "EspWifiManagerTest");

	if (EspWifiManager.startWifi())
	{
		Logger.info("Main", "NORMAL START");
		char ipAddress[30];
		EspWifiManager.getIpAddress(ipAddress);
		Logger.info("Main, getIpAddress()", ipAddress);
		HttpServer.init();
	}
}

void loop()
{
	HttpServer.handleClient();
	delay(1);
}
