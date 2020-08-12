// Device power cycling using Arduino Uno and 4-relay Module.
// This setup is for electrical testing and troubleshooting purposes.
// DUT - Device Under Test.

int relayPin1 = 5;            //Output to pin8 connected to relay IN1 pin
int relayPin2 = 6;            //Output to pin7 connected to relay IN2 pin
int relayPin3 = 7;            //Output to pin6 connected to relay IN3 pin
int relayPin4 = 8;            //Output to pin5 connected to relay IN4 pin
int counter = 0;              //Counter to count number of cycles.

void setup() {
  pinMode(relayPin1, OUTPUT);  //Define pin 5 as output
  pinMode(relayPin2, OUTPUT);  //Define pin 6 as output
  pinMode(relayPin3, OUTPUT);  //Define pin 7 as output
  pinMode(relayPin4, OUTPUT);  //Define pin 8 as output
  Serial.begin(9600);
}

void loop() {
  digitalWrite(relayPin1,LOW); // The pin is set LOW because the trigger on the relay is set to excite the relay at low condition.
  delay(100);                  // This can be changed as per users need like setting it to HIGH but make sure your trigger is also set to HIGH.
  digitalWrite(relayPin1,HIGH);
  delay(100);

 digitalWrite(relayPin2,LOW);
 delay(100);
 digitalWrite(relayPin2,HIGH);
 delay(100);

 digitalWrite(relayPin3,LOW);
 delay(100);
 digitalWrite(relayPin3,HIGH);
 delay(100);
 
 digitalWrite(relayPin4,LOW);
 delay(40000);                // This is my custom setting you can have your own values.
 digitalWrite(relayPin4,HIGH);
 delay(20000);
 counter = counter+1;         // Counter to count number of cycles the DUT turns ON/OFF. 
    if (counter==3000){       // Here the counter is set to count till 3000 cycles and turn off the DUT for 166.66665mins or 2.778Hrs. 
    digitalWrite(relayPin4,HIGH);
    counter = 0;
    delay(9999999);           // This the delay time or how long the DUT will stay turned OFF i.e 166.66665mins or 2.778Hrs.
      
    }                         // This is custom setting you can have your own values.
 Serial.println(counter);     // This will display the cycle count onto the serial monitor.
}
