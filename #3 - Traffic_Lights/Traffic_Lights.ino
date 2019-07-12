//Project 3 - Traffic Lights 

int ledDelay = 10000; // delay in between changes 
int redPin = 10; 
int yellowPin = 9;
int greenPin = 8; 

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT); 
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // turn the red light on
  digitalWrite(redPin, HIGH);
  delay(ledDelay); // wait 5 seconds

  digitalWrite(yellowPin, HIGH); // turn on yellow
  delay(2000); // wait 2 seconds 

  digitalWrite(greenPin, HIGH); // turn green on
  digitalWrite(redPin, LOW); // turn red off
  digitalWrite(yellowPin, LOW); // turn yellow off 
  delay(ledDelay); // wait ledDelay milliseconds

  digitalWrite(yellowPin, HIGH); // turn yellow on
  digitalWrite(greenPin, LOW); // turn green off
  delay(2000); // wait 2 seconds 

  digitalWrite(yellowPin, LOW); // turn yellow off
  // now our loop repeats
}
