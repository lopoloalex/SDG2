#include "piMusicBox_1.h"
#include <stdio.h>
#include <string.h>



//------------------------------------------------------
// VARIABLES CON LAS MELODIAS A REPRODUCIR
//------------------------------------------------------
int frecuenciaDespacito[160] = {0,1175,1109,988,740,740,740,740,740,740,988,988,988,988,880,988,784,0,784,784,784,784,784,988,988,988,988,1109,1175,880,0,880,880,880,880,880,1175,1175,1175,1175,1318,1318,1109,0,1175,1109,988,740,740,740,740,740,740,988,988,988,988,880,988,784,0,784,784,784,784,784,988,988,988,988,1109,1175,880,0,880,880,880,880,880,1175,1175,1175,1175,1318,1318,1109,0,1480,1318,1480,1318,1480,1318,1480,1318,1480,1318,1480,1568,1568,1175,0,1175,1568,1568,1568,0,1568,1760,1568,1480,0,1480,1480,1480,1760,1568,1480,1318,659,659,659,659,659,659,659,659,554,587,1480,1318,1480,1318,1480,1318,1480,1318,1480,1318,1480,1568,1568,1175,0,1175,1568,1568,1568,1568,1760,1568,1480,0,1480,1480,1480,1760,1568,1480,1318};
int tiempoDespacito[160] = {1200,600,600,300,300,150,150,150,150,150,150,150,150,300,150,300,343,112,150,150,150,150,150,150,150,150,300,150,300,300,150,150,150,150,150,150,150,150,150,300,150,300,800,300,600,600,300,300,150,150,150,150,150,150,150,150,300,150,300,343,112,150,150,150,150,150,150,150,150,300,150,300,300,150,150,150,150,150,150,150,150,150,300,150,300,450,1800,150,150,150,150,300,150,300,150,150,150,300,150,300,450,450,300,150,150,225,75,150,150,300,450,800,150,150,300,150,150,300,450,150,150,150,150,150,150,150,150,300,300,150,150,150,150,150,150,450,150,150,150,300,150,300,450,450,300,150,150,150,300,150,300,450,800,150,150,300,150,150,300,450};
int frecuenciaGOT[518] = {1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,1175,0,1397,0,932,0,1244,0,1175,0,1397,0,932,0,1244,0,1175,0,1046,0,831,0,698,0,523,0,349,0,784,0,523,0,523,0,587,0,622,0,698,0,784,0,523,0,622,0,698,0,784,0,523,0,622,0,698,0,587,0,698,0,466,0,622,0,587,0,698,0,466,0,622,0,587,0,523,0,523,0,587,0,622,0,698,0,784,0,523,0,622,0,698,0,784,0,523,0,622,0,698,0,587,0,698,0,466,0,622,0,587,0,698,0,466,0,622,0,587,0,523,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1175,0,587,0,622,0,587,0,523,0,587,0,784,0,880,0,932,0,1046,0,1175,0,0,1397,0,0,932,0,0,1244,0,0,1175,0,0,1397,0,0,932,0,0,1244,0,0,1175,0,0,1046,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1175,0,880,0,784,0,932,0,1244,0,0,1397,0,0,932,0,0,1175,0,0,1244,0,0,1175,0,0,932,0,0,1046,0,0,2093,0,622,0,831,0,932,0,1046,0,622,0,831,0,1046,0,0,1865,0,622,0,784,0,831,0,932,0,622,0,784,0,932,0,0,1661,0,523,0,698,0,784,0,831,0,523,0,698,0,831,0,0,1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,0,0,1661,0,1046,0,1175,0,1244,0,831,0,1175,0,1244,0,0,0,0,2489,0,0,0,0,2794,0,0,0,0,3136,0,0,2093,0,622,0,831,0,932,0,1046,0,622,0,831,0,1046,0,0,1865,0,622,0,784,0,831,0,932,0,622,0,784,0,932,0,0,1661,0,523,0,698,0,784,0,831,0,523,0,698,0,831,0,0,1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,0,0,1661,0,1046,0,1175,0,1244,0,831,0,1175,0,1244,0,0,0,0,2489,0,1397,0,0,0,2350,0,0,0,2489,0,0,0,2350,0,0,0,0,2093,0,392,0,415,0,466,0,523,0,392,0,415,0,466,0,523,0,392,0,415,0,466,0,2093,0,1568,0,1661,0,1865,0,2093,0,1568,0,1661,0,1865,0,2093,0,1568,0,1661,0,1865};
int tiempoGOT[518] = {900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1400,1400,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,116,267,28,267,28,267,28,900,89,900,89,1400,89,69,7,69,7,69,7,69,7,900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1800,1800,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,2400,69,7,69,7,69,7,69,7,900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1800,1800,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,2400,3600,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,600,59,600,133,13,150,133,13,150,1200,400,69,7,69,7,69,7,69,7,267,28,400,45,133,13,267,28,267,28,267,28,300,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,900,89,900,133,13,150,133,13,150,1200,1800,3600,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,600,59,600,133,13,150,133,13,150,1200,400,267,28,1200,400,133,13,133,13,150,900,89,900,900,89,900,600,59,600,267,28,300,600,59,600,267,28,300,1200,2400,3600,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,133,13,267,28,267,28,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,150,600,59,133,13,133,13,267,28,267,28,133,13,133,13,150,150,150,900,89,900,900,900,900,89,900,900,900,1200,2400,3600,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,150,600,59,133,13,133,13,267,28,267,28,133,13,133,13,150,150,150,600,212,133,13,150,150,267,28,300,300,400,45,450,450,133,13,150,150,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,267,28,267,28,133,13,2400,116,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,267,28,267,28,133,13,2400};
int frecuenciaTetris[55] = {1319,988,1047,1175,1047,988,880,880,1047,1319,1175,1047,988,988,1047,1175,1319,1047,880,880,0,1175,1397,1760,1568,1397,1319,1047,1319,1175,1047,988,988,1047,1175,1319,1047,880,880,0,659,523,587,494,523,440,415,659,523,587,494,523,659,880,831};
int tiempoTetris[55] = {450,225,225,450,225,225,450,225,225,450,225,225,450,225,225,450,450,450,450,450,675,450,225,450,225,225,675,225,450,225,225,450,225,225,450,450,450,450,450,450,900,900,900,900,900,900,1800,900,900,900,900,450,450,900,1800};
int frecuenciaStarwars[59] = {523,0,523,0,523,0,698,0,1046,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,1760,0,0,784,0,523,0,0,523,0,0,523,0};
int tiempoStarwars[59] = {134,134,134,134,134,134,536,134,536,134,134,134,134,134,134,536,134,402,134,134,429,357,134,134,134,134,536,134,402,134,134,429,357,134,134,134,134,536,134,402,134,134,429,357,134,134,134,429,357,1071,268,67,67,268,67,67,67,67,67};

