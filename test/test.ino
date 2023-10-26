#include "HX711.h"
 
#define DT A1
#define SCK A0

HX711 cell;

void setup() {
  cell.begin(DT, SCK);
  Serial.begin(9600);
}
 
void loop() {
  float read = cell.read();
  Serial.println(read);
  delay(500);
}