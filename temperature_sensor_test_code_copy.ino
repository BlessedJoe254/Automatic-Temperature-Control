#include <DHT.h>

#define DHTPIN 2      // Digital pin connected to DHT22
#define DHTTYPE DHT22 // DHT22 (AM2302)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT22 Test");
  dht.begin();
}

void loop() {
  delay(2000); // Wait 2 sec between readings (DHT22 max rate)

  float humidity = dht.readHumidity();     // Read humidity (%)
  float tempC = dht.readTemperature();     // Read temp in °C
  float tempF = dht.readTemperature(true); // Read temp in °F

  // Check if readings failed
  if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print results
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("% | Temp: ");
  Serial.print(tempC);
  Serial.print("°C (");
  Serial.print(tempF);
  Serial.println("°F)");
}