//------------------------------------------------------
// VARIABLE VOLATILE FLAGS
//------------------------------------------------------
volatile int flags = 0;

// Timeout to avoid bouncing after pin event
int debounceTime;

// Funcion que se ejecuta al finalizar el timer usado en la maquina de estados player
void timer_isr (union sigval value) {
	piLock (FLAGS_KEY);
	flags |= FLAG_NOTA_TIMEOUT;
	piUnlock (FLAGS_KEY);
}

// Funcion encargada de responder ante las interrupciones externas
// detecta tarjeta insertada ante bajadas.
void interrupcionStart (void) {

	if (millis() < debounceTime){
		debounceTime = millis() + DEBOUNCE_TIME;
		return;
	}
	if (digitalRead(GPIO_BUTTON1)==LOW){
		printf("Tarjeta detectada\n");

		piLock (FLAGS_KEY);
		flags |= FLAG_CARD_IN;
		piUnlock (FLAGS_KEY);
	} else {
		printf("Tarjeta retirada\n");

		piLock (FLAGS_KEY);
		flags &= ~FLAG_CARD_IN; // activa tarjetaNoDisponible y se va a cancelaReproduccion--FLAGSTOP activo--para melodia--pasa a waitstart
		flags |= FLAG_SYSTEM_START; // para q se reinicie

		piUnlock (FLAGS_KEY);
	}


	debounceTime = millis()+DEBOUNCE_TIME;
}


