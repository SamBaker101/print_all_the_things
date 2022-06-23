//Sam Baker - 05/23/2022
//Naive test for salvaged stepper from Epson scanner bed

#define WIRE_ONE 6
#define WIRE_TWO 5


void setup() {
  pinMode(WIRE_ONE, OUTPUT);
  pinMode(WIRE_TWO, OUTPUT);
}

void loop() {
  digitalWrite(WIRE_ONE, LOW);
  digitalWrite(WIRE_TWO, HIGH);
  delay(5);
  digitalWrite(WIRE_TWO, LOW);
  digitalWrite(WIRE_ONE, HIGH);
  delay(5);
}
