/*
 * piMusicBox_1.h
 *
 *  Created on: 11 de sep. de 2017
 *      Author: FFM, Alejandro Perez Parra, Adriana De Pablo Moreno
 */

#ifndef PIMUSICBOX_1_H_
#define PIMUSICBOX_1_H_

//------------------------------------------------------
// INCLUDE USADOS
//------------------------------------------------------
#include <stdlib.h> // para poder usar NULL
#include <stdio.h> // para poder usar printf
#include <time.h>
#include <stdint.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <wiringPi.h>
#include <softTone.h>
#include "kbhit.h"
#include "fsm.h"
#include "tmr.h"
#include "rfid.h"




//------------------------------------------------------
// DEFINE RELOJ
//------------------------------------------------------
#define CLK_MS 10//Periodo de actualizacion maquina
#define DEBOUNCE_TIME 200
//------------------------------------------------------
// DEFINE GPIN UTILIZADOS
//------------------------------------------------------
#define GPIO_BUTTON17	18   //Gpin 18 - 17 de TL
#define GPIO_BUTTON1	5
//------------------------------------------------------
//DEFINE DE FLAGS
//------------------------------------------------------
#define FLAG_PLAYER_START 0x01
#define FLAG_PLAYER_STOP  0x02
#define FLAG_PLAYER_END   0x04
#define FLAG_NOTA_TIMEOUT 0x08

#define FLAG_SYSTEM_START 0x10
#define FLAG_CARD_IN 0x20
#define FLAG_VALID_CARD 0x40
#define FLAG_SYSTEM_END 0x80


#define	FLAGS_KEY	1
#define	STD_IO_BUFFER_KEY	2

//------------------------------------------------------
// FUNCIONES DE ENTRADA O DE TRANSICION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------
int CompruebaPlayerStart (fsm_t* this);
int CompruebaPlayerStop (fsm_t* this);
int CompruebaFinalMelodia (fsm_t* this);
int CompruebaNuevaNota (fsm_t* this);
int CompruebaNotaTimeout(fsm_t* this);

int CompruebaComienzo (fsm_t* this);
int TarjetaNoDisponible (fsm_t* this);
int TarjetaDisponible (fsm_t* this);
int TarjetaNoValida (fsm_t* this);
int TarjetaValida (fsm_t* this);
int CompruebaFinalReproduccion (fsm_t* this);


//------------------------------------------------------
// FUNCION ANTE INTERRUPCION EXTERNA
//------------------------------------------------------
void interrupcionStart(void);

//------------------------------------------------------
// FUNCIONES DE SALIDA O DE ACCION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------
void ProcedimientoDummyQueNoHaceNada (fsm_t* this);
void ActualizaPlayer (fsm_t* this );
void StopPlayer (fsm_t* this);
void ComienzaNuevaNota (fsm_t* this );
void FinalMelodia (fsm_t* this);
void InicializaPlayer(fsm_t* this);


void ComienzaSistema (fsm_t* this);
void EsperoTarjeta (fsm_t* this);
void LeerTarjeta (fsm_t* this);
void DescartaTarjeta (fsm_t* this);
void ComienzaReproduccion (fsm_t* this);
void ComprueboTarjeta (fsm_t* this);
void CancelaReproduccion (fsm_t* this);
void FinalizaReproduccion (fsm_t* this);

//------------------------------------------------------
// SUBRUTINAS DE ATENCION A LAS INTERRUPCIONES
//------------------------------------------------------
PI_THREAD (thread_explora_teclado);

//------------------------------------------------------
// VARIABLES CON LA INFORMACION SOBRE LAS CANCIONES
//------------------------------------------------------
extern int frecuenciaDespacito[];
extern int tiempoDespacito[];
extern int frecuenciaGOT[];
extern int tiempoGOT[];
extern int frecuenciaTetris[];
extern int tiempoTetris[];
extern int frecuenciaStarwars[];
extern int tiempoStarwars[];

//------------------------------------------------------
// MAQUINA DE ESTADOS
//------------------------------------------------------
enum fsm_state {
	WAIT_START = 00,
	WAIT_PUSH = 01,
	WAIT_END = 11,
};
enum fsm_state_detecta {
	WAIT_START2=0,
	WAIT_CARD=1,
	WAIT_CHECK=2,
	WAIT_PLAY=3,
};

//------------------------------------------------------
// DEFINE VALORES STRUCT
//------------------------------------------------------
#define MAX_NUM_TARJETAS	5
#define MAX_NUM_NOTAS 		600
#define MAX_NUM_CHAR_NOMBRE	100
#define MAX_NUM_CHAR_UID	100

//------------------------------------------------------
// CREACION STRUCTS A USAR
//------------------------------------------------------
typedef struct {
	char nombre[MAX_NUM_CHAR_NOMBRE]; // String con el nombre de la melodia
	int frecuencias[MAX_NUM_NOTAS]; // Array con las frecuencias de las notas de la melodia
	int duraciones[MAX_NUM_NOTAS]; // Array con las duraciones de las notas de la melodia
	int num_notas; // Numero de notas de que consta la melodia
} TipoMelodia;

typedef struct {
	int posicion_nota_actual;	// Valor correspondiente a la posicion de la nota actual en los arrays de frecuencias y duraciones
	int frecuencia_nota_actual; // Valor correspondiente a la frecuencia de la nota actual
	int duracion_nota_actual; // Valor correspondiente a la duracion de la nota actual

	TipoMelodia melodia;

	tmr_t* timer_nota; //Timer que reproduce las notas

	// A completar por el alumno
	// ...
} TipoPlayer;

typedef uint8_t byte;
// A struct used for passing the UID of a PICC.
typedef struct {
	int		size;			// Number of bytes in the UID. 4, 7 or 10.
	int		uidByte[10];
} Uid;

typedef struct {
	Uid uid;  // Identificador correspondiente a la tarjeta (tipo de datos complejo definido en liberia control RFID)
	TipoMelodia melodia;
} TipoTarjeta;

typedef struct {
	TipoPlayer player; // Reproductor de melodias

	int num_tarjetas_activas; // Numero de tarjetas validas

	TipoTarjeta tarjetas_activas[MAX_NUM_TARJETAS]; // Array con todas las tarjetas validas

	Uid uid_tarjeta_actual; // Identificador de la tarjeta actual (tipo de datos complejo definido en liberia control RFID)

	int pos_tarjeta_actual; // Posicion de la tarjeta actual en el array de tarjetas validas

	char uid_tarjeta_actual_string[MAX_NUM_CHAR_UID]; // Identificador de la tarjeta actual a modo de string de caracteres

	//TipoEstadosSistema estado; // Variable que almacena el estado actual del sistema

	char teclaPulsada; // Variable que almacena la ultima tecla pulsada

	int debug; // Variable que habilita o deshabilita la impresion de mensajes por salida estandar
} TipoSistema;


//------------------------------------------------------
// FUNCIONES DE CONFIGURACION INICIAL
//------------------------------------------------------
int InicializaMelodia (TipoMelodia *melodia, char *nombre, int *array_frecuencias, int *array_duraciones, int num_notas);
int systemSetup (void);
void fsm_setup(fsm_t* luz_fsm);

//------------------------------------------------------
// FUNCIONES AUXILIARES
//------------------------------------------------------
int CheckCardValidity (TipoSistema *sistema);
int Transformar (char a);

//void fsm_setup (tarjeta_fsm_tmr);
#endif /* PIMUSICBOX_1_H_ */
