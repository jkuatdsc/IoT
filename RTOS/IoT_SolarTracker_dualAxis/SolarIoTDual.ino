// libraries
// servo :: https://github.com/madhephaestus/ESP32Servo


#include <ESP32Servo.h>

// Servo
#define SERVO_PIN_P     16
#define SERVO_PIN_T     14

#define LDR_UP_Right_pin   34
#define LDR_UP_Left_pin    35
#define LDR_DOWN_Right_pin 33
#define LDR_DOWN_Left_pin  32


# define ServoLimitHigh    160
# define ServoLimitLow      20

#define AllowedError        10

// create a servo instance
Servo myServo_P;
int servo_p = 0;


Servo myServo_T;
int servo_t = 0;

void setup() {
    
  Serial.begin(115200); 

  // Allow allocation of all timer 
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  // pan servo(LEFT-RIGHT)
  myServo_P.setPeriodHertz(50);    // standard 50 hz servo

  myServo_P.attach(SERVO_PIN_P, 500, 2500);  // attaches the servo on pin 16 to the servo object
  
  servo_p = (ServoLimitHigh + ServoLimitLow) / 2;
  myServo.write(servo_p);              // sets the servo position according to the scaled value
  delay(1000);


  // tilt servo(UP-DOWN)
  myServo_T.setPeriodHertz(50);    // standard 50 hz servo

  myServo_T.attach(SERVO_PIN_T, 500, 2500);  // attaches the servo on pin 16 to the servo object
  
  servo_t = (ServoLimitHigh + ServoLimitLow) / 2;
  myServo.write(servo_t);              // sets the servo position according to the scaled value
  delay(1000);


}

void loop{
  
   // Read LDR values
   int LDR_Right1 = map(analogRead(LDR_UP_Right_pin), 0, 4095, 1023, 0);
   int LDR_Left1 = map(analogRead(LDR_UP_Left_pin), 0, 4095, 1023, 0);
   int LDR_Right2 = map(analogRead(LDR_DOWN_Right_pin), 0, 4095, 1023, 0);
   int LDR_Left2 = map(analogRead(LDR_DOWN_Left_pin), 0, 4095, 1023, 0);

   int LDR_Top   = (LDR_Right1 + LDR_Left1)/2;
   int LDR_Bottom= (LDR_Right2 + LDR_Left2)/2;

   int LDR_Right = (LDR_Right1  + LDR_Right2)/2;
   int LDR_Left  = (LDR_Left1 + LDR_Left2)/2 ;
   
   // print the values out 
   Serial.print("LDR_Top: " + String(LDR_Top));
   Serial.print("LDR_Bottom: " + String(LDR_Bottom));

   Serial.print("LDR_Right: " + String(LDR_Right));
   Serial.print("LDR_Left: " + String(LDR_Left));

   // move to higher side
   if(LDR_Right > (LDR_Left + AllowedError)){
     
        servo_p = servo_p + 1;
        if (servo_p > ServoLimitHigh) {
            servo_p = ServoLimitHigh;
            Serial.println("Limit Reached");
        } else {
            myServo.write(servo_p);
            Serial.println("Moving Right");
        }
   }

    // move to lower side
    if(LDR_Left > (LDR_Right + AllowedError)){
         
            servo_p = servo_p - 1;
            if (servo_p < ServoLimitLow) {
                servo_p = ServoLimitLow;
                Serial.println("Limit Reached");
            } else {
                myServo.write(servo_p);
                Serial.println("Moving Left");
            }
    }


   // move to higher side 
    if(LDR_Top > (LDR_Bottom + AllowedError)){
      
            servo_t = servo_t + 1;
            if (servo_t > ServoLimitHigh) {
                servo_t = ServoLimitHigh;
                Serial.println("Limit Reached");
            } else {
                myServo.write(servo_t);
                Serial.println("Moving Up");
            }
    }

    // move to lower side
    if(LDR_Bottom > (LDR_Top + AllowedError)){
         
            servo_t = servo_t - 1;
            if (servo_t < ServoLimitLow) {
                servo_t = ServoLimitLow;
                Serial.println("Limit Reached");
            } else {
                myServo.write(servo_t);
                Serial.println("Moving Down");
            }
    }

    delay(10);

}