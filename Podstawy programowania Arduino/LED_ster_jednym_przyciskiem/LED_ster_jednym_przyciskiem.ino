 bool x;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  digitalWrite(3, HIGH);
  Serial.begin(9600);
  Serial.print("Hello World");
 
}

void loop() {
  
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
