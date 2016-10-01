byte data;
byte buf = PORTC;
int play = A0;
int 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
DDRC = B00111111; // set pins 8-13 as output
}
void loop() {
  while(Serial.available()) {
      data = Serial.read();
      Serial.print(data,BIN); //print out command
      Serial.print("\r\n");
      data = data &  B00001111 ;
      buf = buf & B11110000;
      buf = buf | data;
      PORTC = buf;
      
  }
}
