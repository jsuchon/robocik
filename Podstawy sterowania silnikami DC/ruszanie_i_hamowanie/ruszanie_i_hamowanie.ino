void setup() {
   pinMode(6, OUTPUT);
   digitalWrite(6, HIGH);
 
  pinMode(7, OUTPUT); //Sygnały sterujące kierunkiem obrotów silnika nr 1
  pinMode(8, OUTPUT);

  digitalWrite(7, LOW);
  digitalWrite(8, LOW);

}

void loop() {
  
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  
 for( int i = 0; i < 255; i++) // ruszanie
 {
  analogWrite(6, i); 
  delay(20);
 }
 for(int i = 255; i>=0; i--)
 {
  analogWrite(6, i); // hamowanie
  delay(20);
 }

 digitalWrite(7, LOW); // zatrzymanie na 1s
 digitalWrite(8, LOW);
 delay(1000);
  
 
digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  
 for( int i = 0; i < 255; i++) // ruszanie
 {
  analogWrite(6, i); 
  delay(20);
 }
 for(int i = 255; i>=0; i--)
 {
  analogWrite(6, i); // hamowanie
  delay(20);
 }
 
 digitalWrite(7, LOW); // zatrzymanie na 1s
 digitalWrite(8, LOW);
 delay(1000);
}
