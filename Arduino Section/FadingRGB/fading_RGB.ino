int redPin= 11;
int greenPin =10;
int bluePin= 9;


//vars to hold the led color
int red=255;
int blue= 127;
int green=0;

//var to change the direction
int redDir=-1;
int greenDir=1;
int blueDir=-1;

void setup() {
  // put your setup code here, to run once:
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(redPin, red);
analogWrite(greenPin, green);
analogWrite(bluePin, blue);

//to change the LED values
 red+=redDir;
 green+=greenDir;
 blue+=blueDir;

//for the color to change the direction oce it reaches 0 or 255
if(red>=255 || red<=0){
 redDir*=-1;}

 if(green>=255 || green<=0){
  greenDir*=-1;}
  if(blue>=255 || blue<=0){
    blueDir*=-1;
}
delay(40);

}
