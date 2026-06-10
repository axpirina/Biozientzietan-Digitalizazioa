## Build & Flash

```bash
pio run             # build
pio run --target upload   # flash to board
pio device monitor        # serial monitor (115200 baud)
```

## Secrets

`include/secrets.h` is gitignored. Copy from `include/secrets.h.example` and fill:

```cpp
#define WIFI_SSID "your_ssid"
#define WIFI_PASSWORD "your_password"
#define MQTT_SERVER "eu.thingsboard.cloud"
#define MQTT_PORT 1883
#define MQTT_USERNAME "your_thingsboard_device_token"  // token, not username
#define MQTT_TOPIC "v1/devices/me/telemetry"
```

## Hardware

- **Board**: NodeMCU V1.0 (nodemcuv2, ESP8266)
- **DHT11 data pin**: D1 (GPIO5) — see `src/main.cpp:6`
- **DHT11 VCC**: 5V required (3.3V may be unreliable)
- **Libs**: `adafruit/DHT sensor library@^1.4.6`, `knolleary/PubSubClient@^2.8`

## Architecture

- `src/main.cpp` is the real firmware (not the example in README).
- Publishes temperature/humidity/heatIndex every ~2s to ThingsBoard via MQTT.
- `index.html` and `include/dashboard.html` embed a ThingsBoard public dashboard.

## MQTT

- Server: `eu.thingsboard.cloud:1883`
- Credentials: ThingsBoard device access token goes in `MQTT_USERNAME`; password is blank (`NULL` in code).
- All data published to `v1/devices/me/telemetry`.

## VS Code

- Recommended extension: `platformio.platformio-ide`
- Unwanted: `ms-vscode.cpptools-extension-pack`

## Serie abiadura
- Monitorea: `monitor_speed = 115200` (`platformio.ini:15`)
- Kodea: `Serial.begin(115200)` (`src/main.cpp:57`)
- Beti 115200 baud erabili.

## Segurtasuna
- PlatformIO (npm/Node.js ez dago). Ez exekutatu `npm` script-ik inoiz.

## Sekretuen politika
- Include karpetaren barruan secret.h artxibo batean gorde erabiltzaile eta pasahitz guztiak.
- Ez irakurri, ez erakutsi, ez log-ean inprimatu `include/secrets.h`-ren edukia.
- Fitxategi honek WiFi kredentzialak eta ThingsBoard access token-a ditu.
- Github-era igoaz gero gitignorean gehitu. 

## Kodeketa-estiloa
- Aldagaiak ingelesez
- Komentarioak euskaraz
