#include <Arduino.h>
#define Boton 4
#define Boton1 5
#define Led 1
#define Led1 2
#define Led2 3
#define Pin_Analogo A0
bool Anterior_valor_boton=0;
bool Valor_boton;
bool Estado_Led=0;
void setup() 
{
Serial.begin(9600);
pinMode(Boton, INPUT);
pinMode(Boton1, INPUT);
pinMode(Led, OUTPUT);
pinMode(Led1, OUTPUT);
pinMode(Led2, OUTPUT);
digitalWrite(Led, LOW);
digitalWrite(Led1, LOW);
digitalWrite(Led2, LOW);
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
   bool Valor_Boton_1 = digitalRead(Boton1);
    if(Anterior_valor_boton == 0 && Valor_Boton_1==1)
    {
    Estado_Led =!Estado_Led;
    digitalWrite(Led1, Estado_Led);
    }  
  Anterior_valor_boton=Valor_boton;

  int Valor=analogRead(Pin_Analogo);
  analogWrite(Led2, Valor/4);
  Serial.println("Valor del potenciometro: "+String(Valor));

}