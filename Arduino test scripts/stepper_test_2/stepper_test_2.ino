//Sam Baker - 05/23/2022
//Testing H-Bridge based motor driver
//https://www.ti.com/document-viewer/SN754410/datasheet

//Using this circuit
//https://www.hobbytronics.co.uk/stepper-motor-sn754410

//Step order YELLOW, ORANGE, BROWN, BLACK
// 50 Steps per Revolution

//This thing is pretty rough, quad stepping is probably a good idea



#include <Stepper.h>

#define BUTTON 2

#define YELLOW 11
#define ORANGE 9
#define BROWN 8
#define BLACK 10


int spin = 1;

const int stepsPerRevolution = 50; 

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 11, 9, 8, 10);            

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(1);

  pinMode(BUTTON, INPUT);

  attachInterrupt(digitalPinToInterrupt(BUTTON), button_ISR, RISING);

}

void loop() {
  if (spin){
    myStepper.step(stepsPerRevolution);
    delay(500);
  }

  //myStepper.step(-stepsPerRevolution);
  //delay(500); 
}


void button_ISR(){
  spin = !spin;
  }
