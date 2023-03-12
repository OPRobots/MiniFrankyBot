///////////////////////////////////////////////////////////////////
// Este fichero contendrá todos los movimientos y posiciones que //
// podrá adoptar el robot durante su funcionamiento.             //
///////////////////////////////////////////////////////////////////

/**
* Establece todos los servos a su posición inicial.
*/
void init_position(){
  nipple_lights = false;
  // set_servo_position(pinsServosPiernaIzquierda[0], posicionesInicialesPiernaIzquierda[0]);
  // set_servo_position(pinsServosPiernaIzquierda[1], posicionesInicialesPiernaIzquierda[1]);
  // set_servo_position(pinsServosPiernaIzquierda[2], posicionesInicialesPiernaIzquierda[2]);
  // set_servo_position(pinsServosPiernaIzquierda[3], posicionesInicialesPiernaIzquierda[3]);
  // set_servo_position(pinsServosPiernaIzquierda[4], posicionesInicialesPiernaIzquierda[4]);
  // set_servo_position(pinsServosPiernaDerecha[0], posicionesInicialesPiernaDerecha[0]);
  // set_servo_position(pinsServosPiernaDerecha[1], posicionesInicialesPiernaDerecha[1]);
  // set_servo_position(pinsServosPiernaDerecha[2], posicionesInicialesPiernaDerecha[2]);
  // set_servo_position(pinsServosPiernaDerecha[3], posicionesInicialesPiernaDerecha[3]);
  // set_servo_position(pinsServosPiernaDerecha[4], posicionesInicialesPiernaDerecha[4]);
  // set_servo_position(pinsServosCadera[0], posicionesInicialesCadera[0]);
  // set_servo_position(pinsServosCadera[1], posicionesInicialesCadera[1]);
  // set_servo_position(pinsServosCadera[2], posicionesInicialesCadera[2]);
  // set_servo_position(servosHombros[0], posicionesInicialesHombros[0]);
  // set_servo_position(servosHombros[1], posicionesInicialesHombros[1]);
  // set_servo_position(pinsServosCodos[0], posicionesInicialesCodos[0]);
  set_servo_position(pinsServosCodos[1], posicionesInicialesCodos[1]);

  // set_servo_position(servosHombros[0], 70);
  // set_servo_position(servosHombros[1], 140);
  delay(100);
}

/**
* Movimiento de agacharse lentamente que parte desde la posición inicial.
* @param repeticiones Número de períodos a ejecutar
*/
void mov_agacharse(float repeticiones){
  // init_position();

  const byte numServos = 8;
  short ajustesAgacharse[numServos][5];
  short servosAgacharse[numServos];

  servosAgacharse[0] = pinsServosPiernaDerecha[1];
  servosAgacharse[1] = pinsServosPiernaDerecha[2];
  servosAgacharse[2] = pinsServosPiernaDerecha[3];
  servosAgacharse[3] = pinsServosPiernaDerecha[4];
  servosAgacharse[4] = pinsServosPiernaIzquierda[1];
  servosAgacharse[5] = pinsServosPiernaIzquierda[2];
  servosAgacharse[6] = pinsServosPiernaIzquierda[3];
  servosAgacharse[7] = pinsServosPiernaIzquierda[4];

  ajustesAgacharse[0][OFFSET]           = posicionesInicialesPiernaDerecha[1];
  ajustesAgacharse[0][PERIODO]          = 1000;
  ajustesAgacharse[0][AMPLITUD]         = 30;
  ajustesAgacharse[0][FASE]             = 0;
  ajustesAgacharse[0][DEFAULT]          = 0;

  ajustesAgacharse[1][OFFSET]           = posicionesInicialesPiernaDerecha[2];
  ajustesAgacharse[1][PERIODO]          = 1000;
  ajustesAgacharse[1][AMPLITUD]         = 30;
  ajustesAgacharse[1][FASE]             = 0;
  ajustesAgacharse[1][DEFAULT]          = 0;

  ajustesAgacharse[2][OFFSET]           = posicionesInicialesPiernaDerecha[3];
  ajustesAgacharse[2][PERIODO]          = 1000;
  ajustesAgacharse[2][AMPLITUD]         = 30;
  ajustesAgacharse[2][FASE]             = 180;
  ajustesAgacharse[2][DEFAULT]          = 0;

  ajustesAgacharse[3][OFFSET]           = posicionesInicialesPiernaDerecha[4];
  ajustesAgacharse[3][PERIODO]          = 1000;
  ajustesAgacharse[3][AMPLITUD]         = 30;
  ajustesAgacharse[3][FASE]             = 180;
  ajustesAgacharse[3][DEFAULT]          = 0;

  ajustesAgacharse[4][OFFSET]           = posicionesInicialesPiernaIzquierda[1];
  ajustesAgacharse[4][PERIODO]          = 1000;
  ajustesAgacharse[4][AMPLITUD]         = 30;
  ajustesAgacharse[4][FASE]             = 180;
  ajustesAgacharse[4][DEFAULT]          = 0;

  ajustesAgacharse[5][OFFSET]           = posicionesInicialesPiernaIzquierda[2];
  ajustesAgacharse[5][PERIODO]          = 1000;
  ajustesAgacharse[5][AMPLITUD]         = 30;
  ajustesAgacharse[5][FASE]             = 180;
  ajustesAgacharse[5][DEFAULT]          = 0;

  ajustesAgacharse[6][OFFSET]           = posicionesInicialesPiernaIzquierda[3];
  ajustesAgacharse[6][PERIODO]          = 1000;
  ajustesAgacharse[6][AMPLITUD]         = 30;
  ajustesAgacharse[6][FASE]             = 0;
  ajustesAgacharse[6][DEFAULT]          = 0;

  ajustesAgacharse[7][OFFSET]           = posicionesInicialesPiernaIzquierda[4];
  ajustesAgacharse[7][PERIODO]          = 1000;
  ajustesAgacharse[7][AMPLITUD]         = 30;
  ajustesAgacharse[7][FASE]             = 0;
  ajustesAgacharse[7][DEFAULT]          = 0;

  ejecutar_movimiento(servosAgacharse, ajustesAgacharse, numServos, repeticiones);
}

/**
* Realiza un pequeño salto usando la funcion "mov_agacharse" como primer paso
* @param repeticiones Número de saltos consecutivos.
*/
void mov_salto(int repeticiones) {
  short loops = 0;
  if(!invencible)
  do {

    // Prepara el salto agachandose lentamente
      mov_agacharse(0.25);
      init_position();

    loops ++;
  } while(loops < repeticiones);

}

/**
* Gira sobre si mismo hacia la derecha
* @param repeticiones Número de "toques" del giro.
*/
void mov_rotate_de(int repeticiones) {
  short loops = 0;
  do {

    // Prepara el salto agachandose lentamente
    set_servo_position(pinsServosCadera[1], 100);
    // delay(1000);
    mov_agacharse(0.25);
    init_position();
    delay(120);

    loops ++;
  } while(loops < repeticiones);

}

/**
* Gira sobre si mismo hacia la izquierda
* @param repeticiones Número de "toques" del giro.
*/
void mov_rotate_iz(int repeticiones) {
  short loops = 0;
  do {

    // Prepara el salto agachandose lentamente
    set_servo_position(pinsServosCadera[1], 16);
    // delay(1000);
    mov_agacharse(0.25);
    init_position();
    delay(120);

    loops ++;
  } while(loops < repeticiones);

}

