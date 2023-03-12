////////////////////////////////////////////////////////////////////////
// Este fichero contendrá todas las funciones responsables de asignar //
// posiciones y gestionar movimientos de todos los servos             //
////////////////////////////////////////////////////////////////////////


/**
* Función sobrecargada para asignar cierto offset(ángulo) a cada uno de los servos conectados a la PCA9685.
* La funcion también mapea el ángulo introducido desde un rango de 0-180 hasta el ancho de pulso máx.-mín.
* @param id_servo     Índice del servo al que se quiere ajustar el ángulo. Corresponde con los números de la PCA9685.
* @param servo_offset Offset o ángulo a asignar al servo.
*/
void set_servo_position(int id_servo, int servo_offset){
  posicionesActualesPCA9685[id_servo] = servo_offset;
  servoController.setPWM(id_servo, 0, map(servo_offset, 0, 180, (int)SERVOMIN, (int)SERVOMAX));
}

void disable_servo(int id_servo){
  servoController.setPWM(id_servo, 0, 0);
}

void disable_servo(Servo servo){
  servo.detach();
}

/**
* Función sobrecargada para asigarn cierto offset(ángulo) a cada uno de los servos conectados directamente al Arduino.
* En este caso no hace falta mapear porque la librería Servo.h encargada de sus posiciones ya trabaja con ángulos nativamente.
* @param servo        Objeto Servo attacheado al servo que al que se quiere asignar el ángulo
* @param servo_offset Offset o ángulo a asigar al servo.
*/
void set_servo_position(Servo servo, int servo_offset){
  servo.write(servo_offset);
}

/**
* Función base para la ejecución de movimientos coordinados basados en la librería Oscillator, para gestionar correctamente
* las funciones senoidales, asi como su duración y repeticiones.
* @param servosMovimiento  Índices de los servos que se usarán en el movimiento, coincidiendo con sus números en la PCA9685
* @param ajustesMovimiento Array bidimensional cuya primera dimensión coincide con el número de servos a usar y segunda
*                          dimensión contiene los ajustes de OFFSET, PERIODO, AMPLITUD, FASE y DEFAULT de cada uno de los servos
*                          para realizar el movimiento.
* @param numServos         Número de servos que componen el movimiento a realizar para definir el límite de los búcles
* @param repeticiones      Número de veces que se repetirá el movimiento. Admite valores decimales.
*                          Ej.: 1/4 de movimiento serían 0.25 repeticiones.
*/
void ejecutar_movimiento(short servosMovimiento[], short ajustesMovimiento[][5], byte numServos, float repeticiones) {
  // Crea e inicia los osciladores según los ajustes de cada servo.
  Oscillator oscillatorMovimiento[numServos];
  for (byte servo = 0; servo < numServos; servo++) {
    oscillatorMovimiento[servo].setOffset(ajustesMovimiento[servo][OFFSET]);
    oscillatorMovimiento[servo].setPeriod(ajustesMovimiento[servo][PERIODO]);
    oscillatorMovimiento[servo].setAmplitude(ajustesMovimiento[servo][AMPLITUD]);
    oscillatorMovimiento[servo].setPhase(ajustesMovimiento[servo][FASE]);
    oscillatorMovimiento[servo].start();
    oscillatorMovimiento[servo].setTime(millis());
  }

  // Inicia el contador de servos parados e inicia el bucle del movimiento mientras haya servos en movimiento.
  byte countStopped = 0;
  do {
    for (byte servo = 0; servo < numServos; servo++) {
      set_servo_position(servosMovimiento[servo], oscillatorMovimiento[servo].refresh());
      if (repeticiones > 0 && oscillatorMovimiento[servo].getLoops() >= repeticiones && oscillatorMovimiento[servo].isRunning()) {
        oscillatorMovimiento[servo].stop();
        countStopped++;
        if (ajustesMovimiento[servo][DEFAULT]) {
          set_servo_position(servosMovimiento[servo], ajustesMovimiento[servo][OFFSET]);
        }
      }
    }
  } while (countStopped < numServos);
}


