#define USE_ARDUINO_INTERRUPTS true // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h> // Includes the PulseSensorPlayground Library.

 
const int PulseWire = 0; // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
int Threshold = 550; // Determine which Signal to "count as a beat" and which to ignore.
// Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
// Otherwise leave the default "550" value.
 
PulseSensorPlayground pulseSensor;

void setup() {
 
Serial.begin(9600);

pulseSensor.analogInput(PulseWire);

pulseSensor.setThreshold(Threshold);
 
if (pulseSensor.begin()) {
Serial.println("We created a pulseSensor Object !"); //This prints one time at Arduino power-up, or on Arduino reset.
}
}
 
void loop() {
 
int myBPM = pulseSensor.getBeatsPerMinute(); // Calls function on our pulseSensor object that returns BPM as an "int".
// "myBPM" hold this BPM value now.
if (pulseSensor.sawStartOfBeat()) { // Constantly test to see if "a beat happened".
Serial.println("♥ A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
Serial.print("BPM: "); // Print phrase "BPM: "
Serial.println(myBPM); // Print the value inside of myBPM.

}
delay(1000); // considered best practice in a simple sketch.
}