/**
* Efectua un paso, compuesto por varios segmentos de movimientos.
* @param repeticiones Número de pasos que dará.
*/
void mov_paso(int repeticiones){
  short loops = 0;
  float speed = 0.5;

  do {
    const byte numServosPaso1 = 4;
    short ajustesPaso1[numServosPaso1][5];
    short servosPaso1[numServosPaso1];

    servosPaso1[0] = pinsServosPiernaIzquierda[0];
    servosPaso1[1] = pinsServosCadera[0];
    servosPaso1[2] = pinsServosPiernaDerecha[0];
    servosPaso1[3] = pinsServosCadera[2];

    ajustesPaso1[0][OFFSET]           = posicionesInicialesPiernaIzquierda[0];
    ajustesPaso1[0][PERIODO]          = 6000*speed;
    ajustesPaso1[0][AMPLITUD]         = 13;
    ajustesPaso1[0][FASE]             = 0;
    ajustesPaso1[0][DEFAULT]          = 0;

    ajustesPaso1[1][OFFSET]           = posicionesInicialesCadera[0];
    ajustesPaso1[1][PERIODO]          = 6000*speed;
    ajustesPaso1[1][AMPLITUD]         = 13;
    ajustesPaso1[1][FASE]             = 0;
    ajustesPaso1[1][DEFAULT]          = 0;

    ajustesPaso1[2][OFFSET]           = posicionesInicialesPiernaDerecha[0];
    ajustesPaso1[2][PERIODO]          = 6000*speed;
    ajustesPaso1[2][AMPLITUD]         = 13;
    ajustesPaso1[2][FASE]             = 0;
    ajustesPaso1[2][DEFAULT]          = 0;

    ajustesPaso1[3][OFFSET]           = posicionesInicialesCadera[2];
    ajustesPaso1[3][PERIODO]          = 6000*speed;
    ajustesPaso1[3][AMPLITUD]         = 13;
    ajustesPaso1[3][FASE]             = 270;
    ajustesPaso1[3][DEFAULT]          = 0;

    ejecutar_movimiento(servosPaso1, ajustesPaso1, numServosPaso1, 0.25);

    delay(100);

    const byte numServosPaso2 = 2;
    short ajustesPaso2[numServosPaso2][5];
    short servosPaso2[numServosPaso2];

    servosPaso2[0] = pinsServosPiernaDerecha[3];
    servosPaso2[1] = pinsServosPiernaDerecha[4];

    ajustesPaso2[0][OFFSET]           = posicionesInicialesPiernaDerecha[3];
    ajustesPaso2[0][PERIODO]          = 4000*speed;
    ajustesPaso2[0][AMPLITUD]         = 27;
    ajustesPaso2[0][FASE]             = 180;
    ajustesPaso2[0][DEFAULT]          = 0;

    ajustesPaso2[1][OFFSET]           = posicionesInicialesPiernaDerecha[4];
    ajustesPaso2[1][PERIODO]          = 4000*speed;
    ajustesPaso2[1][AMPLITUD]         = 27;
    ajustesPaso2[1][FASE]             = 180;
    ajustesPaso2[1][DEFAULT]          = 0;

    ejecutar_movimiento(servosPaso2, ajustesPaso2, numServosPaso2, 0.25);

    delay(250);

    const byte numServosPaso4 = 5;
    short ajustesPaso4[numServosPaso4][5];
    short servosPaso4[numServosPaso4];

    servosPaso4[0] = pinsServosPiernaIzquierda[0];
    servosPaso4[1] = pinsServosCadera[0];
    servosPaso4[2] = pinsServosPiernaDerecha[0];
    servosPaso4[3] = pinsServosCadera[2];
    servosPaso4[4] = pinsServosPiernaIzquierda[1];
    servosPaso4[5] = pinsServosPiernaIzquierda[2];

    ajustesPaso4[0][OFFSET]           = posicionesActualesPCA9685[servosPaso4[0]];
    ajustesPaso4[0][PERIODO]          = 4000*speed;
    ajustesPaso4[0][AMPLITUD]         = 10;
    ajustesPaso4[0][FASE]             = 180;
    ajustesPaso4[0][DEFAULT]          = 0;

    ajustesPaso4[1][OFFSET]           = posicionesActualesPCA9685[servosPaso4[1]];
    ajustesPaso4[1][PERIODO]          = 4000*speed;
    ajustesPaso4[1][AMPLITUD]         = 10;
    ajustesPaso4[1][FASE]             = 180;
    ajustesPaso4[1][DEFAULT]          = 0;

    ajustesPaso4[2][OFFSET]           = posicionesActualesPCA9685[servosPaso4[2]];
    ajustesPaso4[2][PERIODO]          = 4000*speed;
    ajustesPaso4[2][AMPLITUD]         = 13;
    ajustesPaso4[2][FASE]             = 180;
    ajustesPaso4[2][DEFAULT]          = 0;
    //
    ajustesPaso4[3][OFFSET]           = posicionesActualesPCA9685[servosPaso4[3]];
    ajustesPaso4[3][PERIODO]          = 4000*speed;
    ajustesPaso4[3][AMPLITUD]         = 10;
    ajustesPaso4[3][FASE]             = 90;
    ajustesPaso4[3][DEFAULT]          = 0;

    ajustesPaso4[4][OFFSET]           = posicionesInicialesPiernaIzquierda[1];
    ajustesPaso4[4][PERIODO]          = 4000*speed;
    ajustesPaso4[4][AMPLITUD]         = 80;
    ajustesPaso4[4][FASE]             = 180;
    ajustesPaso4[4][DEFAULT]          = 0;

    ajustesPaso4[5][OFFSET]           = posicionesInicialesPiernaIzquierda[2];
    ajustesPaso4[5][PERIODO]          = 4000*speed;
    ajustesPaso4[5][AMPLITUD]         = 80;
    ajustesPaso4[5][FASE]             = 180;
    ajustesPaso4[5][DEFAULT]          = 0;

    ejecutar_movimiento(servosPaso4, ajustesPaso4, numServosPaso4, 0.25);

    delay(100);

    const byte numServosPaso5 = 4;
    short ajustesPaso5[numServosPaso5][5];
    short servosPaso5[numServosPaso5];

    servosPaso5[0] = pinsServosPiernaIzquierda[0];
    servosPaso5[1] = pinsServosCadera[0];
    servosPaso5[2] = pinsServosPiernaDerecha[0];
    servosPaso5[3] = pinsServosCadera[2];

    ajustesPaso5[0][OFFSET]           = posicionesActualesPCA9685[servosPaso5[0]];
    ajustesPaso5[0][PERIODO]          = 6000*speed;
    ajustesPaso5[0][AMPLITUD]         = 8;
    ajustesPaso5[0][FASE]             = 180;
    ajustesPaso5[0][DEFAULT]          = 0;

    ajustesPaso5[1][OFFSET]           = posicionesActualesPCA9685[servosPaso5[1]];
    ajustesPaso5[1][PERIODO]          = 6000*speed;
    ajustesPaso5[1][AMPLITUD]         = 8;
    ajustesPaso5[1][FASE]             = 90;
    ajustesPaso5[1][DEFAULT]          = 0;

    ajustesPaso5[2][OFFSET]           = posicionesActualesPCA9685[servosPaso5[2]];
    ajustesPaso5[2][PERIODO]          = 6000*speed;
    ajustesPaso5[2][AMPLITUD]         = 8;
    ajustesPaso5[2][FASE]             = 180;
    ajustesPaso5[2][DEFAULT]          = 0;

    ajustesPaso5[3][OFFSET]           = posicionesActualesPCA9685[servosPaso5[3]];
    ajustesPaso5[3][PERIODO]          = 6000*speed;
    ajustesPaso5[3][AMPLITUD]         = 8;
    ajustesPaso5[3][FASE]             = 90;
    ajustesPaso5[3][DEFAULT]          = 0;

    ejecutar_movimiento(servosPaso5, ajustesPaso5, numServosPaso5, 0.25);

    delay(100);

    const byte numServosPaso6 = 6;
    short ajustesPaso6[numServosPaso6][5];
    short servosPaso6[numServosPaso6];

    servosPaso6[0] = pinsServosPiernaIzquierda[1];
    servosPaso6[1] = pinsServosPiernaIzquierda[2];
    servosPaso6[2] = pinsServosPiernaIzquierda[3];
    servosPaso6[3] = pinsServosPiernaIzquierda[4];
    servosPaso6[4] = pinsServosPiernaDerecha[1];
    servosPaso6[5] = pinsServosPiernaDerecha[2];

    ajustesPaso6[0][OFFSET]           = posicionesActualesPCA9685[servosPaso6[0]];
    ajustesPaso6[0][PERIODO]          = 4000*speed;
    ajustesPaso6[0][AMPLITUD]         = 30;
    ajustesPaso6[0][FASE]             = 180;
    ajustesPaso6[0][DEFAULT]          = 0;

    ajustesPaso6[1][OFFSET]           = posicionesActualesPCA9685[servosPaso6[1]];
    ajustesPaso6[1][PERIODO]          = 4000*speed;
    ajustesPaso6[1][AMPLITUD]         = 30;
    ajustesPaso6[1][FASE]             = 180;
    ajustesPaso6[1][DEFAULT]          = 0;

    ajustesPaso6[2][OFFSET]           = posicionesActualesPCA9685[servosPaso6[2]];
    ajustesPaso6[2][PERIODO]          = 4000*speed;
    ajustesPaso6[2][AMPLITUD]         = 30;
    ajustesPaso6[2][FASE]             = 0;
    ajustesPaso6[2][DEFAULT]          = 0;

    ajustesPaso6[3][OFFSET]           = posicionesActualesPCA9685[servosPaso6[3]];
    ajustesPaso6[3][PERIODO]          = 4000*speed;
    ajustesPaso6[3][AMPLITUD]         = 30;
    ajustesPaso6[3][FASE]             = 0;
    ajustesPaso6[3][DEFAULT]          = 0;

    ajustesPaso6[4][OFFSET]           = posicionesActualesPCA9685[servosPaso6[4]];
    ajustesPaso6[4][PERIODO]          = 4000*speed;
    ajustesPaso6[4][AMPLITUD]         = 30;
    ajustesPaso6[4][FASE]             = 0;
    ajustesPaso6[4][DEFAULT]          = 0;

    ajustesPaso6[5][OFFSET]           = posicionesActualesPCA9685[servosPaso6[5]];
    ajustesPaso6[5][PERIODO]          = 4000*speed;
    ajustesPaso6[5][AMPLITUD]         = 30;
    ajustesPaso6[5][FASE]             = 0;
    ajustesPaso6[5][DEFAULT]          = 0;

    ejecutar_movimiento(servosPaso6, ajustesPaso6, numServosPaso6, 0.25);

    delay(100);

    const byte numServosPaso7 = 4;
    short ajustesPaso7[numServosPaso7][5];
    short servosPaso7[numServosPaso7];

    servosPaso7[0] = pinsServosPiernaIzquierda[0];
    servosPaso7[1] = pinsServosCadera[0];
    servosPaso7[2] = pinsServosPiernaDerecha[0];
    servosPaso7[3] = pinsServosCadera[2];

    ajustesPaso7[0][OFFSET]           = posicionesActualesPCA9685[servosPaso7[0]];
    ajustesPaso7[0][PERIODO]          = 6000*speed;
    ajustesPaso7[0][AMPLITUD]         = 10;
    ajustesPaso7[0][FASE]             = 0;
    ajustesPaso7[0][DEFAULT]          = 0;

    ajustesPaso7[1][OFFSET]           = posicionesActualesPCA9685[servosPaso7[1]];
    ajustesPaso7[1][PERIODO]          = 6000*speed;
    ajustesPaso7[1][AMPLITUD]         = 10;
    ajustesPaso7[1][FASE]             = 0;
    ajustesPaso7[1][DEFAULT]          = 0;

    ajustesPaso7[2][OFFSET]           = posicionesActualesPCA9685[servosPaso7[2]];
    ajustesPaso7[2][PERIODO]          = 6000*speed;
    ajustesPaso7[2][AMPLITUD]         = 10;
    ajustesPaso7[2][FASE]             = 0;
    ajustesPaso7[2][DEFAULT]          = 0;

    ajustesPaso7[3][OFFSET]           = posicionesActualesPCA9685[servosPaso7[3]];
    ajustesPaso7[3][PERIODO]          = 6000*speed;
    ajustesPaso7[3][AMPLITUD]         = 10;
    ajustesPaso7[3][FASE]             = 270;
    ajustesPaso7[3][DEFAULT]          = 0;

    ejecutar_movimiento(servosPaso7, ajustesPaso7, numServosPaso7, 0.25);

    delay(100);

    const byte numServosPaso8 = 6;
    short ajustesPaso8[numServosPaso8][5];
    short servosPaso8[numServosPaso8];

    servosPaso8[0] = pinsServosPiernaDerecha[1];
    servosPaso8[1] = pinsServosPiernaDerecha[2];
    servosPaso8[2] = pinsServosPiernaDerecha[3];
    servosPaso8[3] = pinsServosPiernaDerecha[4];
    servosPaso8[4] = pinsServosPiernaIzquierda[2];
    // servosPaso8[5] = pinsServosPiernaIzquierda[1];
    disable_servo(pinsServosPiernaIzquierda[1]);
    disable_servo(pinsServosPiernaIzquierda[3]);
    // servosPaso8[6] = pinsServosPiernaIzquierda[3];
    servosPaso8[5] = pinsServosPiernaIzquierda[4];

    ajustesPaso8[0][OFFSET]           = posicionesActualesPCA9685[servosPaso8[0]];
    ajustesPaso8[0][PERIODO]          = 4000*speed;
    ajustesPaso8[0][AMPLITUD]         = 20;
    ajustesPaso8[0][FASE]             = 180;
    ajustesPaso8[0][DEFAULT]          = 0;

    ajustesPaso8[1][OFFSET]           = posicionesActualesPCA9685[servosPaso8[1]];
    ajustesPaso8[1][PERIODO]          = 4000*speed;
    ajustesPaso8[1][AMPLITUD]         = 20;
    ajustesPaso8[1][FASE]             = 180;
    ajustesPaso8[1][DEFAULT]          = 0;

    ajustesPaso8[2][OFFSET]           = posicionesActualesPCA9685[servosPaso8[2]];
    ajustesPaso8[2][PERIODO]          = 4000*speed;
    ajustesPaso8[2][AMPLITUD]         = 30;
    ajustesPaso8[2][FASE]             = 0;
    ajustesPaso8[2][DEFAULT]          = 0;

    ajustesPaso8[3][OFFSET]           = posicionesActualesPCA9685[servosPaso8[3]];
    ajustesPaso8[3][PERIODO]          = 4000*speed;
    ajustesPaso8[3][AMPLITUD]         = 30;
    ajustesPaso8[3][FASE]             = 0;
    ajustesPaso8[3][DEFAULT]          = 0;

    ajustesPaso8[4][OFFSET]           = posicionesActualesPCA9685[servosPaso8[4]];
    ajustesPaso8[4][PERIODO]          = 4000*speed;
    ajustesPaso8[4][AMPLITUD]         = 40;
    ajustesPaso8[4][FASE]             = 0;
    ajustesPaso8[4][DEFAULT]          = 0;

    // ajustesPaso8[5][OFFSET]           = posicionesActualesPCA9685[servosPaso8[5]];
    // ajustesPaso8[5][PERIODO]          = 4000*speed;
    // ajustesPaso8[5][AMPLITUD]         = 20;
    // ajustesPaso8[5][FASE]             = 90;
    // ajustesPaso8[5][DEFAULT]          = 0;
    //
    // ajustesPaso8[6][OFFSET]           = posicionesActualesPCA9685[servosPaso8[6]];
    // ajustesPaso8[6][PERIODO]          = 4000*speed;
    // ajustesPaso8[6][AMPLITUD]         = 40;
    // ajustesPaso8[6][FASE]             = 270;
    // ajustesPaso8[6][DEFAULT]          = 0;
    //
    ajustesPaso8[5][OFFSET]           = posicionesActualesPCA9685[servosPaso8[5]];
    ajustesPaso8[5][PERIODO]          = 4000*speed;
    ajustesPaso8[5][AMPLITUD]         = 40;
    ajustesPaso8[5][FASE]             = 180;
    ajustesPaso8[5][DEFAULT]          = 0;

    ejecutar_movimiento(servosPaso8, ajustesPaso8, numServosPaso8, 0.25);

    delay(100);

    init_position();

    loops++;
  } while(loops < repeticiones);


}

