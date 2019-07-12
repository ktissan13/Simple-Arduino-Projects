// Project 10 - Serial Controlled RGB Lamp

char buffer[18]; // set array to hold 18 characters. It only uses 16 but we have 18 so we don't run into errors
int red, green, blue; // intialiazes red, green, blue as integers to hold integer values for the digital pins

int RedPin = 11; // an intger for which pin to use RED, GREEN, BLUE LED 
int GreenPin = 10;
int BluePin = 9;

void setup() // THE SETUP FUNCTION 
{
  Serial.begin(9600);  // Set serial comms to run at 9600 cahrs per sec
  Serial.flush(); // Flush serial line
  pinMode(RedPin, OUTPUT); // Set the red led pin to be an output pin
  pinMode(GreenPin, OUTPUT); // for green
  pinMode(BluePin, OUTPUT); // for blue
}

void loop() // the main program loop
{
  
  if (Serial.available() > 0) { // if data is sent down the serial line...
    int index=0; // Declare integer called iindex and set to 0
    delay(100); // wait 100 milliseconds 
    int numChar = Serial.available(); // Set numChar to the incoming data from serial 
    if (numChar>15) { // If numchar is greater than 15 characters...
      numChar=15;  // make it 15 and no more 
    }
    while (numChar--) { // while numchar is not zero (subtract 1 from it)
      buffer[index++] = Serial.read(); // set element[index] to value read in (add 1)
    }
    splitString(buffer); // call splitspring function and send it data in buffer 
  }
}

void splitString(char* data) { // The splitstring functon references buffer data 
  Serial.print("Data entered: "); // print data 
  Serial.print(data); // print value
  char* parameter; // declare cahr data type
  parameter= strtok (data, " ,"); // set it to text up to the first space or comma 
  while (parameter != NULL) { // while contents of parameter are not empty
    setLED(parameter); // call the setled function
    parameter = strtok (NULL, " ,"); // set parameter to next part of text string 
  }
  
                              
  for (int x=0; x<16; x++) {  // Clear the text and serial buffers
    buffer[x]='\0';
  }
  Serial.flush();
}

void setLED(char* data) { // a function called setled is passed buffer 
  if ((data[0] == 'r') || (data[0] == 'R')) { // if first letter is r or R 
    int Ans = strtol(data+1, NULL, 10); // set integer ans to number in next part of text
    Ans = constrain(Ans, 0, 255); // make sure it is between 0 and 255
    analogWrite(RedPin, Ans); // write that value out to the red pin
    Serial.print(" Red is set to: "); // print out "Red is set to; "
    Serial.println(Ans);  // and then the value of ans
  }
  if ((data[0] == 'g') || (data[0] == 'G')) { // refer to above 
    int Ans = strtol(data+1, NULL, 10);
    Ans = constrain(Ans, 0, 255);
    analogWrite(GreenPin, Ans);
    Serial.print(" Green is set to: ");
    Serial.println(Ans);
  } 
  if ((data[0] == 'b') || (data[0] == 'B')) { // refer to above 
    int Ans = strtol(data+1, NULL, 10);
    Ans = constrain(Ans, 0, 255);
    analogWrite(BluePin, Ans);
    Serial.print(" Blue is set to: ");
    Serial.println(Ans);
  }
}  