// espera hasta la próxima activación del reloj
void delay_until (unsigned int next) {
	unsigned int now = millis();
	if (next > now) {
		delay (next - now);
	}
}

//------------------------------------------------------
// FUNCIONES DE ENTRADA O COMPROBACION
//------------------------------------------------------

// Conjunto de funciones de comprobacion conforme a la maquina
// de estados propuesto en el enunciado para la reproduccion
// Comprueban si el flag esta activo o no 

// FUNCIONES PLAYER

// Metodo encargados de comprobar el FLAG_PLAYER_START
int CompruebaPlayerStart (fsm_t* this) {
	int result = 0;
	piLock (FLAGS_KEY);

	result = (flags & FLAG_PLAYER_START);

	piUnlock (FLAGS_KEY);


	return result;
}

// Metodo encargados de comprobar el FLAG_PLAYER_STOP
int CompruebaPlayerStop (fsm_t* this) {
	int result = 0;
	piLock (FLAGS_KEY);

	result = (flags & FLAG_PLAYER_STOP);

	piUnlock (FLAGS_KEY);

	return result;
}

// Metodo encargados de comprobar el FLAG_NOTA_TIMEOUT
int CompruebaNotaTimeout(fsm_t* this){
	int result = 0;
	piLock (FLAGS_KEY);

	result = (flags & FLAG_NOTA_TIMEOUT);

	piUnlock (FLAGS_KEY);
	return result;
}

// Metodos encargados de comprobar el FLAG_PLAYER_END.
// Consideramos que si FLAG_PLAYER_END esta desactivado
// CompruebaNuevaNota nos devuelve un 1.
int CompruebaFinalMelodia (fsm_t* this) {
	int result = 0;
	piLock (FLAGS_KEY);

	result = (flags & FLAG_PLAYER_END);

	piUnlock (FLAGS_KEY);
	return result;
}

int CompruebaNuevaNota (fsm_t* this) {
	int result = 0;
	piLock (FLAGS_KEY);

	result = (flags & FLAG_PLAYER_END);

	piUnlock (FLAGS_KEY);
	return !result;
}

// FUNCIONES SISTEMA

// Metodo encargados de comprobar el FLAG_SYSTEM_START
int CompruebaComienzo (fsm_t* this) {
	int result = 0;
	piLock (FLAGS_KEY);

	result = (flags & FLAG_SYSTEM_START);

	piUnlock (FLAGS_KEY);


	return result;
}

//Metodos encargado de comprobar el FLAG_CARD_IN
int TarjetaNoDisponible (fsm_t* this) {
	int result = 0;
	piLock (FLAGS_KEY);

	result = (flags & FLAG_CARD_IN);

	piUnlock (FLAGS_KEY);


	return !result;
}

int TarjetaDisponible (fsm_t* this) {
	int result = 0;
	piLock (FLAGS_KEY);

	result = (flags & FLAG_CARD_IN);

	piUnlock (FLAGS_KEY);


	return result;
}

//Metodos encargado de comprobar el FLAG_CVALID_CARD
int TarjetaNoValida (fsm_t* this) {
	int result = 0;
	piLock (FLAGS_KEY);

	result = (flags & FLAG_VALID_CARD);

	piUnlock (FLAGS_KEY);


	return !result;
}

int TarjetaValida (fsm_t* this) {
	int result = 0;
	piLock (FLAGS_KEY);

	result = (flags & FLAG_VALID_CARD);

	piUnlock (FLAGS_KEY);


	return result;
}

//Metodo encargado de comprobar el FLAG_SYSTEM_OUT
int CompruebaFinalReproduccion (fsm_t* this){
	int result = 0;
	piLock (FLAGS_KEY);

	result = (flags & FLAG_SYSTEM_END);

	piUnlock (FLAGS_KEY);


	return result;
}