void mov_lowkick_derecha(int repeticiones){

  for (byte loops = 0; loops < repeticiones; loops++) {
    const byte numServos = 6;
    short ajustesPatada[numServos][5];
    short servosPatada[numServos];

    servosPatada[0] = pinsServosPiernaIzquierda[1];
    servosPatada[1] = pinsServosPiernaIzquierda[2];
    servosPatada[2] = pinsServosPiernaIzquierda[3];
    servosPatada[3] = pinsServosPiernaIzquierda[4];
    servosPatada[4] = pinsServosCadera[2];
    servosPatada[5] = pinsServosPiernaDerecha[0];


    ajustesPatada[0][OFFSET]           = posicionesInicialesPiernaIzquierda[1];
    ajustesPatada[0][PERIODO]          = 1500;
    ajustesPatada[0][AMPLITUD]         = 45;
    ajustesPatada[0][FASE]             = 180;
    ajustesPatada[0][DEFAULT]          = 0;

    ajustesPatada[1][OFFSET]           = posicionesInicialesPiernaIzquierda[2];
    ajustesPatada[1][PERIODO]          = 1500;
    ajustesPatada[1][AMPLITUD]         = 45;
    ajustesPatada[1][FASE]             = 180;
    ajustesPatada[1][DEFAULT]          = 0;

    ajustesPatada[2][OFFSET]           = posicionesInicialesPiernaIzquierda[3];
    ajustesPatada[2][PERIODO]          = 1500;
    ajustesPatada[2][AMPLITUD]         = 45;
    ajustesPatada[2][FASE]             = 0;
    ajustesPatada[2][DEFAULT]          = 0;

    ajustesPatada[3][OFFSET]           = posicionesInicialesPiernaIzquierda[4];
    ajustesPatada[3][PERIODO]          = 1500;
    ajustesPatada[3][AMPLITUD]         = 45;
    ajustesPatada[3][FASE]             = 0;
    ajustesPatada[3][DEFAULT]          = 0;

    ajustesPatada[4][OFFSET]           = posicionesInicialesCadera[2];
    ajustesPatada[4][PERIODO]          = 1500;
    ajustesPatada[4][AMPLITUD]         = 45;
    ajustesPatada[4][FASE]             = 0;
    ajustesPatada[4][DEFAULT]          = 0;

    ajustesPatada[5][OFFSET]           = posicionesInicialesPiernaDerecha[0];
    ajustesPatada[5][PERIODO]          = 1500;
    ajustesPatada[5][AMPLITUD]         = 45;
    ajustesPatada[5][FASE]             = 0;
    ajustesPatada[5][DEFAULT]          = 0;

    ejecutar_movimiento(servosPatada, ajustesPatada, numServos, 0.5);
    delay(100);
  }
}

