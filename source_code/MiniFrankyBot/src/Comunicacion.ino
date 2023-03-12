/////////////////////////////////////////////////////////////////////////////////////////
// Este fichero contendrá todas las funciones referentes a la comunicación mediante BT //
// con el mando y a la gestión de comandos.                                            //
/////////////////////////////////////////////////////////////////////////////////////////


/**
* Función que se debería llamar en tiempo de ejecución para comprobar si hay órdenes pendientes
* en el Buffer de comunicación Serial.
* Comprueba si la letra recibida está dentro de la lista de comandos aceptados del fichero Commands.h y
* efectua la operación pertinente.
*
* NOTE: Importante mantener sincronizado el fichero Commands.h en MiniFrankyBot y MiniFrankyBotController para
*       mantener la integridad de los movimientos.
*/
void update_tasks() {
  if (Serial.available()) {
    // Si hay algo pendiente en el Buffer, lo lee y guarda el tiempo en el que lo leyo.
    last_update = millis();
    byte readByte = Serial.read();

    if ((isDigit((char)readByte) || (char)readByte == '.' || (char)readByte == '-')) {
      // Si es un dígito, signo decimal o signo negativo, lo guarda como un valor.
      valor += (char)readByte;
    }else{
      if(letra != ' '){
        // Si es una letra y ya hay otra letra ya leída, ejecuta la acción correspondiente a esa letra.
        execute_task(letra, (valor!="")?valor.toInt():0);
      }
      // Llega una nueva letra; limpia el valor anterior y lee la nueva letra.
      valor = "";
      letra = (char)readByte;
    }
  }else if((millis()-last_update) > 5 && letra != ' '){
    // Si no se ha recibido nada en los últimos 5ms y hay alguna letra pendiente, ejecuta su acción correspondiente.
    execute_task(letra, (valor!="")?valor.toInt():0);
    letra = ' ';
    valor = "";
  }
}

/**
* Ejecuta el comando enviado mediante BT
* @param comando Letra de la lista de comandos del fichero Comandos.h
* @param valor   Valor opcional que se usaría para realizar la acción
*/
void execute_task(char comando, int valor){
  switch (comando) {
    case STRONG_RIGHT:
    mov_StrongRight();
    break;
    case STRONG_LEFT:
    mov_StrongLeft();
    break;
    case SALTITOS:
    mov_salto(1);
    break;
    case SUUUUUUPER:
    mov_SUUUUUPER();
    break;
    case LOWKICK_DERECHA:
    mov_lowkick_derecha(1);
    break;
    case LOWKICK_IZQUIERDA:
    mov_lowkick_izquierda(1);
    break;
    case ROTATE_DERECHA:
    mov_rotate_de(1);
    break;
    case ROTATE_IZQUIERDA:
    mov_rotate_iz(1);
    break;
    case POS_INICIAL:
    invencible = false;
    init_position();
    break;
    case INVINCIBLE_MOD:
    invencible = true;
    mov_invencible();
    break;
    case DESPL_DERECHA:
    mov_lateral_de(1);
    break;
    case DESPL_IZQUIERDA:
    mov_lateral_iz(1);
    break;
    case AGACHARSE:
    mov_agacharse(0.25);
    break;
    case POS_CADERA_D:
    set_servo_position(pinsServosCadera[1], 8);
    break;
    case POS_CADERA_I:
    set_servo_position(pinsServosCadera[1], 108);
    break;
    case POS_CADERA_C:
    set_servo_position(pinsServosCadera[1], posicionesInicialesCadera[1]);
    break;
    default:
    // init_position();
    break;
  }
}
