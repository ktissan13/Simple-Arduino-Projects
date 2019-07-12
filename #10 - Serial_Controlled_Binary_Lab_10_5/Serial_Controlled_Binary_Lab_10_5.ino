//project 10 - serial controlled RGB lamp

char buffer[2];  //first we set up am arry of characters to hold our text string, which we made 18 characters long to ensure we won't get buffer overflow errors

int red, green, yellow; //then we  set up the integers to hold the red green and yellow values for the digital pins on the arduino

int redpin = 11; //set to digital pin 11

int greenpin = 10; //set to digital pin 10

int yellowpin = 9; //set to digital pin 9


 
void setup() {  //in ou setup  function we have our 3 digital pins set to an output and then a serial.begin command 
  
  Serial.begin(9600);   //the serial.begin command tells the arduino to start serial communications at 9600 characters per second
  
  Serial.flush();  //this command will flush out any characters that happen to be in the serial line so that it is empty and ready for input/output
  
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(yellowpin, OUTPUT); 
}

void loop() {  
  
  if(Serial.available() > 0) {  //in the main loop we have an if statement which checks to see if any characters have been sent down the serial line, if they have the following code will run
    
    int index = 0;    //an integer called index is set to 0 and this integer will be held as a pointer to the characters within the char array
    
    delay(100);  // we then have a delay of 100ms  inorder to ensure that the serial buffer if full before we carry on and process the data - this is because the character transfer to the serial is slow and it will take time for all the characters to get there
    
    int numChar = Serial.available(); //after the 100ms delay is complete we initalize a integer variable called numChar which will be the number of characters within a string
    
    if(numChar > 15) {
      
      numChar = 15;  //this checks if the value of numChar is greater than 15 and if it is, it sets it to 15 so that the buffer doesn't get overfilled
      
      
    }
    
    while(numChar--){  //this creates a while loop which only runs the code, 'while' the condition is true
      //the condition being checked is if the value of numChar is not 0
      
      
      buffer[index++] = Serial.read();  //as the condition is true, it sets each element of the buffer array to each character read in from the serial line, (it fills up the buffer array witht he letters we entered in the serial monitor)
    
    //so once the value of numChar equals 0, (the length of the string entered) it will get out of the loop
    }
    splitString(buffer); //after the loop is done, it will call the splitString functtion we have created
    
  }
}


void splitString (char* data) { //this function returns no value so it will be linked to the void data type;   also this function has one paratmeter called the char* data
                    //the ashterik is used to allow our character allow to be used in the function, something this is usually not allowed
                    
  Serial.print("Data entered: ");  //this writed the string value written in the paraenthesis in the serial for us to see and enter in values
  Serial.println(data);
  
  char* parameter;  //next we create a new char data type called parameter which is a local scope variable (only can be used in this function)
  parameter = strtok (data, ",");  //we pass the data array to the strtok command as the first arguement and the tokens enclosed within quotes; this will split the string we entered at the comma
  
  while(parameter != NULL) { //we have a while loop whose condition is that the parameter is not empty
   setLED (parameter); //we call out second function setLED
   parameter = strtok(NULL, ",");  //and then it tells the strtok command to carry on where it last left off
    
    
    //so basically this whole portion of code, is splitting the string from the spaces or commas and is going to send that to the next function: setLED
  }
  
  
  for (int x=0; x < 16; x++) {  //this last part of the function simply fills the buffer array with NULL characters, whice is done with the /0 symbol and then flushes the serial data put of the serial buffer, making it ready for the next set of data
    buffer[x] = '\0';  
    
  }
  Serial.flush();  //flushes the serial data making it ready for the next set
}


void setLED(char* data) {        //this final function takes the value of the split string (we got from the splitstring function) and correspond it to each of the LEds, which will read it decide which 
       
        if ((data[0] == '0') && (data[1] == '0') && (data[2] == '0')) {          //In order to make the 3 bit work, we need to take the three numbers the user enters from the serial monitor 
         //it checks if all the numbers the user enters is 0, and only if they all do (AND operator) it will run the code
          
          digitalWrite(redpin, LOW);   //if the user enters all 0, it will turn all the leds off
          digitalWrite(yellowpin, LOW);
          digitalWrite(greenpin, LOW);        
        }
        
        if ((data[0] == '0') && (data[1] == '0') && (data[2] == '1')) {          
          digitalWrite(redpin, LOW);
          digitalWrite(yellowpin, HIGH);                                               //the rest of the if statements are all similar, they inevitably turn the leds on, the leds which the sure chooses
          digitalWrite(greenpin, LOW);
        }
        
        if ((data[0] == '0') && (data[1] == '1') && (data[2] == '0')) {          
          digitalWrite(redpin, LOW);
          digitalWrite(yellowpin, LOW);
          digitalWrite(greenpin, HIGH);
        }
        
        if ((data[0] == '0') && (data[1] == '1') && (data[2] == '1')) {          
          digitalWrite(redpin, LOW);
          digitalWrite(yellowpin, HIGH);
          digitalWrite(greenpin, HIGH);
        }
        
        if ((data[0] == '1') && (data[1] == '0') && (data[2] == '0')) {          
          digitalWrite(redpin, HIGH);
          digitalWrite(yellowpin, LOW);
          digitalWrite(greenpin, LOW);
        }
        
        if ((data[0] == '1') && (data[1] == '0') && (data[2] == '1')) {          
          digitalWrite(redpin, HIGH);
          digitalWrite(yellowpin, HIGH);
          digitalWrite(greenpin, LOW);
        }
            

        if ((data[0] == '1') && (data[1] == '1') && (data[2] == '0')) {          
          digitalWrite(redpin, HIGH);
          digitalWrite(yellowpin, LOW);
          digitalWrite(greenpin, HIGH);
        }
        
        if ((data[0] == '1') && (data[1] == '1') && (data[2] == '1')) {          
          digitalWrite(redpin, HIGH);
          digitalWrite(yellowpin, HIGH);
          digitalWrite(greenpin, HIGH);
        }


            
            
        
}



  
   


  
  
