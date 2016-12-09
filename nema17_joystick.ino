#define VELOCIDAD 5000
int steps = 2;
int direccion = 3;
int reset = 9;
int pasos = 200;
int vol_x = A0;
int vol_y = A1;
int xpos = 0;
int ypos = 0;
void setup()
{
  pinMode(vol_x,INPUT);
  pinMode(vol_y,INPUT);
  pinMode(steps, OUTPUT); 
  pinMode(direccion, OUTPUT); 
  pinMode(reset, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  xpos = analogRead(vol_x);
  ypos = analogRead(vol_y);

  if(ypos > 600)
  {
      digitalWrite(reset, LOW);
      delay(100);
      digitalWrite(reset, HIGH);
      digitalWrite(direccion, HIGH);
      while(ypos > 600)
      {
        ypos = analogRead(vol_y);
        Serial.println(ypos);
        digitalWrite(steps, HIGH);
        digitalWrite(steps, LOW);
        delayMicroseconds(VELOCIDAD);
        Serial.println("hola");
      }
  }
  else if(ypos < 400)
  {
      digitalWrite(reset, LOW);
      delay(100);
      digitalWrite(reset, HIGH);
      digitalWrite(direccion, LOW);
      while(ypos < 400)
      {
        ypos = analogRead(vol_y);
        digitalWrite(steps, HIGH);
        digitalWrite(steps, LOW);
        delayMicroseconds(VELOCIDAD);
      }
  }
}
