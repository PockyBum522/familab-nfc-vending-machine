void readSerialOneString(String &serialReadData){
  int makeSerialStringPosition;
  int inByte;
  char serialReadCharArray[100] = "";
  const int terminatingChar = '\n'; //Terminate lines with newline

  inByte = Serial1.read();
  makeSerialStringPosition=0;

  if (inByte > 0 && inByte != terminatingChar) { //If we see data (inByte > 0) and that data isn't a carriage return
    delay(50); //Allow serial data time to collect (I think.) If you want to read longer strings, you may have to up this.

    while (inByte != terminatingChar && Serial1.available() > 0){ // As long as EOL not found and there's more to read, keep reading
      serialReadCharArray[makeSerialStringPosition] = inByte; // Save the data in a character array
      makeSerialStringPosition++; //Increment position in array
      //if (inByte > 0) Serial1.writeln(inByte); // Debug line that prints the charcodes one per line for everything recieved over serial
      inByte = Serial1.read(); // Read next byte
    }

    if (inByte == terminatingChar) { //If we terminated properly
      serialReadCharArray[makeSerialStringPosition] = 0; //Null terminate the serialReadCharArray (Overwrites last position char (terminating char) with 0
      serialReadData = serialReadCharArray;
    }
  }
}
