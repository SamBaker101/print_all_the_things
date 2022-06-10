//Sam Baker - 05/23/2022
//Testing salvaged encoder for Epson linear rail with interrupt
//encoder currently only outputting one digital signal (so no directional iformation available)
//Using L298 motor controller for tests

//10cm approx 736 posedge

#define ENC_I 2

#define MOTOR_PWM 11
#define MOTOR_POS 10
#define MOTOR_NEG 9

#define BUTTON_NEG 6
#define BUTTON_POS 5

#define POS 1
#define NEG 0

//This is not suuuper accurate but will work for now
#define DMULTIPLIER 10.0/736

//At 12V only works at full output (100% duty cycle)
#define PWM_DUTY 100

//counts posedges from encoder
int enc_count = 0;
int last_enc_count = 0;

int motor_dir = 0;

//(cm)
float distance = 0.0;

void setup() {
  //Feedback
  Serial.begin(115200);

  //Motor Control
  pinMode(MOTOR_PWM, OUTPUT);
  pinMode(MOTOR_POS, OUTPUT);
  pinMode(MOTOR_NEG, OUTPUT);

  pinMode(BUTTON_POS, INPUT);
  pinMode(BUTTON_NEG, INPUT);
  
  //Input from encoder (Blue wire from carrage)
  pinMode(ENC_I, INPUT);
  attachInterrupt(0, enc_ISR, RISING);

  //set motor speed
  int set_duty = (255*PWM_DUTY)/100;
  analogWrite(MOTOR_PWM, set_duty);

  home_axis();
  }


void loop() {
  if (digitalRead(BUTTON_POS)){
    motor_dir = POS;
    digitalWrite(MOTOR_POS, HIGH);
    }
   else{
    digitalWrite(MOTOR_POS, LOW);
    }

  if (digitalRead(BUTTON_NEG)){
    motor_dir = NEG;
    digitalWrite(MOTOR_NEG, HIGH);
    }
   else{
    digitalWrite(MOTOR_NEG, LOW);
    }
  
  distance = enc_count * DMULTIPLIER;
  Serial.println(distance);
  delay(100);
  
}


//increment enc_counter when input from encoder goes high
void enc_ISR(){
  if(motor_dir == POS) enc_count ++;
  else if (motor_dir == NEG) enc_count --;
  }


void home_axis(){
  do{
    digitalWrite(MOTOR_NEG, HIGH);
    last_enc_count = enc_count;
    delay(2500);
    }while(last_enc_count != enc_count);
    
    digitalWrite(MOTOR_NEG, LOW);
    enc_count = 0;
  }  
