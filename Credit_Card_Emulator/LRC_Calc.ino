String calcLRC(String stringToLRC)
{
  int firstLRCCalcBit = 0;
  int secondLRCCalcBit = 0;
  int thirdLRCCalcBit = 0;
  int fourthLRCCalcBit = 0;

  int LRCParityBit = 0;
  
  String LRCString("00000");
  
  for(int pos = 0; pos < stringToLRC.length(); pos++) // Run through the string to calc LRC
  {
    char currentChar = stringToLRC.charAt(pos);
    
    if (currentChar == '1')
    {
      firstLRCCalcBit++;
    }
    else if (currentChar == '2')
    {
      secondLRCCalcBit++; 
    }
    else if (currentChar == '3')
    {
      firstLRCCalcBit++;
      secondLRCCalcBit++;      
    }
    else if (currentChar == '4')
    {
      thirdLRCCalcBit++;
    }
    else if (currentChar == '5')
    {
      firstLRCCalcBit++;
      thirdLRCCalcBit++;      
    }
    else if (currentChar == '6')
    {
      secondLRCCalcBit++;
      thirdLRCCalcBit++;      
    }
    else if (currentChar == '7')
    {
      firstLRCCalcBit++;
      secondLRCCalcBit++;
      thirdLRCCalcBit++;      
    }
    else if (currentChar == '8')
    {
      fourthLRCCalcBit++;      
    }
    else if (currentChar == '9')
    {
      firstLRCCalcBit++;      
      fourthLRCCalcBit++;      
    }
    else if (currentChar == ';')
    {
      firstLRCCalcBit++;
      secondLRCCalcBit++;
      fourthLRCCalcBit++;
    } 
    else if (currentChar == '=')
    {
      firstLRCCalcBit++;
      thirdLRCCalcBit++;
      fourthLRCCalcBit++;
    } 
    else if (currentChar == '?')
    {
      firstLRCCalcBit++;
      secondLRCCalcBit++;
      thirdLRCCalcBit++;
      fourthLRCCalcBit++;
    }  
  }
  
  if(firstLRCCalcBit % 2 == 1) {LRCParityBit++;} // Total up bits for calculating Parity Bit
  if(secondLRCCalcBit % 2 == 1) {LRCParityBit++;}
  if(thirdLRCCalcBit % 2 == 1) {LRCParityBit++;}
  if(fourthLRCCalcBit % 2 == 1) {LRCParityBit++;}
 
  if(LRCParityBit % 2 == 1){LRCParityBit = '0';} else {LRCParityBit = '1';}
       
  LRCString.setCharAt(0, firstLRCCalcBit % 2 + '0');
  LRCString.setCharAt(1, secondLRCCalcBit % 2 + '0');
  LRCString.setCharAt(2, thirdLRCCalcBit % 2 + '0');
  LRCString.setCharAt(3, fourthLRCCalcBit % 2 + '0');
  LRCString.setCharAt(4, LRCParityBit);
  
  return LRCString;
}