/**
* Función base para la ejecución de movimientos coordinados y combinados entre la placa PCA9685 y los servos de Arduino basados en la librería Oscillator, para gestionar correctamente
* las funciones senoidales, asi como su duración y repeticiones.
* @param servosMovimientoPCA9585    Índices de los servos que se usarán en el movimiento, coincidiendo con sus números en la PCA9685
* @param ajustesMovimientoPCA9585   Array bidimensional cuya primera dimensión coincide con el número de servos a usar y segunda
*                                   dimensión contiene los ajustes de OFFSET, PERIODO, AMPLITUD, FASE y DEFAULT de cada uno de los servos
*                                   para realizar el movimiento.
* @param numServosPCA9585           Número de servos que componen el movimiento a realizar para definir el límite de los búcles
* @param servosMovimiento           Índices de los servos que se usarán en el movimiento, coincidiendo con sus números en la PCA9685
* @param ajustesMovimiento          Array bidimensional cuya primera dimensión coincide con el número de servos a usar y segunda
*                                   dimensión contiene los ajustes de OFFSET, PERIODO, AMPLITUD, FASE y DEFAULT de cada uno de los servos
*                                   para realizar el movimiento.
* @param numServos                  Número de servos que componen el movimiento a realizar para definir el límite de los búcles
* @param repeticiones               Número de veces que se repetirá el movimiento. Admite valores decimales.
*                                   Ej.: 1/4 de movimiento serían 0.25 repeticiones.
*/
void ejecutar_movimiento(short servosMovimientoPCA9685[], short ajustesMovimientoPCA9685[][5], byte numServosPCA9685, Servo servosMovimiento[], short ajustesMovimiento[][5], byte numServos, float repeticiones) {
  // Crea e inicia los osciladores según los ajustes de cada servo de la PCA9685.
  Oscillator oscillatorMovimientoPCA9685[numServosPCA9685];
  for (byte servoPCA9685 = 0; servoPCA9685 < numServos; servoPCA9685++) {
    oscillatorMovimientoPCA9685[servoPCA9685].setOffset(ajustesMovimientoPCA9685[servoPCA9685][OFFSET]);
    oscillatorMovimientoPCA9685[servoPCA9685].setPeriod(ajustesMovimientoPCA9685[servoPCA9685][PERIODO]);
    oscillatorMovimientoPCA9685[servoPCA9685].setAmplitude(ajustesMovimientoPCA9685[servoPCA9685][AMPLITUD]);
    oscillatorMovimientoPCA9685[servoPCA9685].setPhase(ajustesMovimientoPCA9685[servoPCA9685][FASE]);
    oscillatorMovimientoPCA9685[servoPCA9685].start();
    oscillatorMovimientoPCA9685[servoPCA9685].setTime(millis());
  }

  // Crea e inicia los osciladores según los ajustes de cada servo.
  Oscillator oscillatorMovimiento[numServos];
  for (byte servo = 0; servo < numServos; servo++) {
    oscillatorMovimiento[servo].setOffset(ajustesMovimiento[servo][OFFSET]);
    oscillatorMovimiento[servo].setPeriod(ajustesMovimiento[servo][PERIODO]);
    oscillatorMovimiento[servo].setAmplitude(ajustesMovimiento[servo][AMPLITUD]);
    oscillatorMovimiento[servo].setPhase(ajustesMovimiento[servo][FASE]);
    oscillatorMovimiento[servo].start();
    oscillatorMovimiento[servo].setTime(millis());
  }

  // Inicia el contador de servos parados e inicia el bucle del movimiento mientras haya servos en movimiento.
  byte countStopped = 0;
  do {
    for (byte servoPCA9685 = 0; servoPCA9685 < numServosPCA9685; servoPCA9685++) {
      set_servo_position(servosMovimientoPCA9685[servoPCA9685], oscillatorMovimientoPCA9685[servoPCA9685].refresh());
      if (repeticiones > 0 && oscillatorMovimientoPCA9685[servoPCA9685].getLoops() >= repeticiones && oscillatorMovimientoPCA9685[servoPCA9685].isRunning()) {
        oscillatorMovimientoPCA9685[servoPCA9685].stop();
        countStopped++;
        if (ajustesMovimientoPCA9685[servoPCA9685][DEFAULT]) {
          set_servo_position(servosMovimientoPCA9685[servoPCA9685], ajustesMovimientoPCA9685[servoPCA9685][OFFSET]);
        }
      }
    }
    for (byte servo = 0; servo < numServos; servo++) {
      set_servo_position(servosMovimiento[servo], oscillatorMovimiento[servo].refresh());
      if (repeticiones > 0 && oscillatorMovimiento[servo].getLoops() >= repeticiones && oscillatorMovimiento[servo].isRunning()) {
        oscillatorMovimiento[servo].stop();
        countStopped++;
        if (ajustesMovimiento[servo][DEFAULT]) {
          set_servo_position(servosMovimiento[servo], ajustesMovimiento[servo][OFFSET]);
        }
      }
    }
  } while (countStopped < (numServos+numServosPCA9685));
}
