#define THERM 0
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(analogRead(THERM));
}
