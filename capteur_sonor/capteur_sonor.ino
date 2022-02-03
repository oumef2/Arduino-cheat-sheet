
#define A0_pin A0 
#define D0_pin 13

#include
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0_pin,INPUT);
  pinMode(D0_pin,OUTPUT);
  digitalWrite(D0_pin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D0_pin,LOW);
  int noise = analogRead(A0_pin);
  int ValeurLED = map (noise, 0, 1023, 0, 255);
  Serial.println("read noise : ");
  Serial.println(noise);
  
}
