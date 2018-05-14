void setup() { 
 pinMode(6, OUTPUT);
 digitalWrite(6, HIGH);
 
  pinMode(7, OUTPUT); //Sygnały sterujące kierunkiem obrotów silnika nr 1
  pinMode(8, OUTPUT);

  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
} 
 
void loop()  {   
   digitalWrite(7, LOW); //Silnik nr 1 - obroty w lewo
  digitalWrite(8, HIGH); 
  delay(3000);
  
  digitalWrite(7, HIGH); //Silnik nr 1 - obroty w prawo
  digitalWrite(8, LOW); 
  delay(3000);      
}
