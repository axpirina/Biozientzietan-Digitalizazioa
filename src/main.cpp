#include <Arduino.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define DHT_PIN D1
#define DHT_TYPE DHT11

#include <secrets.h>

DHT dht(DHT_PIN, DHT_TYPE);
WiFiClient espClient;
PubSubClient mqtt(espClient);

const int HIRI_KOPURUA = 17;
const float latitude[] = {
  43.0960,   // Arette
  43.1890,   // Barkoxe
  43.4756,   // Bardoze
  43.5277,   // Boucau
  43.48012,  // Biarritz
  43.38871,  // Donibane Lohizune
  43.31283,  // Donostia
  43.29571,  // Deba
  43.36417,  // Lekeitio
  43.40804,  // Mundaka
  43.2306,   // Karrantza
  42.723262, // Armiñon
  42.55461,  // Laguardia
  42.42269,  // Lodosa
  42.19653,  // Valtierra
  42.06166,  // Tutera
  42.37908   // Zarrakaztelu
};

const float longitude[] = {
  -0.7170,   // Arette
  -0.7695,   // Barkoxe
  -1.2025,   // Bardoze
  -1.4656,   // Boucau
  -1.55558,  // Biarritz
  -1.66267,  // Donibane Lohizune
  -1.97499,  // Donostia
  -2.35213,  // Deba
  -2.50492,  // Lekeitio
  -2.69852,  // Mundaka
  -3.3572,   // Karrantza
  -2.871835, // Armiñon
  -2.58528,  // Laguardia
  -2.07741,  // Lodosa
  -1.63459,  // Valtierra
  -1.60452,  // Tutera
  -1.44376   // Zarrakaztelu
};

void setup() {
  Serial.begin(115200);
  dht.begin();
  
  Serial.println("WiFi konektatzen...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi konektatuta!");
  
  mqtt.setServer(MQTT_SERVER, MQTT_PORT);
  Serial.println("MQTT konfiguratuta");
}

void reconnect() {
  while (!mqtt.connected()) {
    Serial.print("MQTT konektatzen...");
    if (mqtt.connect("ESP8266Client", MQTT_USERNAME, NULL)) {
      Serial.println("MQTT konektatuta!");
    } else {
      Serial.print("Akatsa: ");
      Serial.print(mqtt.state());
      Serial.println(" berriro saiatzen 5s...");
      delay(5000);
    }
  }
}

float kalkulatuIntzaPuntua(float temp, float hum) {
  float hi = 0.5 * (temp + 61.0 + ((temp - 68.0) * 1.2) + (hum * 0.094));
  if (hi >= 80) {
    hi = -8.785 + 1.611 * temp + 2.339 * hum - 0.146 * temp * hum 
         - 0.012308 * temp * temp - 0.016424 * hum * hum 
         + 0.002211 * temp * temp * hum + 0.000725 * temp * hum * hum 
         - 0.000003 * temp * temp * hum * hum;
  }
  return hi;
}

unsigned long previousLocationPublish = 0;
const unsigned long LOCATION_INTERVAL = 10000;
int currentTownIndex = 0;

void loop() {
  if (!mqtt.connected()) {
    reconnect();
  }
  mqtt.loop();

  unsigned long currentMillis = millis();
  
  if (currentMillis - previousLocationPublish >= LOCATION_INTERVAL) {
    previousLocationPublish = currentMillis;
    String payload = "{\"latitude\":" + String(latitude[currentTownIndex]) + ",\"longitude\":" + String(longitude[currentTownIndex]) + "}";
    Serial.print("Location JSON: ");
    Serial.println(payload);
    mqtt.publish(MQTT_TOPIC, payload.c_str());
    currentTownIndex = (currentTownIndex + 1) % HIRI_KOPURUA;
  }

  Serial.println("Irakurtzen...");
  float temperatura = dht.readTemperature();
  float hezetasuna = dht.readHumidity();

  Serial.print("Temp read: ");
  Serial.println(temperatura);
  Serial.print("Hez read: ");
  Serial.println(hezetasuna);

  if (isnan(temperatura) || isnan(hezetasuna)) {
    Serial.println("Akatsa datuak irakurtzean!");
  } else {
    Serial.print("Tenperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");
    Serial.print("Hezetasuna: ");
    Serial.print(hezetasuna);
    Serial.println(" %");

    float intza = kalkulatuIntzaPuntua(temperatura, hezetasuna);
    Serial.print("Intza puntua: ");
    Serial.println(intza);

    String payload = "{\"temperature\":" + String(temperatura) + ",\"humidity\":" + String(hezetasuna) + ",\"heatIndex\":" + String(intza) + "}";
    Serial.print("JSON: ");
    Serial.println(payload);
    mqtt.publish(MQTT_TOPIC, payload.c_str());
  }

  delay(2000);
}