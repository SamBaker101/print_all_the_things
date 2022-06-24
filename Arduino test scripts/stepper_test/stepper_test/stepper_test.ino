//Sam Baker - 05/23/2022
//Naive test for salvaged stepper from Epson scanner bed

#define WIRE_ONE 6
#define WIRE_TWO 5
#define WIRE_THREE 4
#define WIRE_FOUR 3

void setup() {
  pinMode(WIRE_ONE, OUTPUT);
  pinMode(WIRE_TWO, OUTPUT);
  pinMode(WIRE_THREE, OUTPUT);
  pinMode(WIRE_FOUR, OUTPUT);
}

void loop() {
  digitalWrite(WIRE_TWO, LOW);
  digitalWrite(WIRE_THREE, LOW);
  digitalWrite(WIRE_FOUR, LOW);
  digitalWrite(WIRE_ONE, HIGH);
  delay(5);
  digitalWrite(WIRE_ONE, LOW);
  digitalWrite(WIRE_THREE, LOW);
  digitalWrite(WIRE_FOUR, LOW);
  digitalWrite(WIRE_TWO, HIGH);
  delay(5);
  digitalWrite(WIRE_ONE, LOW);
  digitalWrite(WIRE_TWO, LOW);
  digitalWrite(WIRE_FOUR, LOW);
  digitalWrite(WIRE_THREE, HIGH);
  delay(5);
  digitalWrite(WIRE_ONE, LOW);
  digitalWrite(WIRE_TWO, LOW);
  digitalWrite(WIRE_THREE, LOW);
  digitalWrite(WIRE_FOUR, HIGH);
  delay(5);
}
