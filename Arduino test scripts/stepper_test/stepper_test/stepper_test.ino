//Sam Baker - 05/23/2022
//Naive test for salvaged stepper from Epson scanner bed
//This exists primarily to find out the wiring/coil order of unmarked stepper

#define WIRE_ONE 6
#define WIRE_TWO 5
#define WIRE_THREE 4
#define WIRE_FOUR 3

#define BUTTON 2

//Coil states
int state = 0;


void setup() {
  pinMode(WIRE_ONE, OUTPUT);
  pinMode(WIRE_TWO, OUTPUT);
  pinMode(WIRE_THREE, OUTPUT);
  pinMode(WIRE_FOUR, OUTPUT);

  pinMode(BUTTON, INPUT);

  attachInterrupt(digitalPinToInterrupt(BUTTON), button_ISR, RISING);
}

void loop() {
  if (state == 0){
    digitalWrite(WIRE_TWO, LOW);
    digitalWrite(WIRE_THREE, LOW);
    digitalWrite(WIRE_FOUR, LOW);
    digitalWrite(WIRE_ONE, HIGH);
    }

  else if (state == 1){
    digitalWrite(WIRE_ONE, LOW);
    digitalWrite(WIRE_THREE, LOW);
    digitalWrite(WIRE_FOUR, LOW);
    digitalWrite(WIRE_TWO, HIGH);
    }

  else if (state == 2){ 
    digitalWrite(WIRE_ONE, LOW);
    digitalWrite(WIRE_TWO, LOW);
    digitalWrite(WIRE_FOUR, LOW);
    digitalWrite(WIRE_THREE, HIGH);
    }

  else if (state == 3){
    digitalWrite(WIRE_ONE, LOW);
    digitalWrite(WIRE_TWO, LOW);
    digitalWrite(WIRE_THREE, LOW);
    digitalWrite(WIRE_FOUR, HIGH);
    }
}

void button_ISR(){
  state = (state+1)%2;
  }