void mov_lowkick_izquierda(int repeticiones){

  for (byte loops = 0; loops < repeticiones; loops++) {
    const byte numServos = 6;
    short ajustesPatada[numServos][5];
    short servosPatada[numServos];

    servosPatada[0] = pinsServosPiernaDerecha[1];
    servosPatada[1] = pinsServosPiernaDerecha[2];
    servosPatada[2] = pinsServosPiernaDerecha[3];
    servosPatada[3] = pinsServosPiernaDerecha[4];
    servosPatada[4] = pinsServosCadera[0];
    servosPatada[5] = pinsServosPiernaIzquierda[0];


    ajustesPatada[0][OFFSET]           = posicionesInicialesPiernaDerecha[1];
    ajustesPatada[0][PERIODO]          = 1500;
    ajustesPatada[0][AMPLITUD]         = 45;
    ajustesPatada[0][FASE]             = 0;
    ajustesPatada[0][DEFAULT]          = 0;

    ajustesPatada[1][OFFSET]           = posicionesInicialesPiernaDerecha[2];
    ajustesPatada[1][PERIODO]          = 1500;
    ajustesPatada[1][AMPLITUD]         = 45;
    ajustesPatada[1][FASE]             = 0;
    ajustesPatada[1][DEFAULT]          = 0;

    ajustesPatada[2][OFFSET]           = posicionesInicialesPiernaDerecha[3];
    ajustesPatada[2][PERIODO]          = 1500;
    ajustesPatada[2][AMPLITUD]         = 45;
    ajustesPatada[2][FASE]             = 180;
    ajustesPatada[2][DEFAULT]          = 0;

    ajustesPatada[3][OFFSET]           = posicionesInicialesPiernaDerecha[4];
    ajustesPatada[3][PERIODO]          = 1500;
    ajustesPatada[3][AMPLITUD]         = 45;
    ajustesPatada[3][FASE]             = 180;
    ajustesPatada[3][DEFAULT]          = 0;

    ajustesPatada[4][OFFSET]           = posicionesInicialesCadera[0];
    ajustesPatada[4][PERIODO]          = 1500;
    ajustesPatada[4][AMPLITUD]         = 60;
    ajustesPatada[4][FASE]             = 180;
    ajustesPatada[4][DEFAULT]          = 0;

    ajustesPatada[5][OFFSET]           = posicionesInicialesPiernaIzquierda[0];
    ajustesPatada[5][PERIODO]          = 1500;
    ajustesPatada[5][AMPLITUD]         = 60;
    ajustesPatada[5][FASE]             = 180;
    ajustesPatada[5][DEFAULT]          = 0;

    ejecutar_movimiento(servosPatada, ajustesPatada, numServos, 0.5);
    delay(100);
  }
}

