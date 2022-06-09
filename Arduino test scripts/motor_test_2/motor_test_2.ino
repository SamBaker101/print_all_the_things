//Sam Baker - 05/23/2022
//Testing Salvaged Encoder
//Blue gives expected encoder output, yellow appears to always be high
//Unclear if yellow is damaged or this is usual operation

#define YELLOW_WIRE 7
#define BLUE_WIRE 6

  struct wires{
    int yellow;
    int blue;
    }; 

void setup() {
  //Feedback
  Serial.begin(115200);
  
  //Unidentified Encoder Outputs
  pinMode(YELLOW_WIRE, INPUT);
  pinMode(BLUE_WIRE, INPUT);
  }


void loop() {
  wires test_wires = {0, 0};  
  
  test_wires.yellow = digitalRead(YELLOW_WIRE);
  test_wires.blue = digitalRead(BLUE_WIRE);

  //Serial.println(test_wires.yellow);
  Serial.println(test_wires.blue);
  
  delay(1);
}
