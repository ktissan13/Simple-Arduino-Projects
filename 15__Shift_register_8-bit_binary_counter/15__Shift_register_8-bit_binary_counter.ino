// Project 15
//Pin connected to Pin 12 of 74HC595 (Latch)
int latchPin = 8;
//Pin connected to Pin 11 of 74HC595 (Clock)
int clockPin = 12;
//Pin connected to Pin 14 of 74HC595 (Data)
int dataPin = 11;
void setup() {
//set pins to output
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
}
void loop() {
//count from 0 to 255
for (int i = 0; i < 256; i++) {
//set latchPin low to allow data flow
digitalWrite(latchPin, LOW);
shiftOut(i);
//set latchPin to high to lock and send data
digitalWrite(latchPin, HIGH);
delay(500);
}
}
void shiftOut(byte dataOut) {
// Shift out 8 bits LSB first,
// on rising edge of clock
boolean pinState;
//clear shift register ready for sending data
digitalWrite(dataPin, LOW);
digitalWrite(clockPin, LOW);
// for each bit in dataOut send out a bit
for (int i=0; i<=7; i++) {
//set clockPin to LOW prior to sending bit
digitalWrite(clockPin, LOW);
// if the value of DataOut and (logical AND) a bitmask
// are true, set pinState to 1 (HIGH)
if ( dataOut & (1<<i) ) {
pinState = HIGH;
}
else {
pinState = LOW;
}
//sets dataPin to HIGH or LOW depending on pinState
digitalWrite(dataPin, pinState);
//send bit out on rising edge of clock
digitalWrite(clockPin, HIGH);
}
//stop shifting out data
digitalWrite(clockPin, LOW);
}