void mov_airKick(){


  const byte numServosPaso1 = 8;
  short ajustesPaso1[numServosPaso1][5];
  short servosPaso1[numServosPaso1];

  servosPaso1[0] = pinsServosPiernaDerecha[1];
  servosPaso1[1] = pinsServosPiernaDerecha[2];
  servosPaso1[2] = pinsServosPiernaDerecha[3];
  servosPaso1[3] = pinsServosPiernaDerecha[4];
  servosPaso1[4] = pinsServosPiernaIzquierda[1];
  servosPaso1[5] = pinsServosPiernaIzquierda[2];
  servosPaso1[6] = pinsServosPiernaIzquierda[3];
  servosPaso1[7] = pinsServosPiernaIzquierda[4];

  ajustesPaso1[0][OFFSET]           = posicionesInicialesPiernaDerecha[1];
  ajustesPaso1[0][PERIODO]          = 1000;
  ajustesPaso1[0][AMPLITUD]         = 50;
  ajustesPaso1[0][FASE]             = 0;
  ajustesPaso1[0][DEFAULT]          = 0;

  ajustesPaso1[1][OFFSET]           = posicionesInicialesPiernaDerecha[2];
  ajustesPaso1[1][PERIODO]          = 1000;
  ajustesPaso1[1][AMPLITUD]         = 50;
  ajustesPaso1[1][FASE]             = 0;
  ajustesPaso1[1][DEFAULT]          = 0;

  ajustesPaso1[2][OFFSET]           = posicionesInicialesPiernaDerecha[3];
  ajustesPaso1[2][PERIODO]          = 1000;
  ajustesPaso1[2][AMPLITUD]         = 50;
  ajustesPaso1[2][FASE]             = 180;
  ajustesPaso1[2][DEFAULT]          = 0;

  ajustesPaso1[3][OFFSET]           = posicionesInicialesPiernaDerecha[4];
  ajustesPaso1[3][PERIODO]          = 1000;
  ajustesPaso1[3][AMPLITUD]         = 50;
  ajustesPaso1[3][FASE]             = 180;
  ajustesPaso1[3][DEFAULT]          = 0;

  ajustesPaso1[4][OFFSET]           = posicionesInicialesPiernaIzquierda[1];
  ajustesPaso1[4][PERIODO]          = 1000;
  ajustesPaso1[4][AMPLITUD]         = 50;
  ajustesPaso1[4][FASE]             = 180;
  ajustesPaso1[4][DEFAULT]          = 0;

  ajustesPaso1[5][OFFSET]           = posicionesInicialesPiernaIzquierda[2];
  ajustesPaso1[5][PERIODO]          = 1000;
  ajustesPaso1[5][AMPLITUD]         = 50;
  ajustesPaso1[5][FASE]             = 180;
  ajustesPaso1[5][DEFAULT]          = 0;

  ajustesPaso1[6][OFFSET]           = posicionesInicialesPiernaIzquierda[3];
  ajustesPaso1[6][PERIODO]          = 1000;
  ajustesPaso1[6][AMPLITUD]         = 50;
  ajustesPaso1[6][FASE]             = 0;
  ajustesPaso1[6][DEFAULT]          = 0;

  ajustesPaso1[7][OFFSET]           = posicionesInicialesPiernaIzquierda[4];
  ajustesPaso1[7][PERIODO]          = 1000;
  ajustesPaso1[7][AMPLITUD]         = 50;
  ajustesPaso1[7][FASE]             = 0;
  ajustesPaso1[7][DEFAULT]          = 0;

  ejecutar_movimiento(servosPaso1, ajustesPaso1, numServosPaso1, 0.25);


  const byte numServosPaso2 = 7;
  short ajustesPaso2[numServosPaso2][5];
  short servosPaso2[numServosPaso2];

  servosPaso2[0] = pinsServosPiernaDerecha[1];
  servosPaso2[1] = pinsServosPiernaDerecha[2];
  servosPaso2[2] = pinsServosPiernaDerecha[3];
  servosPaso2[3] = pinsServosPiernaDerecha[4];
  servosPaso2[4] = pinsServosCadera[2];
  servosPaso2[5] = pinsServosCadera[0];
  servosPaso2[6] = pinsServosPiernaIzquierda[0];


  ajustesPaso2[0][OFFSET]           = posicionesActualesPCA9685[servosPaso2[0]];
  ajustesPaso2[0][PERIODO]          = 1000;
  ajustesPaso2[0][AMPLITUD]         = 40;
  ajustesPaso2[0][FASE]             = 180;
  ajustesPaso2[0][DEFAULT]          = 0;

  ajustesPaso2[1][OFFSET]           = posicionesActualesPCA9685[servosPaso2[1]];
  ajustesPaso2[1][PERIODO]          = 1000;
  ajustesPaso2[1][AMPLITUD]         = 40;
  ajustesPaso2[1][FASE]             = 180;
  ajustesPaso2[1][DEFAULT]          = 0;

  ajustesPaso2[2][OFFSET]           = posicionesActualesPCA9685[servosPaso2[2]];
  ajustesPaso2[2][PERIODO]          = 1000;
  ajustesPaso2[2][AMPLITUD]         = 40;
  ajustesPaso2[2][FASE]             = 0;
  ajustesPaso2[2][DEFAULT]          = 0;

  ajustesPaso2[3][OFFSET]           = posicionesActualesPCA9685[servosPaso2[3]];
  ajustesPaso2[3][PERIODO]          = 1000;
  ajustesPaso2[3][AMPLITUD]         = 40;
  ajustesPaso2[3][FASE]             = 0;
  ajustesPaso2[3][DEFAULT]          = 0;

  ajustesPaso2[4][OFFSET]           = posicionesInicialesCadera[2];
  ajustesPaso2[4][PERIODO]          = 1800;
  ajustesPaso2[4][AMPLITUD]         = 110;
  ajustesPaso2[4][FASE]             = 180;
  ajustesPaso2[4][DEFAULT]          = 0;

  ajustesPaso2[5][OFFSET]           = posicionesInicialesCadera[0];
  ajustesPaso2[5][PERIODO]          = 1000;
  ajustesPaso2[5][AMPLITUD]         = 80;
  ajustesPaso2[5][FASE]             = 180;
  ajustesPaso2[5][DEFAULT]          = 0;
  //
  ajustesPaso2[6][OFFSET]           = posicionesInicialesPiernaIzquierda[0];
  ajustesPaso2[6][PERIODO]          = 2000;
  ajustesPaso2[6][AMPLITUD]         = 10;
  ajustesPaso2[6][FASE]             = 0;
  ajustesPaso2[6][DEFAULT]          = 0;

  ejecutar_movimiento(servosPaso2, ajustesPaso2, numServosPaso2, 0.25);


  const byte numServosPaso3 = 5;
  short ajustesPaso3[numServosPaso3][5];
  short servosPaso3[numServosPaso3];

  servosPaso3[0] = pinsServosPiernaDerecha[1];
  servosPaso3[1] = pinsServosPiernaDerecha[2];
  servosPaso3[2] = pinsServosPiernaDerecha[3];
  servosPaso3[3] = pinsServosPiernaDerecha[4];
  servosPaso3[4] = pinsServosCadera[2];

  ajustesPaso3[0][OFFSET]           = posicionesActualesPCA9685[servosPaso3[0]];
  ajustesPaso3[0][PERIODO]          = 1000;
  ajustesPaso3[0][AMPLITUD]         = 50;
  ajustesPaso3[0][FASE]             = 0;
  ajustesPaso3[0][DEFAULT]          = 0;

  ajustesPaso3[1][OFFSET]           = posicionesActualesPCA9685[servosPaso3[1]];
  ajustesPaso3[1][PERIODO]          = 1000;
  ajustesPaso3[1][AMPLITUD]         = 50;
  ajustesPaso3[1][FASE]             = 0;
  ajustesPaso3[1][DEFAULT]          = 0;

  ajustesPaso3[2][OFFSET]           = posicionesActualesPCA9685[servosPaso3[2]];
  ajustesPaso3[2][PERIODO]          = 1000;
  ajustesPaso3[2][AMPLITUD]         = 50;
  ajustesPaso3[2][FASE]             = 180;
  ajustesPaso3[2][DEFAULT]          = 0;

  ajustesPaso3[3][OFFSET]           = posicionesActualesPCA9685[servosPaso3[3]];
  ajustesPaso3[3][PERIODO]          = 1000;
  ajustesPaso3[3][AMPLITUD]         = 50;
  ajustesPaso3[3][FASE]             = 180;
  ajustesPaso3[3][DEFAULT]          = 0;

  ajustesPaso3[4][OFFSET]           = posicionesActualesPCA9685[servosPaso3[4]];
  ajustesPaso3[4][PERIODO]          = 1000;
  ajustesPaso3[4][AMPLITUD]         = 220;
  ajustesPaso3[4][FASE]             = 0;
  ajustesPaso3[4][DEFAULT]          = 0;

  ejecutar_movimiento(servosPaso3, ajustesPaso3, numServosPaso3, 0.25);

  const byte numServosPaso4 = 4;
  short ajustesPaso4[numServosPaso4][5];
  short servosPaso4[numServosPaso4];

  servosPaso4[0] = pinsServosPiernaDerecha[1];
  servosPaso4[1] = pinsServosPiernaDerecha[2];
  servosPaso4[2] = pinsServosPiernaDerecha[3];
  servosPaso4[3] = pinsServosPiernaDerecha[4];
  // servosPaso4[4] = pinsServosPiernaIzquierda[1];
  // servosPaso4[5] = pinsServosPiernaIzquierda[2];
  // servosPaso4[6] = pinsServosPiernaIzquierda[3];
  // servosPaso4[7] = pinsServosPiernaIzquierda[4];
  // servosPaso2[8] = pinsServosPiernaIzquierda[0];

  ajustesPaso4[0][OFFSET]           = posicionesActualesPCA9685[servosPaso4[0]];
  ajustesPaso4[0][PERIODO]          = 250;
  ajustesPaso4[0][AMPLITUD]         = 60;
  ajustesPaso4[0][FASE]             = 180;
  ajustesPaso4[0][DEFAULT]          = 0;

  ajustesPaso4[1][OFFSET]           = posicionesActualesPCA9685[servosPaso4[1]];
  ajustesPaso4[1][PERIODO]          = 250;
  ajustesPaso4[1][AMPLITUD]         = 60;
  ajustesPaso4[1][FASE]             = 180;
  ajustesPaso4[1][DEFAULT]          = 0;

  ajustesPaso4[2][OFFSET]           = posicionesActualesPCA9685[servosPaso4[2]];
  ajustesPaso4[2][PERIODO]          = 250;
  ajustesPaso4[2][AMPLITUD]         = 60;
  ajustesPaso4[2][FASE]             = 0;
  ajustesPaso4[2][DEFAULT]          = 0;

  ajustesPaso4[3][OFFSET]           = posicionesActualesPCA9685[servosPaso4[3]];
  ajustesPaso4[3][PERIODO]          = 250;
  ajustesPaso4[3][AMPLITUD]         = 60;
  ajustesPaso4[3][FASE]             = 0;
  ajustesPaso4[3][DEFAULT]          = 0;

  // ajustesPaso4[4][OFFSET]           = posicionesActualesPCA9685[servosPaso4[4]];
  // ajustesPaso4[4][PERIODO]          = 250;
  // ajustesPaso4[4][AMPLITUD]         = 70;
  // ajustesPaso4[4][FASE]             = 0;
  // ajustesPaso4[4][DEFAULT]          = 0;

  // ajustesPaso4[5][OFFSET]           = posicionesActualesPCA9685[servosPaso4[5]];
  // ajustesPaso4[5][PERIODO]          = 250;
  // ajustesPaso4[5][AMPLITUD]         = 70;
  // ajustesPaso4[5][FASE]             = 0;
  // ajustesPaso4[5][DEFAULT]          = 0;

  // ajustesPaso4[6][OFFSET]           = posicionesActualesPCA9685[servosPaso4[6]];
  // ajustesPaso4[6][PERIODO]          = 250;
  // ajustesPaso4[6][AMPLITUD]         = 70;
  // ajustesPaso4[6][FASE]             = 180;
  // ajustesPaso4[6][DEFAULT]          = 0;

  // ajustesPaso4[7][OFFSET]           = posicionesActualesPCA9685[servosPaso4[7]];
  // ajustesPaso4[7][PERIODO]          = 250;
  // ajustesPaso4[7][AMPLITUD]         = 70;
  // ajustesPaso4[7][FASE]             = 180;
  // ajustesPaso4[7][DEFAULT]          = 0;


  // ajustesPaso4[8][OFFSET]           = posicionesActualesPCA9685[servosPaso4[8]];
  // ajustesPaso4[8][PERIODO]          = 300;
  // ajustesPaso4[8][AMPLITUD]         = 20;
  // ajustesPaso4[8][FASE]             = 180;
  // ajustesPaso4[8][DEFAULT]          = 0;

  ejecutar_movimiento(servosPaso4, ajustesPaso4, numServosPaso4, 0.25);
}

