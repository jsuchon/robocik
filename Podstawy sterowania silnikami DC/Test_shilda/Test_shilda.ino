#define LED 13
#define BUZZER 10
#define PRZYCISK 2

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(PRZYCISK, INPUT_PULLUP);

  digitalWrite(LED, HIGH ); // migniecie LED
  delay(500);
  digitalWrite(LED, LOW );
  delay(500);
  

}

void loop() {
  if( digitalRead(PRZYCISK) == LOW)
   {
      digitalWrite(LED, HIGH );
      analogWrite(BUZZER, 255);
      delay(250);
   }
   else
   {
      digitalWrite(LED, LOW );
      digitalWrite(BUZZER, LOW); 
   }

}
