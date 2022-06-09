//Sam Baker - 05/23/2022
//Testing salvaged encoder for Epson linear rail with interrupt
//encoder currently only outputting one digital signal (so no directional iformation available)
//Using L298 motor controller for tests

//10cm approx 736 posedge

#define ENC_I 2

#define MOTOR_PWM 11
#define MOTOR_POS 10
#define MOTOR_NEG 9

//This is not suuuper accurate but will work for now
#define DMULTIPLIER 10.0/736

#define PWM_DUTY 100

//counts posedges from encoder
int enc_count = 0;
int last_enc_count = 0;

//(cm)
float distance = 0.0;

void setup() {
  //Feedback
  Serial.begin(115200);

  //Motor Control
  pinMode(MOTOR_PWM, OUTPUT);
  pinMode(MOTOR_POS, OUTPUT);
  pinMode(MOTOR_NEG, OUTPUT);
  
  //Input from encoder (Blue wire from carrage)
  pinMode(ENC_I, INPUT);
  attachInterrupt(0, enc_ISR, RISING);

  //set motor speed
  int set_duty = (255*PWM_DUTY)/100;
  analogWrite(MOTOR_PWM, set_duty);

  home_axis();
  }


void loop() {
  distance = enc_count * DMULTIPLIER;
  Serial.println(distance);
  delay(100);

  digitalWrite(MOTOR_NEG, HIGH);
}


//increment enc_counter when input from encoder goes high
void enc_ISR(){
  enc_count ++;
  }


void home_axis(){
  do{
    digitalWrite(MOTOR_NEG, HIGH);
    last_enc_count = enc_count;
    delay(5);
    }while(last_enc_count != enc_count);

    digitalWrite(MOTOR_NEG, LOW);
  }  
