

#include <WiFi.h>
WiFiClient WIFI_CLIENT;
#include <PubSubClient.h>
PubSubClient MQTT_CLIENT;
String wifiPwd = "****";
String wifiName = "****";

int LED_PIN = 2;
//This function handles received messages
void myMessageArrived(char* topic, byte* payload, unsigned int length)
{
  //Converte the message payload from bytes to a string
  String message = "";
  for (unsigned int i=0; i<length; i++) 
  {
    message = message + (char)payload[i];
  }

  //Print the message to the serial port
  Serial.println(message);

  //Check if message is turn led on
  if (message == "turn led on")
  {
    //TURN LED ON
    digitalWrite (LED_PIN, HIGH);
    Serial.println("led on");
  }

 //Check if message is "turn led off"
 if(message == "turn led off"){
  //TURN THE LED OFF
  digitalWrite(LED_PIN, LOW);
   Serial.println("led off");
 }
}


//This function connects to the MQTT broker
void reconnect(){
//set our MQTT broker address and port
MQTT_CLIENT.setServer("broker.hivemq.com",1883);
MQTT_CLIENT.setClient(WIFI_CLIENT);
 //MQTT_CLIENT.setCallback(mqttCallback);

//Loop until we are connected

while (!MQTT_CLIENT.connected()){
  //Attempt to connect
  Serial.println("Attempt to connect to MQTT broker");
  MQTT_CLIENT.connect("esp32_1234");
  //mqttClient.connect("ESP8266Client", mqttUser, mqttPassword )

  //Wait some time to space out connection requests
  delay(3000);
   
}

Serial.println("MQTT connected");

//Subscribe to the topic where our web page is publishing messages
MQTT_CLIENT.subscribe("From_Website_To_Esp_32/Test_1");

//set the message received callback
 MQTT_CLIENT.setCallback(myMessageArrived);
 
}

void setup() {
 Serial.begin(115200);
  WiFi.begin(wifiName, wifiPwd);
// Keep checking the connection status until it is connected
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
  }

  // Print the IP address of your module
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  // Check if we are connected to the MQTT broker
  if (!MQTT_CLIENT.connected()) {
//If we are not, attempt to reconnect
reconnect();
}

//Publish a message to a topic
//MQTT_CLIENT.publish("test_topic/from_esp32", "Hello world");
//Wait five seconds
//delay(5000);

//Check for incoming MQTT messages

#include <WiFi.h>
WiFiClient WIFI_CLIENT;
#include <PubSubClient.h>
PubSubClient MQTT_CLIENT;
String wifiPwd = "****";
String wifiName = "****";

int LED_PIN = 2;
//This function handles received messages
void myMessageArrived(char* topic, byte* payload, unsigned int length)
{
  //Converte the message payload from bytes to a string
  String message = "";
  for (unsigned int i=0; i<length; i++) 
  {
    message = message + (char)payload[i];
  }

  //Print the message to the serial port
  Serial.println(message);

  //Check if message is turn led on
  if (message == "turn led on")
  {
    //TURN LED ON
    digitalWrite (LED_PIN, HIGH);
    Serial.println("led on");
  }

 //Check if message is "turn led off"
 if(message == "turn led off"){
  //TURN THE LED OFF
  digitalWrite(LED_PIN, LOW);
   Serial.println("led off");
 }
}


//This function connects to the MQTT broker
void reconnect(){
//set our MQTT broker address and port
MQTT_CLIENT.setServer("broker.hivemq.com",1883);
MQTT_CLIENT.setClient(WIFI_CLIENT);
 //MQTT_CLIENT.setCallback(mqttCallback);

//Loop until we are connected

while (!MQTT_CLIENT.connected()){
  //Attempt to connect
  Serial.println("Attempt to connect to MQTT broker");
  MQTT_CLIENT.connect("esp32_1234");
  //mqttClient.connect("ESP8266Client", mqttUser, mqttPassword )

  //Wait some time to space out connection requests
  delay(3000);
   
}

Serial.println("MQTT connected");

//Subscribe to the topic where our web page is publishing messages
MQTT_CLIENT.subscribe("From_Website_To_Esp_32/Test_1");

//set the message received callback
 MQTT_CLIENT.setCallback(myMessageArrived);
 
}

void setup() {
 Serial.begin(115200);
  WiFi.begin(wifiName, wifiPwd);
// Keep checking the connection status until it is connected
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
  }

  // Print the IP address of your module
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  // Check if we are connected to the MQTT broker
  if (!MQTT_CLIENT.connected()) {
//If we are not, attempt to reconnect
reconnect();
}

//Publish a message to a topic
//MQTT_CLIENT.publish("test_topic/from_esp32", "Hello world");
//Wait five seconds
//delay(5000);

//Check for incoming MQTT messages
MQTT_CLIENT.loop();

}
