#include <Arduino.h>

class BetterServo{
  private:
    int pin = 8;
    char inpt_mode = 'a';
    int min_pwm = 316;
    int max_pwm = 2594;
    int lower_limit;
    int upper_limit;
    
  public:
    int frequency = 50;
    
    void config_pin(int input){
      pin = input;
      pinMode(pin, OUTPUT);
    }
    void mode(char input){
      if(input != 'a' && input != 'd' && input != 'r'){
        Serial.println("possible modes are: 'a' analog, 'd' degree, 'r' radiants");
      }
      else{
        inpt_mode = input;
      }
    }
    void conf(int input1 = 316, int input2 = 2594){
      min_pwm = input1;
      max_pwm = input2;
    }
    void limit(int input1 = 0, int input2 = 180){
      lower_limit = input1;
      upper_limit = input2;
    }
    void rotation(float input){
      float duration;
      float pi = 3.14159265359;
      switch(inpt_mode){
        case 'a':
            if((input * 180 / 1023) >= lower_limit && (input * 180 / 1023) <= upper_limit){
                duration = ((input * (max_pwm - min_pwm)) / 1023) + min_pwm;
            }
            break;
        case 'd':
            if(input >= lower_limit && input <= upper_limit){
                duration = (input * (max_pwm - min_pwm / 180)) + min_pwm;
            }
            break;
        case 'r':
            if((input * 180 / pi) >= lower_limit && (input * 180 / pi) <= upper_limit){
                duration = (input * (max_pwm - min_pwm / pi)) + min_pwm;
            }
            break;
        default: Serial.println("Error 1");
      }
      digitalWrite(pin, HIGH);
      delayMicroseconds(duration);
      digitalWrite(pin, LOW);
      delayMicroseconds((1000000 / frequency) - duration);
    }
};
