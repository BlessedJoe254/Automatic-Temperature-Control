#include <OneWire.h>
#include <DallasTemperature.h>
OneWire oneWire(2);  // Data wire on pin 2
DallasTemperature sensors(&oneWire);
void setup() {
  Serial.begin(9600);
  sensors.begin();
}
void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println("°C");
  delay(1000);
}