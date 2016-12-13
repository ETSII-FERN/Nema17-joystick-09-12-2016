
 
#include <Stepper.h> //Importamos la librería para controlar motores paso a paso
 
#define STEPS 200 //Ponemos el número de pasos que necesita para dar una vuelta. 200 en nuestro caso
 

 
void setup()
{
  // Velocidad del motor en RPM
  stepper.setSpeed(100);
}
 
void loop()
{
  //Girar una vuelta entera en un sentido
  stepper.step(200);
  delay(500); //Pequeña pausa
 
  //Girar una vuelta entera en sentido contrario
  stepper.step(-200);
  delay(500); //Pequeña pausa
}