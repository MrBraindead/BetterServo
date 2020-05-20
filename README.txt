--functions--

- config_pin(<pin number>) 
	Configures the pin, the Servo is connected to.
- mode(<input type>) 
	Configures which input the function takes. 
	('a' for analog, 'd' for degrees, 'r' for radiants) 
	(the inputmode is 'a' by default)
- conf(<minimum pulsewidth>, <maximum pulsewidth>) 
	Configures range of pulsewidths the servo uses.
	(enter pulswidth in microseconds) 
	(leave as it is, exept your Servo doesn't has the expected range)
- limit(<lower limit>, <upper limit>) 
	Configure the maximum range the servo can move. 
	Value has to be in degrees. 
	(default is 0° to 180°) 
	(this requires the range of pulsewidths to be configured properly)
- rotation(<rotation>) 
	Creates a PWM-Signal at the pin. 

--example code--

#include <BetterServo.h>

const int potpin = 0;
const int servopin = 9;
int rot;   
BetterServo myServo;

void setup() {
  myServo.config_pin(servopin);
  myServo.mode('a');        //not needed in this example
  myServo.conf(300, 2600);  //not needed in this example
  myServo.limit(0,180);     //not needed in this example
}

void loop() {
  rot = analogRead(potpin);
  myServo.rotation(rot);
}

--more information--

https://github.com/MrBraindead/BetterServo/wiki
