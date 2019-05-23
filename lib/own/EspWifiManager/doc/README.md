# Library EspWifiManager

## Ziele

Der EspWifiManager ist für die Verbindung des ESP mit einem Accesspoint verantwortlich. Normalerweise meldet er sich mit den letzten gültigen Credentials an. Sollte das schiefgehen, wird nach einem Restart über den WiIfiManager (Arduino-Library) die Konfigurationsseite (Wifi, Mqtt-Broker, ...) angeboten. Nach einem neuerlichen Neustart wird wieder versucht, den ESP mit den eingegebenen Credentials anzumelden.
Die Restarts sind erforderlich, weil die beiden Wifi-Bibliotheken (Arduino WiFi, Esp-Idf esp_wifi) sich gegenseitig stören. Die Steuerung, mit welchem Wifi-Stack hochgefahren wird, erfolgt über einen Eintrag in ThingConfig (HasToStartWithConfigPage).

Zur Überwachung des Verbindungszustandes der esp_wifi-Verbindung werden die Wifi-Events "belauscht".

## Testprogramm

Das Testprogramm versucht sich mit dem WLAN (z.B. Android-AP) zu verbinden. Gelingt dies nicht, wird nach einem Neustart innerhalb weniger Sekunden ein AP (SSID mit Macadresse) geöffnet, der die Konfigurationsseite anzeigt. Nach Eingabe und Abspeichern der Konfiguration wird der ESP automatisch neu gestartet.

Zum Testen Android-AP abschalten und ESP reseten. Nach ca. 30 Sekunden erscheint der AP zur Auswahl.
Android-AP wieder einschalten. 
Nach der Verbindung mit dem AP wird automatisch das Konfigurationsmenü angezeigt. 
Konfiguration eingeben, abspeichern und ca. 30 Sekunden warten. ESP sollte selbstständig im esp_wifi-Mode starten.
Über die Adresse des ESP (192.168.x.x/state) prüfen, ob er erreichbar ist.
