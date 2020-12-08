/*!
 *	File:	leds.c
 *	Author: Martin Mello Teggia
 *  Date:	2020-11-04
 *
 */

#include "sapi.h"
#include "../inc/leds.h"


void encenderVerde(){
	_encenderLed(LUZ_VERDE);
}

void encenderRojo(){
	_encenderLed(LUZ_ROJA);
}

void encenderAmarillo(){
	_encenderLed(LUZ_AMARILLA);
}

void encenderVerdeRGB(){
	_encenderLed(LUZ_VERDE_RGB);
}

void encenderRojoRGB(){
	_encenderLed(LUZ_ROJA_RGB);
}

void encenderAmarilloRGB(){
	_encenderLed(LUZ_AMARILLA_RGB);
}

inline void _encenderLed(gpioMap_t led){
	gpioWrite(led, ON);
}

// Apagar todos los leds
void apagarLeds(){
	gpioWrite(LUZ_VERDE, OFF);
	gpioWrite(LUZ_AMARILLA, OFF);
	gpioWrite(LUZ_ROJA, OFF);
}

void apagarLedsRGB(){
	gpioWrite(LUZ_VERDE_RGB, OFF);
	gpioWrite(LUZ_AMARILLA_RGB, OFF);
	gpioWrite(LUZ_ROJA_RGB, OFF);
}
