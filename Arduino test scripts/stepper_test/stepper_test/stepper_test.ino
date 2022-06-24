//Sam Baker - 05/23/2022
//Naive test for salvaged stepper from Epson scanner bed
//This exists primarily to find out the wiring/coil order of unmarked stepper

//COIL 1 ORANGE -> BROWN?
//COIL 2 YELLOW -> BLACK?

//Cycling ORANGE -> YELLOW -> ORANGE -> YELLOW  --  Rotates counter clockwise
//Cycling BROWN -> BLACK -> BROWN -> BLACK -- Rotates clockwise
//These are very weak/shaky (5v, low current and incomplete stepping)





//Switch to turn off manual stepping (button press)
//#define DEF_BUTTON 1
#define DEF_BUTTON 0

#define WIRE_ONE 6          //ORANGE
#define WIRE_TWO 5          //YELLOW
#define WIRE_THREE 4        //BROWN
#define WIRE_FOUR 3         //BLACK

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
  if (state == 1){
    digitalWrite(WIRE_TWO, LOW);
    digitalWrite(WIRE_THREE, LOW);
    digitalWrite(WIRE_FOUR, LOW);
    digitalWrite(WIRE_ONE, HIGH);
    }

  else if (state == 0){
    digitalWrite(WIRE_ONE, LOW);
    digitalWrite(WIRE_THREE, LOW);
    digitalWrite(WIRE_FOUR, LOW);
    digitalWrite(WIRE_TWO, HIGH);
    }

  else if (state == -1){ 
    digitalWrite(WIRE_ONE, LOW);
    digitalWrite(WIRE_TWO, LOW);
    digitalWrite(WIRE_FOUR, LOW);
    digitalWrite(WIRE_THREE, HIGH);
    }

  else if (state == -1){
    digitalWrite(WIRE_ONE, LOW);
    digitalWrite(WIRE_TWO, LOW);
    digitalWrite(WIRE_THREE, LOW);
    digitalWrite(WIRE_FOUR, HIGH);
    }

  if (!DEF_BUTTON){
    state = (state + 1) % 2;
    delay(25);
    }
}

void button_ISR(){
  if (DEF_BUTTON){
    state = (state+1)%2;
    }
  }