//------------------------------------------------------
// FUNCIONES DE SALIDA O ACTUALIZACION
//------------------------------------------------------

// FUNCIONES PLAYER


/**
 * @brief				Metodo que inicializa la reproduccion de la melodia. 
 * @param	this		Maquina de estados que ejecuta este metodo, contiene dentro un Struct TipoPlayer.
 * @note				Reproduce la primera nota gracias a un timer 
 */
void InicializaPlayer (fsm_t* this){

	TipoPlayer *p_player;
	p_player = (TipoPlayer*)(this->user_data);

	tmr_t* tmr = tmr_new (timer_isr);//timer encargado de reproducir las notas.
	p_player->timer_nota=tmr;

	p_player->posicion_nota_actual=0;//inicializa posicion nota actual = 0
	p_player->duracion_nota_actual = p_player->melodia.duraciones[p_player->posicion_nota_actual];	//duracion nota actual alomejor es mas facil poner 0 directamente
	p_player->frecuencia_nota_actual = p_player->melodia.frecuencias[p_player->posicion_nota_actual];// frecuencia nota actual
	printf("Iniciamos Cancion\n");


	printf("Nota numero %d/%d Frecuencia de la nota actual: %d Duracion de la nota actual: %d \n",p_player->posicion_nota_actual+1,p_player->melodia.num_notas,p_player->frecuencia_nota_actual,p_player->duracion_nota_actual );
	softToneWrite(GPIO_BUTTON17,p_player->frecuencia_nota_actual);
	tmr_startms(p_player->timer_nota, p_player->duracion_nota_actual);

	piLock (FLAGS_KEY);
	flags &= ~FLAG_PLAYER_START;
	piUnlock (FLAGS_KEY);

}

/**
 * @brief			Actualiza el valor a reproducir.
 * @param	this	Maquina de estados que ejecuta este metodo, contiene dentro un Struc TipoPlayer	
 */
void ActualizaPlayer (fsm_t* this){

	TipoPlayer *p_player;
	p_player = (TipoPlayer*)(this->user_data);


	//Suma uno a la posicion nota
	p_player->posicion_nota_actual=p_player->posicion_nota_actual+1;
	//duracion nota actual
	p_player->duracion_nota_actual = p_player->melodia.duraciones[p_player->posicion_nota_actual];
	// frecuencia nota actual
	p_player->frecuencia_nota_actual = p_player->melodia.frecuencias[p_player->posicion_nota_actual];


	piLock (FLAGS_KEY);
	flags &= ~FLAG_NOTA_TIMEOUT;
	piUnlock (FLAGS_KEY);



}

/**
 * @brief			Reproduce la nota y comprueba si aun quedan mas notas
 * @param	this	Maquina de estados que ejecuta este metodo, contiene dentro un Struc TipoPlayer	
 */
void ComienzaNuevaNota (fsm_t* this ){

	TipoPlayer *p_player;
	p_player = (TipoPlayer*)(this->user_data);

	if (p_player->posicion_nota_actual < p_player->melodia.num_notas){

		// en este print sumo 1 a posicion de nota actual ya que el array se recorre de 0 a 58
		//pero las notas van de 1 a 59 en el caso de Starwars
		printf("Nota numero %d/%d Frecuencia de la nota actual: %d Duracion de la nota actual: %d \n",p_player->posicion_nota_actual+1,p_player->melodia.num_notas,p_player->frecuencia_nota_actual,p_player->duracion_nota_actual );
		softToneWrite(GPIO_BUTTON17,p_player->frecuencia_nota_actual);
		tmr_startms(p_player->timer_nota, p_player->duracion_nota_actual);


	}else { 

		piLock (FLAGS_KEY);
		flags |= FLAG_NOTA_TIMEOUT;
		flags |= FLAG_PLAYER_END;
		piUnlock (FLAGS_KEY);
	}
}

/**
 * @brief			Finaliza la reproduccion de la melodia
 * @param	this	Maquina de estados que ejecuta este metodo, contiene dentro un Struc TipoPlayer	
 */