void mov_StrongLeft(){
  const byte numServosPCA9685 = 1;
  short ajustesStrongLeftPCA9685[numServosPCA9685][5];
  short servosStrongLeftPCA9685[numServosPCA9685];
  servosStrongLeftPCA9685[0] = pinsServosCodos[0];

  const byte numServos = 1;
  short ajustesStrongLeft[numServos][5];
  Servo servosStrongLeft[numServos];
  servosStrongLeft[0] = servosHombros[0];

  ajustesStrongLeftPCA9685[0][OFFSET]           = posicionesInicialesCodos[0];
  ajustesStrongLeftPCA9685[0][PERIODO]          = 800;
  ajustesStrongLeftPCA9685[0][AMPLITUD]         = 95;
  ajustesStrongLeftPCA9685[0][FASE]             = 0;
  ajustesStrongLeftPCA9685[0][DEFAULT]          = 0;



  ajustesStrongLeft[0][OFFSET]           = posicionesInicialesHombros[0];
  ajustesStrongLeft[0][PERIODO]          = 800;
  ajustesStrongLeft[0][AMPLITUD]         = 50;
  ajustesStrongLeft[0][FASE]             = 180;
  ajustesStrongLeft[0][DEFAULT]          = 0;

  ejecutar_movimiento(servosStrongLeftPCA9685, ajustesStrongLeftPCA9685, numServosPCA9685, servosStrongLeft, ajustesStrongLeft, numServos, 0.5f);

}

