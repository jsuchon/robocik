#define led_1 3
#define led_2 5 

void setup() {
 double czas = 1;
  pinMode(led_1, OUTPUT);
  digitalWrite(led_1, HIGH);    
  
   pinMode(led_2, OUTPUT);
  digitalWrite(led_2, LOW);    
  
}

void loop() { 
  double czas = 8;
  
  delay (czas);
  digitalWrite(led, LOW);
  delay (czas);
  digitalWrite(led, HIGH);  
  
  delay (czas);
  digitalWrite(lod, LOW);
  delay (czas);
  digitalWrite(lod, HIGH);  
}
