#include <Arduino.h>
#define Boton 5
#define Led 4
#define Pin_Analogo A0
bool Anterior_valor_boton=0;
bool Valor_boton;
bool Estado_Led=0;
void setup() 
{
Serial.begin(9600);
pinMode(Boton, INPUT);
pinMode(Led, OUTPUT);
digitalWrite(Led, LOW);
}
void loop() 
{
bool Boton_Value = digitalRead(Boton);
Serial.println("Estado del pulsador:"+String(Boton_Value));
if(Boton_Value==1)
  {
   digitalWrite(Led, HIGH);
  }  
  else
   {
   digitalWrite(Led, LOW);  
   }
    if(Anterior_valor_boton == 0 && Valor_boton==1)
    {
    Estado_Led =!Estado_Led;
    digitalWrite(Led, Estado_Led);
    }  
  Anterior_valor_boton=Valor_boton;

  int Valor=analogRead(Pin_Analogo);
  analogWrite(Led, Valor/4);
  Serial.println("Valor del potenciometro: "+String(Valor));
  
}