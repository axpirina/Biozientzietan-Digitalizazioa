# Konfigurazioa

## Serie abiadura
- Monitorea: `monitor_speed = 115200` (`platformio.ini:15`)
- Kodea: `Serial.begin(115200)` (`src/main.cpp:57`)
- Beti 115200 baud erabili.

## Eraikitze sistema
- PlatformIO (npm/Node.js ez dago). Ez exekutatu `npm` script-ik inoiz.
- Aginduak: `pio run`, `pio run --target upload`, `pio device monitor`.

## Sekretuen politika
- Include karpetaren barruan secret.h artxibo batean gorde erabiltzaile eta pasahitz guztiak.
- Ez irakurri, ez erakutsi, ez log-ean inprimatu `include/secrets.h`-ren edukia.
- Fitxategi honek WiFi kredentzialak eta ThingsBoard access token-a ditu.
