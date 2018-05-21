/* 
  Sterowanie jasnoscia 2 diod. Schemat dzialania:
  A123\n
  A - ktora dioda
  123 - wartosc pwm
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

int get_val(char* data)
{
  char val[3]; //strlen(data) - 1
   for(int i = 1; i <= 3 ; i++)  // przepisujemy do tablicy "val" typu char tablice data bez pierwszego znaku
  {
    val[i-1] = data[i];
  }
 int brightness = atoi(val); // Konwersja lancucha znakow do zmiennej typu int
  if(brightness < 0 || brightness> 255 )
  { error();
  //  Serial.print("BLAD");
    return -1;
  }
  return brightness;    

}


void set_values( char *data)
{
  switch(data[0])
  {
    case 'A':
      led_1_brightness = get_val(data);
      break;
    case 'B':
      led_2_brightness = get_val(data);
      break;
    default:  
      error();
      break;
  }
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
    
    if (led_1_brightness >= 0 && led_2_brightness >= 0)
   {
    
    analogWrite(led_1, led_1_brightness);
    analogWrite(led_2, led_2_brightness);
   }

   delay(2000);
   
    
}
