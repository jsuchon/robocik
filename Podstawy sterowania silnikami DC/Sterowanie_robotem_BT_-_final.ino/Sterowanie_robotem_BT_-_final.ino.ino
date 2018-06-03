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
#define MAX_POWER_PWM 160

void error()
{ 
  digitalWrite(led_error, HIGH);
}
void error_reset()
{
  digitalWrite(led_error, LOW);
}

class Left_motor{
  public:
    int get_power() const{ return _power_L;}
    bool set_power(const int power)   // zwraca true jesli ok, false jesli blad 
    {
      if( power >= 0 && power <= MAX_POWER_PWM )
        {
          _power_L = power;
          return true;
        }
        else 
          return false;
    }  
    int get_dir() const { return _dir; }
    void set_dir(const bool dir ) { _dir = dir; }

    void drive( char *data )
      {
        char temp[3];
        for (int i = 1; i < 4; i++ )
        {
          temp[i-1] = data[i];
        }
       int power = atoi(temp);
       
       if(data[0] == '0' )
       {
          set_dir(true);
       } 
       if(data[0] == '1' )
       {
         set_dir(false);
       } 
       if ( set_power(power) == 0 )
          error();

       digitalWrite(L_DIR, get_dir());
       analogWrite(motor_L, get_power());   
      }
  private:
    int _power_L = 0; 
    bool _dir = false;
};


class Right_motor{
  public:
    int get_power() const{ return _power_R;}
    bool set_power(const int power)   // zwraca true jesli ok, false jesli blad 
    {
      if( power >= 0 && power <= MAX_POWER_PWM )
        {
          _power_R = power;
          return true;
        }
        else 
          return false;
    }  
    int get_dir() const { return _dir; }
    void set_dir(const bool dir ) { _dir = dir; }

    void drive( char *data )
      {
        char temp[3];
        for (int i = 0; i < 3; i++ )
        {
          temp[i] = data[i+5];
        }
       int power = atoi(temp);
       
       if(data[4] == '0' )
       {
          set_dir(false);
       } 
       if(data[4] == '1' )
       {
         set_dir(true);
       } 

       if ( set_power(power) == 0 )
         error();

       digitalWrite(R_DIR, get_dir());
       analogWrite(motor_R, get_power());
      }
  private:
    int _power_R = 0; 
    bool _dir = false;
};

  Left_motor left_motor;
  Right_motor right_motor;
  
void setup() {

  Serial.begin(9600);
  pinMode(motor_L, OUTPUT);
  pinMode(motor_R, OUTPUT);
  pinMode(led_error, OUTPUT);

  error_reset();
  right_motor.drive("0000");
  left_motor.drive("0000");
}

void loop() {

  String data = "";

  if(Serial.available() > 0)
  {
    data = "";
    error_reset();
    data = Serial.readStringUntil('\n');
    if ( data == "s" )  // skrot do funkcji zatrzymania
      data = "00000000"; 
    left_motor.drive(data.c_str());
    right_motor.drive(data.c_str());
  }
    
    Serial.println(" Motor_L direction and PWM: ");
    Serial.print(left_motor.get_dir()); 
    Serial.print("   ");
    Serial.print(left_motor.get_power());
    Serial.println(" Motor_R direction and PWM: ");
    Serial.print(right_motor.get_dir());
    Serial.print("   ");
    Serial.print(right_motor.get_power());
    Serial.println(" data: ");
    Serial.print(data);
    Serial.print('\n'); 
    
    delay(1000);
   }
  
   

