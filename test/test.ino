int i = 0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  Serial.println("Setup. \n");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(i);
  delay(500);
  i++;
}
