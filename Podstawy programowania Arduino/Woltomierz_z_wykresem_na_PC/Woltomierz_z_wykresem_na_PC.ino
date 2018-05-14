int odczyt;
float napiecie;
void setup() {
  Serial.begin(9600);
}

void loop() {
 odczyt = analogRead(A0);
 napiecie = odczyt * (5.0/1023.0);
Serial.println(napiecie);
 delay(250);
}
