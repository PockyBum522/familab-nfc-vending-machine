int leftPin = 10;
int rightPin = 11;
int clockSpeed = 500;
int clockHalf = 0;

void writeLow(){
  digitalWrite(leftPin, LOW);
  digitalWrite(rightPin, LOW);
}

void writeBit(int lowOrHigh)
{
  if(lowOrHigh == 1)
  {
    if(clockHalf == 0)
    {
      digitalWrite(rightPin, LOW);
      digitalWrite(leftPin, HIGH);
      delayMicroseconds(clockSpeed);
      digitalWrite(leftPin, LOW);
      digitalWrite(rightPin, HIGH);
      delayMicroseconds(clockSpeed);
      //clockHalf = 1;
    }
    else
    {
      digitalWrite(leftPin, LOW);
      digitalWrite(rightPin, HIGH);
      delayMicroseconds(clockSpeed);
      digitalWrite(rightPin, LOW);
      digitalWrite(leftPin, HIGH);
      delayMicroseconds(clockSpeed);
      //clockHalf = 0;
    }
  }
  else
  {
    if(clockHalf == 0)
    {
      digitalWrite(rightPin, LOW);
      digitalWrite(leftPin, HIGH);
      delayMicroseconds(clockSpeed * 2);
      clockHalf = 1;
    }
    else
    {
      digitalWrite(leftPin, LOW);
      digitalWrite(rightPin, HIGH);
      delayMicroseconds(clockSpeed * 2);
      clockHalf = 0;
    }
  }
}

void writeNumber(int numToWrite)
{
  if(numToWrite == 0)
  {
     writeBit(0);
     writeBit(0);
     writeBit(0);
     writeBit(0);
     writeBit(1);
   }
  else if(numToWrite == 1)
  {
     writeBit(1);
     writeBit(0);
     writeBit(0);
     writeBit(0);
     writeBit(0);
  }
  else if(numToWrite == 2)
  {
     writeBit(0);
     writeBit(1);
     writeBit(0);
     writeBit(0);
     writeBit(0);
  }
  else if(numToWrite == 3)
  {
     writeBit(1);
     writeBit(1);
     writeBit(0);
     writeBit(0);
     writeBit(1);
  }
  else if(numToWrite == 4)
  {
     writeBit(0);
     writeBit(0);
     writeBit(1);
     writeBit(0);
     writeBit(0);
  }
  else if(numToWrite == 5)
  {
     writeBit(1);
     writeBit(0);
     writeBit(1);
     writeBit(0);
     writeBit(1);
  }
  else if(numToWrite == 6)
  {
     writeBit(0);
     writeBit(1);
     writeBit(1);
     writeBit(0);
     writeBit(1);
  }
  else if(numToWrite == 7)
  {
     writeBit(1);
     writeBit(1);
     writeBit(1);
     writeBit(0);
     writeBit(0);
  }
  else if(numToWrite == 8)
  {
     writeBit(0);
     writeBit(0);
     writeBit(0);
     writeBit(1);
     writeBit(0);
  }
  else if(numToWrite == 9)
  {
     writeBit(1);
     writeBit(0);
     writeBit(0);
     writeBit(1);
     writeBit(1);
  }
  else if(numToWrite == 10)
  {
     writeBit(0);
     writeBit(1);
     writeBit(0);
     writeBit(1);
     writeBit(1);
  }
  else if(numToWrite == 11)
  {
     writeBit(1);
     writeBit(1);
     writeBit(0);
     writeBit(1);
     writeBit(0);
  }
  else if(numToWrite == 12)
  {
     writeBit(0);
     writeBit(0);
     writeBit(1);
     writeBit(1);
     writeBit(1);
  }
  else if(numToWrite == 13)
  {
     writeBit(1);
     writeBit(0);
     writeBit(1);
     writeBit(1);
     writeBit(0);
  }
  else if(numToWrite == 14)
  {
     writeBit(0);
     writeBit(1);
     writeBit(1);
     writeBit(1);
     writeBit(0);
  }
  else if(numToWrite == 15)
  {
     writeBit(1);
     writeBit(1);
     writeBit(1);
     writeBit(1);
     writeBit(1); 
  }
}