void FinalMelodia (fsm_t* this){

	TipoPlayer *p_player;
	p_player = (TipoPlayer*)(this->user_data);
	tmr_destroy (p_player->timer_nota);

	p_player->posicion_nota_actual=-1;
	printf("FINAL MELODIA\n");
	softToneWrite(GPIO_BUTTON17,0);

	piLock (FLAGS_KEY);
	flags &= ~FLAG_PLAYER_END;
	flags |= FLAG_SYSTEM_END;
	piUnlock (FLAGS_KEY);
}

/**
 * @brief			Para la reproduccion de la melodia 
 * @param	this	Maquina de estados que ejecuta este metodo, contiene dentro un Struc TipoPlayer	
 */
void StopPlayer (fsm_t* this){

	TipoPlayer *p_player;
	p_player = (TipoPlayer*)(this->user_data);

	printf("MELODIA PARADA\n");
	tmr_destroy (p_player->timer_nota);
	softToneWrite(GPIO_BUTTON17,0);

	piLock (FLAGS_KEY);
	flags &= ~FLAG_PLAYER_STOP;
	piUnlock (FLAGS_KEY);
}

// FUNCIONES SISTEMA

/**
 * @brief			Comienza el sistema y reinicia los flags 
 * @param	this	Maquina de estados que ejecuta este metodo, contiene dentro un Struc TipoSistema	
 */
void ComienzaSistema (fsm_t* this){

	printf("Sistema listo\n");

	piLock (FLAGS_KEY);
	flags = 0;
	piUnlock (FLAGS_KEY);

}

/**
 * @brief			Funcion de transito
 * @param	this	Maquina de estados que ejecuta este metodo, contiene dentro un Struc TipoSistema	
 */
void EsperoTarjeta (fsm_t* this){

}

/**
 * @brief			Lee la tarjeta y decide si el valida o no
 * @param	this	Maquina de estados que ejecuta este metodo, contiene dentro un Struc TipoSistema	
 */
void LeerTarjeta (fsm_t* this){


	TipoSistema *p_sistema; //apunta al sist del main xq le pasa el this (maquina de estado)
	p_sistema = (TipoSistema*)(this->user_data); // cast--fuerzas a q sea tiposistema

	char card_id[100];
	initialize_rfid();
	strcpy(card_id, read_id()); // copiar lo q lee en el rfid en card_id

	int a;
	int b=0; // para uidB
	for (a=0;a<8;a=a+2){
		p_sistema->uid_tarjeta_actual.uidByte[b]= 16*Transformar(card_id[a])+Transformar(card_id[a+1]);
		b++;
	}
	int i;
	for(i=0;i<100;i++){
		p_sistema->uid_tarjeta_actual_string[i]=card_id[i];

	}
	p_sistema->uid_tarjeta_actual.size = 8;  //mirar si pto 8 tb es size 8
	// Y comprobamos su validez...
	int aux = CheckCardValidity (p_sistema); // no pones & xq ya es puntero de antes
	if (aux >= 0) { //aux==indice array tarjeta de datos q metemos
		p_sistema->player.melodia=p_sistema->tarjetas_activas[aux].melodia;// x esto hemos cambiado el puntero de melodia

		// Tarjeta valida
		printf("Valid card!!!\n");
		fflush(stdout);
		piLock (FLAGS_KEY);
		flags |= FLAG_VALID_CARD;
		piUnlock (FLAGS_KEY);

	}
	else {
		// Tarjeta NO valida
		printf("Invalid card!!!\n");
		fflush(stdout);
		piLock (FLAGS_KEY);
		flags &= ~FLAG_VALID_CARD;
		piUnlock (FLAGS_KEY);

	}


}

/**
 * @brief			 Comprueba si la tarjeta leida es una de las almacenadas o no
 * @param	sistema	 Puntero a un Struc TipoSistema	
 */
