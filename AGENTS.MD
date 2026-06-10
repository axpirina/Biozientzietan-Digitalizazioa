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
- Cycles through 17 hardcoded Basque town coordinates every 10s.
- The whole repo is deployed to GitHub Pages on push to `main` (`.github/workflows/pages.yml`).
- No build or test CI exists.
- `index.html` and `include/dashboard.html` embed a ThingsBoard public dashboard.

## MQTT

- Server: `eu.thingsboard.cloud:1883`
- Credentials: ThingsBoard device access token goes in `MQTT_USERNAME`; password is blank (`NULL` in code).
- All data published to `v1/devices/me/telemetry`.

## VS Code

- Recommended extension: `platformio.platformio-ide`
- Unwanted: `ms-vscode.cpptools-extension-pack`

## CONFIGURATION

- Always folllow configuration.md file guideline.
