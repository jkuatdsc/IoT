import RPi.GPIO as GPIO
import time #to delay your LED

#Set up your pins to use board numbering
GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

yelLedPin = 12 #GPIO 18
redlLedPin = 16 #GPIO 23

#Set pin 12 and 16(GPIO 18 and 23) as both power and output, set initial value as low(Off)
GPIO.setup(yelLedPin, GPIO.OUT, initial = GPIO.LOW)
#GPIO.setup(redlLedPin, GPIO.OUT, initial = GPIO.LOW)

"""These two functions are set to blink 2 LEDS simultaneously but only one works"""
#Flashing
def flashYllw():
    while True: #Run forever
        print("Turning on")
        GPIO.output(yelLedPin, GPIO.HIGH)
        time.sleep(0.09)
        print("Going Off")
        GPIO.output(yelLedPin, GPIO.LOW)
        time.sleep(0.09)
    
def flashRed():
    while True: #Run forever
        print("Turning on")
        GPIO.output(redlLedPin, GPIO.HIGH)
        time.sleep(0.5)
        print("Going Off")
        GPIO.output(redlLedPin, GPIO.LOW)
        time.sleep(0.5)
 
flashYllw()  
flashRed()