int CheckCardValidity (TipoSistema *sistema) {
	int i;
	int a;
	for ( i=0 ; i < 5 ; i++ ){

		int b=0;
			for (a=0;a<10;a++){
				if(sistema->tarjetas_activas[i].uid.uidByte[a]==sistema->uid_tarjeta_actual.uidByte[a]) {
					b++;
				}

			}
		if(b>3){


			return i; //tarjeta
		}

	}
	return -1;
}


/**
 * @brief			En caso de no ser valida se considera que no hay tarjeta insertada
 * @param	this	Maquina de estados que ejecuta este metodo, contiene dentro un Struc TipoSistema	
 */
void DescartaTarjeta (fsm_t* this){
	///Borro el fichero txt con los datos de la tarjeta
	//alomejor hay que resetear tambien uidByte
	piLock (FLAGS_KEY);
	flags &= ~ FLAG_CARD_IN;
	piUnlock (FLAGS_KEY);

}

/**
 * @brief			Da paso a la inicializacion de la melodia 
 * @param	this	Maquina de estados que ejecuta este metodo, contiene dentro un Struc TipoSistema	
 */
void ComienzaReproduccion (fsm_t* this){
	piLock (FLAGS_KEY);
	flags |= FLAG_PLAYER_START;
	flags  &= ~ FLAG_VALID_CARD;
	piUnlock (FLAGS_KEY);

}

/**
 * @brief			Funcion de transito
 * @param	this	Maquina de estados que ejecuta este metodo, contiene dentro un Struc TipoSistema	
 */
void ComprueboTarjeta (fsm_t* this){

}

/**
 * @brief			En caso de cancelacion para el player
 * @param	this	Maquina de estados que ejecuta este metodo, contiene dentro un Struc TipoSistema	
 */
void CancelaReproduccion (fsm_t* this){

	piLock (FLAGS_KEY);
	flags |= FLAG_PLAYER_STOP;
	piUnlock (FLAGS_KEY);

}

/**
 * @brief			Da fin al sistema y lo resetea
 * @param	this	Maquina de estados que ejecuta este metodo, contiene dentro un Struc TipoSistema	
 */
void FinalizaReproduccion (fsm_t* this){
	piLock (FLAGS_KEY);
	flags &= ~FLAG_SYSTEM_END;
	flags |= FLAG_SYSTEM_START;
	piUnlock (FLAGS_KEY);

}


//------------------------------------------------------
// FUNCIONES DE CONFIGURACION INICIAL
//------------------------------------------------------

/**
 * @brief								Inicializa los elementos de una melodia que se pasa como parametro.
 * @param	*melodia					Struct que almacena la melodia
 * @param	*nombre						Char con el nombre de la melodia
 * @param	*array_frecuencias			Array con las frecuencias de las notas
 * @param	*array_duraciones			Array con la duracion de las notas
 * @param	num_notas					Entero con el numero total de notas

 * @return			Devuelve el numero de notas de la canción
 */
int InicializaMelodia (TipoMelodia *melodia, char *nombre, int *array_frecuencias, int *array_duraciones, int num_notas) {


	strcpy( melodia->nombre , nombre);
	melodia->num_notas=num_notas;
	int i;
	for ( i=0 ; i < num_notas ; i++ ){
		melodia->frecuencias[i]=array_frecuencias[i];
		melodia->duraciones[i]=array_duraciones[i];
	}
	return melodia->num_notas;
}

/**
 * @brief				procedimiento de configuracion del sistema.
 * 						Realizará, entra otras, todas las operaciones necesarias para:
 * 						configurar el uso de posibles librerías (e.g. Wiring Pi),
 * 						configurar las interrupciones externas asociadas a los pines GPIO,
 * 						configurar las interrupciones periódicas y sus correspondientes temporizadores,
 * 						crear, si fuese necesario, los threads adicionales que pueda requerir el sistema
 */
