 bool x;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  digitalWrite(3, HIGH);
 
}

void loop() {
  
  if(digitalRead(8) == LOW)
   x = (x == LOW)? HIGH : LOW;
 
 digitalWrite(3, x);
 while(digitalRead(8) == LOW) {}
 delay(50);
}
