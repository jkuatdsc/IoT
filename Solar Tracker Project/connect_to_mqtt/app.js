var MQTT_CLIENT_ID = "iot_web_"+Math.floor((1 + Math.random()) * 0x10000000000).toString(16);
// Create a MQTT client instance
var MQTT_CLIENT = new Paho.MQTT.Client("broker.hivemq.com", 8000, "client1js");

// Tell the client instance to connect to the MQTT broker
MQTT_CLIENT.connect({ onSuccess: myClientConnected });


function myButtonWasClicked() {
    //alert("The button was clicked!")
    //select the tag with id="updateMe" and set its inner content
   $(".updateMe").text('The text is updated');

}

function myClientConnected() {
    MQTT_CLIENT.subscribe("test_topic/from_esp32");
  }

  // This is the function which handles received messages
function myMessageArrived(message) {
    // Get the payload
    var messageBody = message.payloadString;
  
    // Create a new HTML element wrapping the message payload
    var messageHTML = $("<p>"+messageBody+"</p>");
  
    // Insert it inside the ```id=updateMe``` element above everything else that is there 
    $(".updateMe").html(messageHTML);
  };
  
  // Tell MQTT_CLIENT to call myMessageArrived(message) each time a new message arrives
  MQTT_CLIENT.onMessageArrived = myMessageArrived;

  function publishToTopic() {
      //create a new MQTT Message with a specific payload
      var mqttMessage = new Paho.MQTT.Message('Hello from website');

      //set the topic it should be published to
      mqttMessage.destinationName = "From_Website_To_Esp_32/Test_1";

      //Publish the message
      MQTT_CLIENT.send(mqttMessage);
  }


  //This function handles "Turn LED on" button clicks
  function turnOnLED() {
      //create a new MQTT messagewith a specific payload
      var mqttMessage = new Paho.MQTT.Message('turn led on');

      //Set the tipic it should be published to
      mqttMessage.destinationName = "From_Website_To_Esp_32/Test_1";

      //publish the message
      MQTT_CLIENT.send(mqttMessage);


  }

  function turnOffLED() {
    //create a new MQTT messagewith a specific payload
    var mqttMessage = new Paho.MQTT.Message('turn led off');

    //Set the tipic it should be published to
    mqttMessage.destinationName = "From_Website_To_Esp_32/Test_1";

    //publish the message
    MQTT_CLIENT.send(mqttMessage);


}