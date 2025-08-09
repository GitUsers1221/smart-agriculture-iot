// #include "DHT.h"

// // Define the pin where the data line is connected
// #define DHTPIN 2

// // Define the sensor type
// #define DHTTYPE DHT22

// // Initialize the DHT sensor
// DHT dht(DHTPIN, DHTTYPE);

// void setup() {
//   Serial.begin(9600);
//   dht.begin();
// }

// void loop() {
//   // Wait a few seconds between measurements
//   delay(2000);

//   // Read humidity and temperature
//   float humidity = dht.readHumidity();
//   float temperature = dht.readTemperature(); // Celsius by default

//   // Check if any reads failed
//   if (isnan(humidity) || isnan(temperature)) {
//     Serial.println("Failed to read from DHT sensor!");
//     return;
//   }

//   // Print the results
//   Serial.print("Humidity: ");
//   Serial.print(humidity);
//   Serial.print(" %\t");
//   Serial.print("Temperature: ");
//   Serial.print(temperature);
//   Serial.println(" °C");

// }


#include <DHT.h>

// === DHT Sensor Setup ===
#define DHTTYPE DHT22

#define DHTPIN1 5   // GPIO5 (D1)
#define DHTPIN2 4   // GPIO4 (D2)
#define DHTPIN3 14  // GPIO14 (D5)

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);

//  Soil Moisture Sensor Setup 
// Assuming analog switching (only A0 is available)
#define MOISTURE_SENSOR_1 A0
#define MOISTURE_SENSOR_2 A0  // Use mux or manual switching
#define MOISTURE_SENSOR_3 A0  // Use mux or manual switching

void setup() {
  Serial.begin(115200);
  dht1.begin();
  dht2.begin();
  dht3.begin();

  // Set up pins if using relays/mux
  pinMode(mux_control_pinX, OUTPUT); etc.
}

void loop() {
  //  Read DHT22 Sensors 
  float temp1 = dht1.readTemperature();
  float hum1 = dht1.readHumidity();

  float temp2 = dht2.readTemperature();
  float hum2 = dht2.readHumidity();

  float temp3 = dht3.readTemperature();
  float hum3 = dht3.readHumidity();

  // // //    Read HW-080 Soil Moisture Sensors 
  int moisture1 = analogRead(MOISTURE_SENSOR_1);
  delay(500);  // Delay for switching/mux time

  // Switch to second sensor (via mux or control pin)
  digitalWrite(muxControlPin, HIGH);
  int moisture2 = analogRead(MOISTURE_SENSOR_2);
  delay(500);

  // Switch to third sensor
  digitalWrite(muxControlPin, nextState);
  int moisture3 = analogRead(MOISTURE_SENSOR_3);
  delay(500);

  //    Print to Serial Monitor 
  Serial.println("---- DHT22 Readings ----");
  Serial.printf("Sensor 1: Temp: %.1f°C  Hum: %.1f%%\n", temp1, hum1);
  Serial.printf("Sensor 2: Temp: %.1f°C  Hum: %.1f%%\n", temp2, hum2);
  Serial.printf("Sensor 3: Temp: %.1f°C  Hum: %.1f%%\n", temp3, hum3);

  Serial.println("---- Soil Moisture ----");
  Serial.printf("Moisture 1: %d\n", moisture1);
  Serial.printf("Moisture 2: %d\n", moisture2);
  Serial.printf("Moisture 3: %d\n", moisture3);

  delay(5000);  // Wait before next reading
}
