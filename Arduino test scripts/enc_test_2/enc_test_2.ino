//Sam Baker - 05/23/2022
//Testing salvaged encoder for Epson linear rail with interrupt
//encoder currently only outputting one digital signal (so no directional iformation available)
//Using L298 motor controller for tests

//10cm approx 736 posedge

#define ENC_I 2

//This is not suuuper accurate but will work for now
#define DMULTIPLIER 10.0/736

//counts posedges from encoder
int enc_count = 0;

//(cm)
float distance = 0.0;

void setup() {
  //Feedback
  Serial.begin(115200);
  
  //Input from encoder (Blue wire from carrage)
  pinMode(ENC_I, INPUT);
  attachInterrupt(0, enc_ISR, RISING);
  }


void loop() {
  distance = enc_count * DMULTIPLIER;
  Serial.println(distance);
  delay(100);
}


//increment enc_counter when input from encoder goes high
void enc_ISR(){
  enc_count ++;
  }
