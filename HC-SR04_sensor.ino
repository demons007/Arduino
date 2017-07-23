/*HC-SR04 - Ultrasonic Sensor
 VCC to Arduino 5V
 GND to Arduino GND
 Echo (or OUTPUT) to Arduino pin D2
 Trig (or INPUT) to Arduino pin D3
 LED D5 pin */
#define echoPin 2 // Echo Pin (OUTPUT pin in HC-SR04)
#define trigPin 3 // Trigger Pin (INPUT pin in HC-SR04)

int led = 5;
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(led, OUTPUT);
}

void loop() {
// The following trigPin/echoPin cycle is used to determine the distance of the nearest object by bouncing soundwaves off of it.
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = duration/58.2; //Calculate the distance (in cm) based on the speed of sound.
 digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
 delay(distance);          // wait for a distance number
 digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
 delay(distance);
   
 delay(30); //Delay 30 ms
}