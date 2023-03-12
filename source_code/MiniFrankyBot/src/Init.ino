//////////////////////////////////////////////////////////////////////
// Este fichero contendrá todos los procesos iniciales del programa //
// que se deberán ejecutar una sola vez al inicio del mismo.        //
//////////////////////////////////////////////////////////////////////

/**
* Función principal de inicialización de componentes.
*/
void init_all(){
  init_serial();
  delay(100);
  init_posiciones_iniciales();
  delay(100);
  init_servos();
  delay(100);
  init_leds();
  delay(100);
}

/**
* Inicialización del puerto Serial.
*/
void init_serial(){
  Serial.begin(9600);
  while (!Serial){}
}

/**
* Inicialización de los servos y posicionamiento inicial.
*/
void init_servos(){
  init_arduino_servos();
  init_PCA9685_servos();
  init_position();
}

/**
* Inizializa los servos conectados directamente al Arduino
*/
void init_arduino_servos(){
  for (short servo = 0; servo < NUM_SERVOS_HOMBROS; servo++) {
    servosHombros[servo].attach(pinsServosHombros[servo]);
  }
}

/**
* Inicizaliza los servos conectados a la PCA9685
*/
void init_PCA9685_servos(){
  // Iniciar de la PCA9685 y establecer la frecuencia de funcionamiento.
  servoController.begin();
  servoController.setPWMFreq(330);
}

/**
* Inicialización de leds
*/
void init_leds(){
  pinMode(LED_DERECHO, OUTPUT);
  pinMode(LED_IZQUIERDO, OUTPUT);
}

/**
* Establece los valores para las posiciones iniciales de cada grupo de servos
*/
void init_posiciones_iniciales(){
  /////////////////////////////////////////
  // Posiciones iniciales PIERNA IZQUIERDA //
  /////////////////////////////////////////
  posicionesInicialesPiernaIzquierda[0] = 130;
  posicionesInicialesPiernaIzquierda[1] = 113; //143
  posicionesInicialesPiernaIzquierda[2] = 140; //170
  posicionesInicialesPiernaIzquierda[3] = 40; //10
  posicionesInicialesPiernaIzquierda[4] = 45; //25

  ///////////////////////////////////////////
  // Posiciones iniciales PIERNA DERECHA //
  ///////////////////////////////////////////
  posicionesInicialesPiernaDerecha[0] = 75;
  posicionesInicialesPiernaDerecha[1] = 50; //28
  posicionesInicialesPiernaDerecha[2] = 35; //18
  posicionesInicialesPiernaDerecha[3] = 139; //161
  posicionesInicialesPiernaDerecha[4] = 118; //146

  /////////////////////////////////////////
  // Posiciones iniciales CADERA //
  /////////////////////////////////////////
  posicionesInicialesCadera[0] = 130;
  posicionesInicialesCadera[1] = 58;
  posicionesInicialesCadera[2] = 85;

  /////////////////////////////////////////
  // Posiciones iniciales HOMBROS //
  /////////////////////////////////////////
  posicionesInicialesHombros[0] = 175;
  posicionesInicialesHombros[1] = 5;

  /////////////////////////////////////////
  // Posiciones iniciales CODOS //
  /////////////////////////////////////////
  posicionesInicialesCodos[0] = 18;
  posicionesInicialesCodos[1] = 150;
}
