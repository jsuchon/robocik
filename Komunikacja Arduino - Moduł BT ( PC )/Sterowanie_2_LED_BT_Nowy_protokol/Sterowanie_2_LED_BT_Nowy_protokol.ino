/* 
  Sterowanie jasnoscia 2 diod. Nowy schemat dzialania:
  XXXXYYYY\n
  XXXX - wartosc ze znakiem (+ do przodu / - do tylu) dla diody 1 
  YYYY -  wartosc PWM ze znakiem (+ do przodu / - do tylu) dla diody 2 
  
  \n - koniec lini
 */

#define led_1 5
#define led_2 6
#define led_error 13
String data = "";
int led_1_brightness = 0;
int led_2_brightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_error, OUTPUT);

  digitalWrite(led_error, LOW);
  analogWrite(led_1, led_1_brightness);
  analogWrite(led_2, led_2_brightness);
  
}

void error()
{ 
  digitalWrite(led_error, HIGH);
}
void error_reset()
{
  digitalWrite(led_error, LOW);
}

void set_values( char *data)
{
  char val_1[4];
  char val_2[4];

  for( int i = 0; i < 4; i++ ) 
  {
     val_1[i] = data[i];
  }
  for( int i = 0; i < 4; i++)
  {
    val_2[i] = data[i+4];
  }
  led_1_brightness = abs(atoi(val_1)); 
  led_2_brightness = abs(atoi(val_2)); 
      
}


void loop() {
  
  if(Serial.available() > 0)
  {
    data = "";
    error_reset();
    data = Serial.readStringUntil('\n');
    set_values(data.c_str());
    
  }
  
    Serial.print(" Led_1: ");
    Serial.println(led_1_brightness);
    Serial.print(" Led_2: ");
    Serial.println(led_2_brightness);
    Serial.print(" data: ");
    Serial.println(data);
    Serial.print('\n');
    
    if (led_1_brightness >= 0 && led_2_brightness >= 0 && led_1_brightness <= 255 && led_2_brightness <= 255)
   {
    analogWrite(led_1, led_1_brightness);
    analogWrite(led_2, led_2_brightness);
   }
   else 
   error();

   delay(2000);
   
    
}