int systemSetup (void) {
	int x = 0;

	piLock (STD_IO_BUFFER_KEY);

	// sets up the wiringPi library
	if (wiringPiSetupGpio () < 0) {
		printf ("Unable to setup wiringPi\n");
		piUnlock (STD_IO_BUFFER_KEY);
		return -1;
	}
	softToneCreate(GPIO_BUTTON17);
	pinMode (GPIO_BUTTON1, INPUT);
	wiringPiISR (GPIO_BUTTON1,INT_EDGE_BOTH , &interrupcionStart) ;




	// Lanzamos thread para exploracion del teclado convencional del PC
	x = piThreadCreate (thread_explora_teclado); // @suppress("Symbol is not resolved")
	if (x != 0) {
		printf ("it didn't start!!!\n");
		piUnlock (STD_IO_BUFFER_KEY);
		return -1;
	}

	piUnlock (STD_IO_BUFFER_KEY);

	return 1;
}

/**
 * @brief				Configuracion de los flags
 * @param	luz_fsm		Maquina de estados.	
 */
void fsm_setup(fsm_t* luz_fsm) {
	piLock (FLAGS_KEY);
	flags = 0;
	piUnlock (FLAGS_KEY);


	piLock (STD_IO_BUFFER_KEY);
	piUnlock (STD_IO_BUFFER_KEY);
}




//------------------------------------------------------
// PI_THREAD (thread_explora_teclado): Thread function for keystrokes detection and interpretation
// Creada en systemSetup 
//------------------------------------------------------

PI_THREAD (thread_explora_teclado) {
	int teclaPulsada;

	while (1) {
		delay(10);
		piLock (STD_IO_BUFFER_KEY);

		if(kbhit()) { // Funcion que detecta si se ha producido pulsacion de tecla alguna
			teclaPulsada = kbread(); // Funcion que devuelve la tecla pulsada

			printf("\n[KBHIT][%c]\n", teclaPulsada);
			switch(teclaPulsada) {
			case 's':
				piLock (FLAGS_KEY);
				flags |= FLAG_PLAYER_START;
				piUnlock (FLAGS_KEY);
				break;

			case 't':
				piLock (FLAGS_KEY);
				//flags |= FLAG_PLAYER_STOP;
				piUnlock (FLAGS_KEY);
				break;

			case 'q':
				exit(0);
				break;

			default:
				printf("INVALID KEY!!!\n");
				break;
			}


		}
		piUnlock (STD_IO_BUFFER_KEY);
	}
}



