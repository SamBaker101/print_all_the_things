//Sam Baker - 05/23/2022
//Motor test code for Arduino using L298 motor controller and salvaged DC motors

#define YDUTY 100
#define XDUTY 60

#define XPOS 5
#define XNEG 4

#define YPOS 6
#define YNEG 7

void setup() {
  //Feedback
  Serial.begin(115200);
  
  //Motor Control to L298 motor controller
  pinMode(YPOS, OUTPUT);
  pinMode(YNEG, OUTPUT);
  pinMode(XPOS, OUTPUT);
  pinMode(XNEG, OUTPUT);

  //PWM outputs
  int set_y_duty = (255*YDUTY)/100;
  int set_x_duty = (255*XDUTY)/100;
  
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  analogWrite(11, set_y_duty);
  analogWrite(10, set_x_duty);
  
  //User Inputs
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
}

void loop() {
  digitalWrite(7, digitalRead(3));
  digitalWrite(6, digitalRead(2));
  digitalWrite(XPOS, digitalRead(8));
  digitalWrite(XNEG, digitalRead(9));

  delay(1);
}
