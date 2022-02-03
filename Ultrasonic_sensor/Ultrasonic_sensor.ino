#define TRIG 11
#define ECHO 12
#define SOUNDVELOCITY 344.0/1000  //m/s

float LireDistance();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  digitalWrite(TRIG,LOW);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
  int duree = pulseIn(ECHO,HIGH,25000UL);
  float dist = SOUNDVELOCITY*duree/2;
  Serial.println("La distance est :");
  Serial.println(dist/10.0);
  delay(200);

}
float LireDistance(){
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
  int duree = pulseIn(ECHO,HIGH,25000UL);
  float dist = SOUNDVELOCITY*duree/2;
  Serial.println("La distance est :");
  return dist/10.0;
  }
