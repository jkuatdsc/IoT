// libraries
// servo :: https://github.com/madhephaestus/ESP32Servo


#include <ESP32Servo.h>

// Servo
#define SERVO_PIN     16
#define LDR_Right_pin 34
#define LDR_Left_pin  35

# define ServoLimitHigh    160
# define ServoLimitLow      20

#define AllowedError        10

// create a servo instance
Servo myServo;
int servoh = 0;

void setup() {
    
  Serial.begin(115200); 

  // Allow allocation of all timer 
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  myServo.setPeriodHertz(50);    // standard 50 hz servo

  myServo.attach(SERVO_PIN, 500, 2500);  // attaches the servo on pin 16 to the servo object
  
  servoh = (ServoLimitHigh + ServoLimitLow) / 2;
  myServo.write(servoh);              // sets the servo position according to the scaled value
  delay(1000);
}

void loop{
  
   // Read LDR values
   int LDR_Right = map(analogRead(LDR_Right_pin), 0, 4095, 1023, 0);
   int LDR_Left = map(analogRead(LDR_Left_pin), 0, 4095, 1023, 0);


   // print the values out 
   Serial.print("LDR_Right: " + String(LDR_Right));
   Serial.print("LDR_Left: " + String(LDR_Left));


   // move to higher side
   if(LDR_Right > (LDR_Left + AllowedError)){
     
        servoh = servoh + 1;
        if (servoh > ServoLimitHigh) {
            servoh = ServoLimitHigh;
            Serial.println("Limit Reached");
        } else {
            myServo.write(servoh);
            Serial.println("Moving Right");
        }
   }

    // move to lower side
    if(LDR_Left > (LDR_Right + AllowedError)){
         
            servoh = servoh - 1;
            if (servoh < ServoLimitLow) {
                servoh = ServoLimitLow;
                Serial.println("Limit Reached");
            } else {
                myServo.write(servoh);
                Serial.println("Moving Left");
            }
    }

    delay(10);

}