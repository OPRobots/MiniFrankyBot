/////////////////////////////////////////////////////////////////////////////
// Programa de control a distancia de MiniFrankyBot mediante BT            //
// Se usa un gamepad de la Nintendo64 gracias a la librería N64Controler.h //
/////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////
// Librería de control del gamepad. //
//////////////////////////////////////
#include <N64Controller.h>
#include <Comandos.h>

/////////////////////////////////
// Pin de conexión del gamepad //
/////////////////////////////////
#define PIN_GAMEPAD 12

#define BATERIA A7

#define LED_ONOFF 9
#define LED_STATE 10
#define PIN_STATE 2


/////////////////////////////////////
// Objeto controlador del gamepad. //
/////////////////////////////////////
N64Controller FrankyController(PIN_GAMEPAD);

int x_axis = 0;

// Bandera para saber si se han enviado comandos en un ciclo de ejecución.
bool comandos_enviados = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED_ONOFF, OUTPUT);
  analogWrite(LED_ONOFF, 80);
  pinMode(PIN_STATE, INPUT);
  pinMode(LED_STATE, OUTPUT);
  digitalWrite(LED_ONOFF, HIGH);
  // Inicializa el controlador del gamepad y espera para normalizar su estado.
  FrankyController.begin();
  delay(500);
}

void loop() {
  analogWrite(LED_ONOFF, 80);

  digitalWrite(LED_STATE, digitalRead(PIN_STATE));

  //Resetea la bandera de envío de comandos
  comandos_enviados = false;

  // Actualiza el estado de los botones del gamepad.
  FrankyController.update();

  //
  if (FrankyController.R()) {
    comandos_enviados = true;
    Serial.print(STRONG_RIGHT);
  }
  if (FrankyController.L()) {
    comandos_enviados = true;
    Serial.print(STRONG_LEFT);
  }
  if (FrankyController.A()) {
    comandos_enviados = true;
    Serial.print(SALTITOS);

  }
  if (FrankyController.B()) {
    comandos_enviados = true;
    Serial.print(SUUUUUUPER);
  }
  if (FrankyController.D_up()) {
    comandos_enviados = true;
    Serial.print(DESPL_IZQUIERDA);

  }
  if (FrankyController.D_down()) {
    comandos_enviados = true;
    Serial.print(DESPL_DERECHA);

  }
  if (FrankyController.D_left()) {
    comandos_enviados = true;
    Serial.print(ROTATE_IZQUIERDA);
  }
  if (FrankyController.D_right()) {
    comandos_enviados = true;
    Serial.print(ROTATE_DERECHA);
  }
  if (FrankyController.Start()) {
    comandos_enviados = true;
    Serial.print(POS_INICIAL);
  }
  if (FrankyController.Z()) {
    comandos_enviados = true;
    Serial.print(INVINCIBLE_MOD);
  }
  if (FrankyController.C_right()) {
    comandos_enviados = true;
    Serial.print(POS_CADERA_D);
  }
  if (FrankyController.C_left()) {
    comandos_enviados = true;
    Serial.print(POS_CADERA_I);
  }
  if (FrankyController.C_up()) {
    comandos_enviados = true;
    Serial.print(POS_CADERA_C);
  }
  if (FrankyController.C_down()) {
    comandos_enviados = true;
    Serial.print(AGACHARSE);
  }
  // if(abs(((int)FrankyController.axis_x())-x_axis) > 10){
  //   x_axis = (int)FrankyController.axis_x();
  //   Serial.print(POS_CADERA);
  //   Serial.println(abs(x_axis)>10?(x_axis>0?100:-100):0);
  // }

  if(comandos_enviados){
    digitalWrite(LED_ONOFF, LOW);
    delay(500);
  }
  delay(30);
}
