//>5V Motor Start/Stop and Speed Control

int ControlPin = 6;   //give your arduino pin a name
void setup() { // the setup routine runs once when you reset the Arduino:
  
  pinMode(ControlPin, OUTPUT); // initialize the digital pin as an output.
  
  Serial.begin(9600);          //setup the serial monitor for viewing the active PWM control value
}

void loop() { // the loop routine runs over and over again forever:
  
 //Start/Stop Control
  digitalWrite(ControlPin, HIGH); // turn the motor on by making the voltage HIGH
  delay(5000);                    // wait for time seconds/1000
  digitalWrite(ControlPin, LOW);  // turn the motor off by making the voltge LOW
  delay(5000);                    // wait for time seconds/1000

 // Speed Control
 // reduce motor speed from max to min in increments of 5 points PWM:
  for (int speedPWM = 255 ; speedPWM >= 0; speedPWM -= 5) { // sets the PWM range from 255 to 0
    analogWrite(ControlPin, speedPWM);                      // writes speedPWM to the motor control pin, arduino pin 3
    Serial.println(speedPWM);                               // prints the fade value to the serial monitor to allow you to find minimum 0 load run speed 
    delay(1000);
  }

  // increase motor speed from min to max in increments of 5 points PWM:
  for (int speedPWM = 0 ; speedPWM <= 255; speedPWM += 5) {
    analogWrite(ControlPin, speedPWM);
    Serial.println(speedPWM);
    delay(1000);
  }
}
