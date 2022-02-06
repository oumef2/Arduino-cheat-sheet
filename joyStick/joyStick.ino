#define JOYSTICKSW 4
#define JOYSTICKX A0
#define JOYSTICKY A1

//joystick structure
typedef struct {
  int x = 0;
  int y = 0;
  bool clicked = false;
}joy_stick;

joy_stick js;
int X,Y;
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
 
   pinMode(JOYSTICKX, INPUT);
   pinMode(JOYSTICKY, INPUT);
   pinMode(JOYSTICKSW, INPUT);
   //calibrate initial position to (0,0)
   X = analogRead(JOYSTICKX);
   Y = analogRead(JOYSTICKY);
}

void loop() {
  // put your main code here, to run repeatedly:
  //the valuse are between 0 and 1023
  js.x = analogRead(JOYSTICKX);
  // values between -100 and 100 
  js.x = js.x -(X-512);
  if (js.x<0) js.x =0;
  else if (js.x>1023) js.x = 1023;
  js.x = map(js.x, 0, 1023, -100 , 100);
  
  js.y= analogRead(JOYSTICKY);
  js.y = js.y -(Y-512);
  if (js.y<0) js.y =0;
  else if (js.y>1023) js.y = 1023;
  js.y = map(js.y, 0, 1023, -100, 100);
  S
  js.clicked = digitalRead(JOYSTICKSW);
  
  if (js.clicked) Serial.println("clicked");
  
  Serial.print("X= ");
  Serial.println(js.x);
  
  Serial.print("Y= ");
  Serial.println(js.y);
  
  delay(500);
 
}
