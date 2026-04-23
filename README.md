# Biozientzietan Digitalizazioa - NodeMCU DHT11 Proiektua

[Ikusi dashboard-a](https://eu.thingsboard.cloud/dashboard/b4a992a0-398d-11f1-ba44-c54ab1d7f1f4?publicId=ebbac470-3d80-11f1-92f7-cbbd42e0f134){:target="_blank"}

![NodeMCU DHT11](Dokumentuak/Irudiak/Nodemcu-DHT11-_Sketch_bb.png)

ESP8266 NodeMCU eta DHT11 sensorea erabiliz ThingsBoard-era tenperatura eta hezetasuna bidaltzeko plataforma.

## Osagaiak

| Osagaia | Deskribapena |
|---------|-------------|
| ESP8266 NodeMCU | Mikrokontrolagailua (WiFi) |
| DHT11 | Tenperatura eta hezetasun sentsorea |
| Kableak | Ribbon kableak |
| Protoboard | (Aukerakoa) |

## Konexioak

| DHT11 Pin | NodeMCU Pin |
|-----------|------------|
| VCC | 3.3V edo 5V |
| GND | GND |
| DATA | D1 (GPIO5) |

### Important: Pull-up Erresistentzia

DATA eta VCC artean **4.7kΩ** pull-up erresistentzia jarri behar da komunikazio egokia lortzeko.

## Softwarearen Konfigurazioa

### 1. Aldatu platformio.ini-n

```ini
[env:nodemcuv2]
platform = espressif8266
board = nodemcuv2
framework = arduino
monitor_speed = 115200
lib_deps = adafruit/DHT sensor library@^1.4.6
           knolleary/PubSubClient@^2.8
```

### 2. Konfiguratu WiFi eta MQTT

Kopiatu `include/secrets.h.example` fitxategia `include/secrets.h` izenarekin eta aldatu balioak:

```cpp
#define WIFI_SSID "ZURE_SSID"
#define WIFI_PASSWORD "ZURE_PASAHITZA"

#define MQTT_SERVER "eu.thingsboard.cloud"
#define MQTT_PORT 1883
#define MQTT_USERNAME "ZURE_TOKEN"
#define MQTT_TOPIC "v1/devices/me/telemetry"
```

ThingsBoard-en:
1. Sortu device bat
2. Kopiatu "Access Token" (MQTT_USERNAME bezala erabili)

### 3. Kompilatu eta Igo

```bash
pio run --target upload
```

### 4. Monitorizatu

```bash
pio device monitor
```

## Egindako Zerbitzuak

- **WiFi**: Konfiguratzeko `include/secrets.h`-n
- **ThingsBoard**: eu.thingsboard.cloud
- **Tenperatura**: DHT11 sentsorea (0-50°C, ±2°C精确tasuna)
- **Hezetasuna**: DHT11 sentsorea (20-90% RH, ±5%精确tasuna)

## Arazoak konpontzeko

### "Akatsa datuak irakurtzean!" nan balioak
1. Egiaztatu pull-up erresistentzia (4.7kΩ) dagoela
2. Egiaztatu VCC 5V-ra konektatuta dagoela (3.3V ez da nahikoa izan daitekeelako)
3. Egiaztatu kableen konexioak
4. Probatu beste DHT sensor bat

### WiFi konexiorik ez
1. Egiaztatu SSID eta pasahitza zuzenak direla
2. Egiaztatu WiFi frekuentzia (2.4GHz behar da, 5GHz ez du onartzen)

### MQTT konexiorik ez
1. Egiaztatu token zuzena dela ThingsBoard-en
2. Egiaztatu internet konexioa dagoela

## Dokumentazio Gehiago

- [Eskuliburuak](Dokumentuak/Eskuliburuak/)
- [Fritzing Elementuak](Dokumentuak/Fritzing%20elementuak/)

## Lizentzia

MIT License - ikusi [LICENSE](LICENSE) fitxategia.

## Egilea

Plataforma: PlatformIO
Framework: Arduino
Plataforma IoT: ThingsBoard