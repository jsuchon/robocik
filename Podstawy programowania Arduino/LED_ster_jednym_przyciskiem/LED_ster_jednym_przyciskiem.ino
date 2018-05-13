 bool x;
 int i;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  digitalWrite(3, HIGH);
  Serial.begin(9600);
  Serial.print("Hello World\n");
  Serial.print("Wpisz \"ON\" aby wlaczyc LED lub \" OFF\" aby wylaczyc");
 
}

void loop() {
  String dane = "";
  if(Serial.available() > 0)
  {
    dane = Serial.readStringUntil('\n');
    if(dane == "ON")
      x = true;
    if(dane == "OFF")
      x = false;
    if(dane != "ON" && dane != "OFF" )
      Serial.print("BLAD!!!\n");
  }
  
  if(digitalRead(8) == LOW)
   { if(x)
      Serial.print("\nTeraz gasne");
     else
     Serial.print("\nTeraz swiece");    
    x = (x == LOW)? HIGH : LOW;
   }
 
 digitalWrite(3, x);
 while(digitalRead(8) == LOW) {}
 delay(50);
}