void mov_StrongRight(){

  const byte numServosPCA9685 = 1;
  short ajustesStrongRightPCA9685[numServosPCA9685][5];
  short servosStrongRightPCA9685[numServosPCA9685];
  servosStrongRightPCA9685[0] = pinsServosCodos[1];

  const byte numServos = 1;
  short ajustesStrongRight[numServos][5];
  Servo servosStrongRight[numServos];
  servosStrongRight[0] = servosHombros[1];

  ajustesStrongRightPCA9685[0][OFFSET]           = posicionesInicialesCodos[1];
  ajustesStrongRightPCA9685[0][PERIODO]          = 800;
  ajustesStrongRightPCA9685[0][AMPLITUD]         = 95;
  ajustesStrongRightPCA9685[0][FASE]             = 180;
  ajustesStrongRightPCA9685[0][DEFAULT]          = 0;

  // ejecutar_movimiento(servosStrongRightPCA9685, ajustesStrongRightPCA9685, numServosPCA9685, 0.5f);

  ajustesStrongRight[0][OFFSET]           = posicionesInicialesHombros[1];
  ajustesStrongRight[0][PERIODO]          = 800;
  ajustesStrongRight[0][AMPLITUD]         = 50;
  ajustesStrongRight[0][FASE]             = 0;
  ajustesStrongRight[0][DEFAULT]          = 0;

  ejecutar_movimiento(servosStrongRightPCA9685, ajustesStrongRightPCA9685, numServosPCA9685, servosStrongRight, ajustesStrongRight, numServos, 0.5f);
}

void mov_lateral_iz(int repeticiones){
  // mov_agacharse(0.25f);
  for (byte loops = 0; loops < repeticiones; loops++) {
    const byte numServosPaso1 = 2;
    short ajustesPaso1[numServosPaso1][5];
    short servosPaso1[numServosPaso1];

    servosPaso1[0] = pinsServosCadera[0];
    servosPaso1[1] = pinsServosCadera[2];

    ajustesPaso1[0][OFFSET]           = posicionesInicialesCadera[0];
    ajustesPaso1[0][PERIODO]          = 250;
    ajustesPaso1[0][AMPLITUD]         = 60;
    ajustesPaso1[0][FASE]             = 0;
    ajustesPaso1[0][DEFAULT]          = 0;

    ajustesPaso1[1][OFFSET]           = posicionesInicialesCadera[2];
    ajustesPaso1[1][PERIODO]          = 250;
    ajustesPaso1[1][AMPLITUD]         = 40;
    ajustesPaso1[1][FASE]             = 0;
    ajustesPaso1[1][DEFAULT]          = 0;
    ejecutar_movimiento(servosPaso1, ajustesPaso1, numServosPaso1, 0.25f);
    delay(100);
    set_servo_position(servosPaso1[0], posicionesInicialesCadera[0]);
    set_servo_position(servosPaso1[1], posicionesInicialesCadera[2]);
    delay(100);
  }
  // init_position();
}

void mov_lateral_de(int repeticiones){
  // mov_agacharse(0.25f);
  for (byte loops = 0; loops < repeticiones; loops++) {
    const byte numServosPaso1 = 2;
    short ajustesPaso1[numServosPaso1][5];
    short servosPaso1[numServosPaso1];

    servosPaso1[0] = pinsServosCadera[0];
    servosPaso1[1] = pinsServosCadera[2];

    ajustesPaso1[0][OFFSET]           = posicionesInicialesCadera[0];
    ajustesPaso1[0][PERIODO]          = 250;
    ajustesPaso1[0][AMPLITUD]         = 40;
    ajustesPaso1[0][FASE]             = 180;
    ajustesPaso1[0][DEFAULT]          = 0;

    ajustesPaso1[1][OFFSET]           = posicionesInicialesCadera[2];
    ajustesPaso1[1][PERIODO]          = 250;
    ajustesPaso1[1][AMPLITUD]         = 60;
    ajustesPaso1[1][FASE]             = 180;
    ajustesPaso1[1][DEFAULT]          = 0;
    ejecutar_movimiento(servosPaso1, ajustesPaso1, numServosPaso1, 0.25f);
    delay(100);
    set_servo_position(servosPaso1[0], posicionesInicialesCadera[0]);
    set_servo_position(servosPaso1[1], posicionesInicialesCadera[2]);
    delay(100);
  }
  // init_position();
}

void mov_SUUUUUPER(){
  init_position();
  delay(120);

  const byte numServosPCA9685 = 9;
  short ajustesSUPERPCA9685[numServosPCA9685][5];
  short servosSUPERPCA9685[numServosPCA9685];

  servosSUPERPCA9685[0] = pinsServosPiernaDerecha[1];
  servosSUPERPCA9685[1] = pinsServosPiernaDerecha[2];
  servosSUPERPCA9685[2] = pinsServosPiernaDerecha[3];
  servosSUPERPCA9685[3] = pinsServosPiernaDerecha[4];
  servosSUPERPCA9685[4] = pinsServosCadera[0];
  servosSUPERPCA9685[5] = pinsServosPiernaIzquierda[0];
  servosSUPERPCA9685[6] = pinsServosPiernaIzquierda[4];
  servosSUPERPCA9685[7] = pinsServosCodos[0];
  servosSUPERPCA9685[8] = pinsServosCodos[1];


  set_servo_position(servosHombros[0], 10);
  set_servo_position(servosHombros[1], 168);
  // const byte numServos = 1;
  // short ajustesSUPER[numServos][5];
  // Servo servosSUPER[numServos];
  // servosSUPER[0] = servosHombros[0];
  // servosSUPER[1] = servosHombros[1];

  // ajustesSUPER[0][OFFSET]           = posicionesInicialesHombros[0];
  // ajustesSUPER[0][PERIODO]          = 2000;
  // ajustesSUPER[0][AMPLITUD]         = 35;
  // ajustesSUPER[0][FASE]             = 180;
  // ajustesSUPER[0][DEFAULT]          = 0;
  //
  // ajustesSUPER[1][OFFSET]           = posicionesInicialesHombros[1];
  // ajustesSUPER[1][PERIODO]          = 2000;
  // ajustesSUPER[1][AMPLITUD]         = 35;
  // ajustesSUPER[1][FASE]             = 0;
  // ajustesSUPER[1][DEFAULT]          = 0;

  ajustesSUPERPCA9685[0][OFFSET]           = posicionesInicialesPiernaDerecha[1];
  ajustesSUPERPCA9685[0][PERIODO]          = 2000;
  ajustesSUPERPCA9685[0][AMPLITUD]         = 35;
  ajustesSUPERPCA9685[0][FASE]             = 0;
  ajustesSUPERPCA9685[0][DEFAULT]          = 0;

  ajustesSUPERPCA9685[1][OFFSET]           = posicionesInicialesPiernaDerecha[2];
  ajustesSUPERPCA9685[1][PERIODO]          = 2000;
  ajustesSUPERPCA9685[1][AMPLITUD]         = 35;
  ajustesSUPERPCA9685[1][FASE]             = 0;
  ajustesSUPERPCA9685[1][DEFAULT]          = 0;

  ajustesSUPERPCA9685[2][OFFSET]           = posicionesInicialesPiernaDerecha[3];
  ajustesSUPERPCA9685[2][PERIODO]          = 2000;
  ajustesSUPERPCA9685[2][AMPLITUD]         = 35;
  ajustesSUPERPCA9685[2][FASE]             = 180;
  ajustesSUPERPCA9685[2][DEFAULT]          = 0;

  ajustesSUPERPCA9685[3][OFFSET]           = posicionesInicialesPiernaDerecha[4];
  ajustesSUPERPCA9685[3][PERIODO]          = 2000;
  ajustesSUPERPCA9685[3][AMPLITUD]         = 35;
  ajustesSUPERPCA9685[3][FASE]             = 180;
  ajustesSUPERPCA9685[3][DEFAULT]          = 0;

  ajustesSUPERPCA9685[4][OFFSET]           = posicionesInicialesCadera[0];
  ajustesSUPERPCA9685[4][PERIODO]          = 2000;
  ajustesSUPERPCA9685[4][AMPLITUD]         = 30;
  ajustesSUPERPCA9685[4][FASE]             = 180;
  ajustesSUPERPCA9685[4][DEFAULT]          = 0;

  ajustesSUPERPCA9685[5][OFFSET]           = posicionesInicialesPiernaIzquierda[0];
  ajustesSUPERPCA9685[5][PERIODO]          = 2000;
  ajustesSUPERPCA9685[5][AMPLITUD]         = 40;
  ajustesSUPERPCA9685[5][FASE]             = 180;
  ajustesSUPERPCA9685[5][DEFAULT]          = 0;

  ajustesSUPERPCA9685[6][OFFSET]           = posicionesInicialesPiernaIzquierda[4];
  ajustesSUPERPCA9685[6][PERIODO]          = 2000;
  ajustesSUPERPCA9685[6][AMPLITUD]         = 40;
  ajustesSUPERPCA9685[6][FASE]             = 180;
  ajustesSUPERPCA9685[6][DEFAULT]          = 0;

  ajustesSUPERPCA9685[7][OFFSET]           = posicionesInicialesCodos[0];
  ajustesSUPERPCA9685[7][PERIODO]          = 2000;
  ajustesSUPERPCA9685[7][AMPLITUD]         = 140;
  ajustesSUPERPCA9685[7][FASE]             = 0;
  ajustesSUPERPCA9685[7][DEFAULT]          = 0;

  ajustesSUPERPCA9685[8][OFFSET]           = posicionesInicialesCodos[1];
  ajustesSUPERPCA9685[8][PERIODO]          = 2000;
  ajustesSUPERPCA9685[8][AMPLITUD]         = 140;
  ajustesSUPERPCA9685[8][FASE]             = 180;
  ajustesSUPERPCA9685[8][DEFAULT]          = 0;

  ejecutar_movimiento(servosSUPERPCA9685, ajustesSUPERPCA9685, numServosPCA9685, 0.25f);

  delay(150);
  nipple_lights = true;

  // ejecutar_movimiento(servosSUPERPCA9685, ajustesSUPERPCA9685, numServosPCA9685, servosSUPER, ajustesSUPER, numServos, 0.5f);
}


