void writeCardString(String cardString)
{

    Serial.println("Starting!");
  String csumString;
      Serial.println("You Passed:");
          Serial.println(cardString);
  csumString = calcLRC(cardString); 
  
  for(int i = 0; i < 20; i ++) {writeBit(0);} // Lead in clocking 0s

  for(int pos = 0; pos < cardString.length(); pos++)
  {
    char currentChar = cardString.charAt(pos); 
    
    if (currentChar - '0' <= 9 && currentChar - '0' >= 0) // this finds out if the character we're working with is 0 - 9. I swear.
    {
      writeNumber(currentChar - '0');
    } 
    else if (currentChar == ';')
    {
          writeNumber(11);
    } 
    else if (currentChar == '=')
    {
              writeNumber(13);
    } 
    else if (currentChar == '?')
    {
                writeNumber(15);
    } else {Serial.println("Invalid char in cc string!");}
  
  }
    
    Serial.println("Done writing Card string!");
    
  for (int csumIndex = 0; csumIndex < 5; csumIndex++)  // Write out the precalculated LRC char by walking through the string passed back by the LRC calc function.
  {
    writeBit(csumString[csumIndex] - '0');
  }
      Serial.println("wrote csum!");

  for(int i = 0; i < 20; i ++) {writeBit(0);} // Lead out clocking 0s
  
  writeLow();
}
