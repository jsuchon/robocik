void setup(){
  Serial.begin(9600); 
  Serial.println("Hello World!"); 
}
void loop() {
  delay(2000);
  Serial.println("Jestem w nieskonczonej petli!"); 
}
