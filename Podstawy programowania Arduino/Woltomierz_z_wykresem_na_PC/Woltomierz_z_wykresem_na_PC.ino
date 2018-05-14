int odczyt;
float napiecie;
float led;
void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() {
 odczyt = analogRead(A0);
 napiecie = odczyt * (5.0/1023.0);
Serial.println(napiecie);
 led = odczyt * (5.0/255.0);
 analogWrite(3, led);
 delay(250);
}
