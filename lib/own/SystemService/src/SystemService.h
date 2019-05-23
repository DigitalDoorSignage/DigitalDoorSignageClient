/*
SystemService

Ziele:
  - Fehlertoleranz des Systems erhöhen
    - der zyklische Ablauf wird mittels Watchdog überwacht
    - bei fatalen Fehlern wird das System neu gestartet
    - bei ständig auftauchenden Fehlern wird das System nach 5 Fehlern neu gestartet
    - Memoryleaks werden zuerst als normale Fehler, bei weniger als 30% des Heaps nach dem Programmstart als FatalError behandelt
  - Dokumentation der auftretenden Probleme
    - Logger 
    - ThingConfig verwaltet aktuell offene Anzahl von fatalen Fehlern, die letzte Fehlermeldung und den letzten Restartgrund
  - "Selbstheilung", indem die Fehlerzähler nach 10-minütigen fehlerfreien Betrieb gelöscht werden
  - Totalabschaltung nach 5 fatalen Fehlern innerhalb kurzer Zeit

Test:
  Die Systemservice-Funktionen können über spezielle Routen des Webservers getestet werden
    http://192.168.0.13/state 
    http://192.168.0.13/pusherror           erzeugt einen einfachen Fehler, nach fünf Fehlern wird daraus ein FatalError
    http://192.168.0.13/pushfatalerror      erzeugt einen FatalError und damit einen Restart des Systems
    http://192.168.0.13/allocatememory      alloziert einen größeren Speicherbereich und führt bei öfterem Aufruf zu Error und FatalError
    http://192.168.0.13/stopfeedwatchdog    blockiert die Behandlung des Watchdog und löst in ca. 30 Sekunden einen Restart aus

*/

#pragma once
#include "esp_attr.h"

class SystemServiceClass
{
public:
  void init();

  long getMicros();
  long getMillis();

  void pushFatalError(const char *errorMessage);
  void pushError(const char *errorMessage);
  // void addLed(LED *led);
  void checkSystem();

  void enableWatchdog(uint8_t seconds);
  void disableWatchdog();
  void feedWatchdog();
  const char *getResetReasonString(int reasonCode);

private:
  int _restarts = 0;
  int _errors = 0;
  long _lastErrorTime = 0;
  long _lastRestartTime;
  int _startHeapSize;
  long _nextMessageTime=0;
  float _nextHeapSizeQuoteForNotification = 0.7;

  };

extern SystemServiceClass SystemService;
