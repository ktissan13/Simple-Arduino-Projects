// Project 6 - Interactive LED Chase Effect
// Create Array for LED pins
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // this is a array which converts the variable in the curly brackets into index number which then can be called throughout the program
int ledDelay(65); // Delay Between changes of lights 
int direction = 1; // the direction the light travels
int currentLED = 0; // the led that is currently turned on 
unsigned long changeTime;
int potPin = 2; // select the input pin for the potentiometer 

void setup() {
  // set all pins to output 
  // loop to tell the ardiuno which led needs to be turned on 
  for (int x=0; x<10; x++) {
    // X led is on 
    pinMode(ledPin[x], OUTPUT); }
    changeTime = millis();
}

void loop() {
  // read the value from the pot
  ledDelay = analogRead(potPin);
  // if it has been ledDelay ms since last change 
  // tells the ardiuno when to call the changeLED function 
  if ((millis() - changeTime) > ledDelay) {
    // call the changeLED function
    changeLED();
    changeTime = millis();
  }
}  

// changeLED Function 
void changeLED() {
  // turn off all LED's 
  for(int x=0; x<10; x++) {
    digitalWrite(ledPin[x], LOW);
  }
  // turn on the current LED
  digitalWrite(ledPin[currentLED], HIGH);
  // increment by the direction value 
  currentLED += direction;
  // change direction if we reach the end 
  if (currentLED == 9) {direction = -1;}
  if (currentLED == 0) {direction = 1;} 
}
    
