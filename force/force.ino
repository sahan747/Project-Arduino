int fsrPin = 0;     // connect FSR to the A0 through 10k resistor
int fsrReading;     // These are variables
int buzzer = 10;

void setup(void) {
 
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(buzzer, OUTPUT); 
}
 
void loop(void) {
  fsrReading = analogRead(fsrPin);

  Serial.print("Analog reading = ");
  Serial.print(fsrReading);    
 
  delay(1000);
  
  Serial.println("");
} 