/**
* Baja el centro de gravedad para disminuir las posibilidades de caer
*/
void mov_invencible(){
  const byte numServos = 12;
  short ajustesInvencible[numServos][5];
  short servosInvencible[numServos];

  servosInvencible[0] = pinsServosPiernaDerecha[1];
  servosInvencible[1] = pinsServosPiernaDerecha[2];
  servosInvencible[2] = pinsServosPiernaDerecha[3];
  servosInvencible[3] = pinsServosPiernaDerecha[4];
  servosInvencible[4] = pinsServosPiernaIzquierda[1];
  servosInvencible[5] = pinsServosPiernaIzquierda[2];
  servosInvencible[6] = pinsServosPiernaIzquierda[3];
  servosInvencible[7] = pinsServosPiernaIzquierda[4];
  servosInvencible[8] = pinsServosCadera[0];
  servosInvencible[9] = pinsServosCadera[2];
  servosInvencible[10] = pinsServosPiernaDerecha[0];
  servosInvencible[11] = pinsServosPiernaIzquierda[0];

  ajustesInvencible[0][OFFSET]           = posicionesInicialesPiernaDerecha[1];
  ajustesInvencible[0][PERIODO]          = 1000;
  ajustesInvencible[0][AMPLITUD]         = 35;
  ajustesInvencible[0][FASE]             = 0;
  ajustesInvencible[0][DEFAULT]          = 0;

  ajustesInvencible[1][OFFSET]           = posicionesInicialesPiernaDerecha[2];
  ajustesInvencible[1][PERIODO]          = 1000;
  ajustesInvencible[1][AMPLITUD]         = 35;
  ajustesInvencible[1][FASE]             = 0;
  ajustesInvencible[1][DEFAULT]          = 0;

  ajustesInvencible[2][OFFSET]           = posicionesInicialesPiernaDerecha[3];
  ajustesInvencible[2][PERIODO]          = 1000;
  ajustesInvencible[2][AMPLITUD]         = 35;
  ajustesInvencible[2][FASE]             = 180;
  ajustesInvencible[2][DEFAULT]          = 0;

  ajustesInvencible[3][OFFSET]           = posicionesInicialesPiernaDerecha[4];
  ajustesInvencible[3][PERIODO]          = 1000;
  ajustesInvencible[3][AMPLITUD]         = 35;
  ajustesInvencible[3][FASE]             = 180;
  ajustesInvencible[3][DEFAULT]          = 0;

  ajustesInvencible[4][OFFSET]           = posicionesInicialesPiernaIzquierda[1];
  ajustesInvencible[4][PERIODO]          = 1000;
  ajustesInvencible[4][AMPLITUD]         = 35;
  ajustesInvencible[4][FASE]             = 180;
  ajustesInvencible[4][DEFAULT]          = 0;

  ajustesInvencible[5][OFFSET]           = posicionesInicialesPiernaIzquierda[2];
  ajustesInvencible[5][PERIODO]          = 1000;
  ajustesInvencible[5][AMPLITUD]         = 35;
  ajustesInvencible[5][FASE]             = 180;
  ajustesInvencible[5][DEFAULT]          = 0;

  ajustesInvencible[6][OFFSET]           = posicionesInicialesPiernaIzquierda[3];
  ajustesInvencible[6][PERIODO]          = 1000;
  ajustesInvencible[6][AMPLITUD]         = 35;
  ajustesInvencible[6][FASE]             = 0;
  ajustesInvencible[6][DEFAULT]          = 0;

  ajustesInvencible[7][OFFSET]           = posicionesInicialesPiernaIzquierda[4];
  ajustesInvencible[7][PERIODO]          = 1000;
  ajustesInvencible[7][AMPLITUD]         = 35;
  ajustesInvencible[7][FASE]             = 0;
  ajustesInvencible[7][DEFAULT]          = 0;

  ajustesInvencible[8][OFFSET]           = posicionesInicialesCadera[0];
  ajustesInvencible[8][PERIODO]          = 1000;
  ajustesInvencible[8][AMPLITUD]         = 30;
  ajustesInvencible[8][FASE]             = 180;
  ajustesInvencible[8][DEFAULT]          = 0;

  ajustesInvencible[9][OFFSET]           = posicionesInicialesCadera[2];
  ajustesInvencible[9][PERIODO]          = 1000;
  ajustesInvencible[9][AMPLITUD]         = 30;
  ajustesInvencible[9][FASE]             = 0;
  ajustesInvencible[9][DEFAULT]          = 0;

  ajustesInvencible[10][OFFSET]           = posicionesInicialesPiernaDerecha[0];
  ajustesInvencible[10][PERIODO]          = 1000;
  ajustesInvencible[10][AMPLITUD]         = 30;
  ajustesInvencible[10][FASE]             = 0;
  ajustesInvencible[10][DEFAULT]          = 0;

  ajustesInvencible[11][OFFSET]           = posicionesInicialesPiernaIzquierda[0];
  ajustesInvencible[11][PERIODO]          = 1000;
  ajustesInvencible[11][AMPLITUD]         = 30;
  ajustesInvencible[11][FASE]             = 180;
  ajustesInvencible[11][DEFAULT]          = 0;

  ejecutar_movimiento(servosInvencible, ajustesInvencible, numServos, 0.25f);
}
