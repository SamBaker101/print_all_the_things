//Sam Baker - 05/23/2022
//Testing Epson linear rail with DC motor and encoder
//encoder currently only outputting one digital signal (so no directional iformation available)
//Using L298 motor controller for tests

#define ENC_I 2

//counts posedges from encoder
int enc_count = 0;

void setup() {
  //Feedback
  Serial.begin(115200);
  
  //Input from encoder (Blue wire from carrage)
  pinMode(ENC_I, INPUT);
  attachInterrupt(0, enc_ISR, RISING);
  }


void loop() {
  Serial.println(enc_count);
  delay(100);
}


//increment enc_counter when input from encoder goes high
void enc_ISR(){
  enc_count ++;
  }
