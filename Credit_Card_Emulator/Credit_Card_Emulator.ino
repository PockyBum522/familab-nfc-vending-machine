void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial1.begin(9600);
  Serial.begin(9600);
}

String database[2][3] = {
  "Friendly Name Card1",       "FF:FF:FF:00",             ";4991000000001234=12011011000000000555?",
  "Friendly Name Card2",       "00:00:00:00:00:00:FF",    ";4991000000001235=12011011000000000666?",
 };

void loop(){  
  String serialData = ""; 
  readSerialOneString(serialData);
  
  if (serialData > 0) {
    digitalWrite(13, HIGH);
    for (int i = 0; i < sizeof(database) / sizeof(database[0]); i++){
      if (serialData == database[i][1]) {
        writeCardString(database[i][2]);
        Serial.print("Read tag ");  Serial.print(database[i][0]);  Serial.println("sending associated credit card!");
      }
    }
  }
}
