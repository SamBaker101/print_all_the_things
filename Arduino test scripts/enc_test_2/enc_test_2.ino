//Sam Baker - 05/23/2022
//Testing Epson linear rail with DC motor and encoder
//encoder currently only outputting one digital signal (so no directional iformation available)
//Using L298 motor controller for tests

#define ENC_I 6

void setup() {
  //Feedback
  Serial.begin(115200);
  
  //Input from encoder (Blue wire from carrage)
  pinMode(ENC_I, INPUT);
  int enc_state = 0;

  //counts posedges from encoder
  int enc_count = 0;
  }


void loop() {

  Serial.println(enc_count);
  
  delay(1);
}


//increment enc_counter when input from encoder goes high
void pin_ISR(){
  enc_state = digitalRead(ENC_I);
  if (enc_state = 1) enc_counter ++;
  }
