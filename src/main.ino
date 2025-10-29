/***************** Project + Blynk setup *****************/
#define BLYNK_TEMPLATE_ID "TMPL6HnlhlDX0"
#define BLYNK_TEMPLATE_NAME "jahidvai"
#define BLYNK_AUTH_TOKEN "1Dc0IoHF8cZXgr6SIf-Mdg2tpRp7U9M8"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

/***************** Hardware *****************/
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define LED_PIN 23

/***************** Network *****************/
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

/***************** App pins *****************/
// V0 = Switch (INT)
// V1 = Temperature Label (STRING)
// V2 = Humidity Label (STRING)
// V3 = LED control (INT)

BlynkTimer timer;
bool showData = false;

void sendSensor()
{
  float t = dht.readTemperature();   // °C
  float h = dht.readHumidity();      // %

  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if (showData) {
    Blynk.virtualWrite(V1, String("Temperature: ") + String(t, 1) + " °C");
    Blynk.virtualWrite(V2, String("Humidity: ") + String(h, 1) + " %");
  }
}

BLYNK_WRITE(V0)  // Switch Handler
{
  showData = param.asInt();

  if (!showData) {
    Blynk.virtualWrite(V1, "");
    Blynk.virtualWrite(V2, "");
  } else {
    sendSensor(); // Show immediate data
  }
}

BLYNK_WRITE(V3)  // LED control
{
  digitalWrite(LED_PIN, param.asInt() ? HIGH : LOW);
}

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0); // Sync Switch state
}

void setup()
{
  Serial.begin(115200);
  dht.begin();
  pinMode(LED_PIN, OUTPUT);

  Blynk.begin(auth, ssid, pass);

  // Update sensor reading every 2 seconds
  timer.setInterval(2000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
