//Sam Baker - 05/23/2022
//Motor test code for Arduino using L298 motor controller and salvaged DC motors

#define DUTY 90

void setup() {
  //Feedback
  Serial.begin(115200);
  
  //Motor Control to L298 motor controller
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);

  //PWM outputs
  int set_duty = (255*DUTY)/100;
  
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  analogWrite(11, set_duty);
  analogWrite(10, set_duty);
  
  //User Inputs
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
}

void loop() {
  int test = digitalRead(2);
  digitalWrite(7, digitalRead(3));
  digitalWrite(6, test);
  digitalWrite(5, digitalRead(8));
  digitalWrite(4, digitalRead(9));

  Serial.println(test, DEC);

  delay(1);
}
