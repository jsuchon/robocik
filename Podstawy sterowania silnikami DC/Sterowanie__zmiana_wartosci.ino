/* 
  Sterowanie 2 silnikami. Nowy schemat dzialania:
  XXXXYYYY\n
  XXXX - wartosc ze znakiem (+ do przodu / - do tylu) dla silnika lewego 
  YYYY -  wartosc PWM ze znakiem (+ do przodu / - do tylu) dla silnika prawego
  1AAA - znak +
  0AAA - znak - 
  \n - koniec lini
 */
 
#define L_DIR 4
#define R_DIR 9
#define motor_L 5
#define motor_R 6
#define led_error 13

String data = "";
int power_L = 0;
int power_R = 0;


void setup() {
  Serial.begin(9600);
  pinMode(motor_L, OUTPUT);
  pinMode(motor_R, OUTPUT);
  pinMode(led_error, OUTPUT);

  digitalWrite(led_error, LOW);
  analogWrite(motor_L, power_L);
  analogWrite(motor_R, power_R);
}

void LeftMotor ()
{
  if ( power_L >=0 && power_L <= 160 )
  {
    digitalWrite( L_DIR, 0);
    analogWrite( motor_L, power_L);
  }

  if ( power_L >= -160 && power_L < 0 )
  {
    digitalWrite( L_DIR, 1);
    analogWrite( motor_L, abs(power_L));
  }
}

void RightMotor ()
{
  if ( power_R >=0 && power_R <= 160 )
  {
    digitalWrite( R_DIR, 1);
    analogWrite( motor_R, power_R);
  }

  if ( power_R >= -160 && power_R < 0 )
  {
    digitalWrite( R_DIR, 0);
    analogWrite( motor_R, abs(power_R));
  }
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
  if(data[0]=='u'){
    power_L+=25;
    power_R+=25;
  }
  if(data[0]=='d'){
    power_L-=25;
    power_R-=25;
  }
  if(data[0]=='l'){
    power_R+=25;
  }
  if(data[0]=='r'){
    power_L+=25;
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
  
    
    if (power_L >= -160 && power_R >= -160 && power_L <= 160 && power_R <= 160)
   {
    LeftMotor();
    RightMotor(); 
    Serial.print(" Motor_L: ");
    Serial.println(power_L);
    Serial.print(" Motor_R: ");
    Serial.println(power_R);
    Serial.print(" data: ");
    Serial.println(data);
    Serial.print('\n');
    
   }
   else 
   error();

   delay(2000);
   
    
}
