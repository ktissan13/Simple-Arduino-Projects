//Project 14 - Light Sensor
// Pin we will connect to LED
int ledPin = 6;
// Pin connected to LDR
int ldrPin = 0;
// Value read from LDR
int lightVal = 0;
void setup()
{
  // Set both pins as outputs
  pinMode(ledPin, OUTPUT);
}
void loop()
{
  // Read in value from LDR
  lightVal = analogRead(ldrPin);
  // Turn LED on
  digitalWrite(ledPin, HIGH);
  // Delay of length lightVal
  delay(lightVal);
  // Turn LED off
  digitalWrite(ledPin, LOW);
  // Delay again
  delay(lightVal);
}