//Programa principal donde se inicia y configuran las variables y las distintas maquinas de estados del sistema
int main () {

	unsigned int next;


	//CONFIGURACION INICIAL DEL SISTEMA
	TipoSistema sistema;
	TipoPlayer player1;	 //Declaramos player y le asignamos la melodia a reproducir
	sistema.player=player1;	 //Anadimos a sistema player1

	//DECLARAR LAS TARJETAS VALIDAS
	TipoTarjeta tarjeta1;
	TipoMelodia Melodia1;
	InicializaMelodia (&Melodia1 , "Starwars" , frecuenciaStarwars , tiempoStarwars, 59);
	tarjeta1.melodia=Melodia1; //cargar melodía a tarjeta1
	tarjeta1.uid.size=8;

	tarjeta1.uid.uidByte[0]=22;
	tarjeta1.uid.uidByte[1]=55;
	tarjeta1.uid.uidByte[2]=170;
	tarjeta1.uid.uidByte[3]=41;


//	tarjeta1.uid.uidByte[0]=224;
//	tarjeta1.uid.uidByte[1]=158;
//	tarjeta1.uid.uidByte[2]=144;
//	tarjeta1.uid.uidByte[3]=21;

	sistema.tarjetas_activas[0]=tarjeta1;

	TipoTarjeta tarjeta2;
	TipoMelodia Melodia2;
	InicializaMelodia (&Melodia2 , "Despacito" , frecuenciaDespacito , tiempoDespacito,160);
	tarjeta2.melodia=Melodia2;
	tarjeta2.uid.size=8;
	tarjeta2.uid.uidByte[0]=62;
	tarjeta2.uid.uidByte[1]=35;
	tarjeta2.uid.uidByte[2]=160;
	tarjeta2.uid.uidByte[3]=89;

	sistema.tarjetas_activas[1]=tarjeta2;



	/* TABLA DE TRANSICIONES PARA LA MAQUINA DE ESTADOS */
	fsm_trans_t reproductor[] = {
			{ WAIT_START, CompruebaPlayerStart, WAIT_PUSH, InicializaPlayer },
			{ WAIT_PUSH, CompruebaPlayerStop, WAIT_START, StopPlayer },
			{ WAIT_PUSH, CompruebaNotaTimeout, WAIT_END, ActualizaPlayer },
			{ WAIT_END, CompruebaNuevaNota, WAIT_PUSH, ComienzaNuevaNota },
			{ WAIT_END, CompruebaFinalMelodia, WAIT_START, FinalMelodia },
			{-1, NULL, -1, NULL },
	};
	fsm_trans_t detector[] = {
			{ WAIT_START2,CompruebaComienzo, WAIT_CARD, ComienzaSistema },
			{ WAIT_CARD, TarjetaNoDisponible, WAIT_CARD, EsperoTarjeta },
			{ WAIT_CARD, TarjetaDisponible, WAIT_CHECK, LeerTarjeta },
			{ WAIT_CHECK, TarjetaNoValida, WAIT_CARD, DescartaTarjeta },
			{ WAIT_CHECK, TarjetaValida, WAIT_PLAY, ComienzaReproduccion },
			{ WAIT_PLAY, CompruebaFinalReproduccion, WAIT_START2,FinalizaReproduccion },
			{ WAIT_PLAY, TarjetaDisponible, WAIT_PLAY, ComprueboTarjeta },
			{ WAIT_PLAY, TarjetaNoDisponible, WAIT_START2,CancelaReproduccion },
			{-1, NULL, -1, NULL },
	};

	//Maquina de estados player
	fsm_t* player_fsm_tmr = fsm_new (WAIT_START, reproductor, &(sistema.player));
	fsm_t* tarjeta_fsm_tmr = fsm_new (WAIT_START2, detector, &(sistema));

	systemSetup ();
	fsm_setup (player_fsm_tmr);
	fsm_setup (tarjeta_fsm_tmr); // inicializa la variable flag a 0

	printf("Sistema listo para ser utilizado");
	piLock (FLAGS_KEY);
	flags |= FLAG_SYSTEM_START;
	piUnlock (FLAGS_KEY);




	next = millis(); // cada next se mira todo y decide
	while (1) {
		fsm_fire (player_fsm_tmr);
		fsm_fire(tarjeta_fsm_tmr); //actualiza la maquina de estados--produce los saltos
		next += CLK_MS;
		delay_until (next);
	}
	fsm_destroy (player_fsm_tmr);
	fsm_destroy(tarjeta_fsm_tmr);

}


//Metodo que transforma un char que representa un numero hex a su int en decimal
int Transformar (char a){





	int c;

		  switch(a) {

		  	  case '0':

		  		  c= 0;

		  		  break;

		  	  case '1':

		  		  c= 1;

		  		  break;

		  	  case '2':

		  		  c= 2;

		  		  break;

		  	  case '3':

		  		  c= 3;

		  		  break;

		  	  case '4':

		  		  c= 4;

		  		  break;

		  	  case '5':

		  		  c= 5;

		  		  break;

		  	  case '6':

		  		  c= 6;

		  		  break;

		  	  case '7':

		  		  c= 7;

		  		  break;

		  	  case '8':

		  		  c= 8;

		  		  break;

		  	  case '9':

		  		  c= 9;

		  		  break;

		      case 'A' :

		    	  	  c = 10;

		    	  	  break;

		      case 'B' :

	    	  	  	  c = 11;

	    	  	  	  break;

	    	  	  case 'C' :

	    	  		  c=12;

	    	  		  break;

		      case 'D' :

		    	  	  c=13;

				  break;

		      case 'E':

		    	  	  c=14;

		    	  	  break;

		      case 'F' :

		    	  	  c=15;

		    	  	  break;

		      default :

		    	  	  c= 0;

		  }



		 return c;

}
