/*!
 *	File:	UARTDriver.c
 *	Author: Martin Mello Teggia
 *  Date:	2020-12-09
 *
 */

#include "../inc/vibrationProcessing.h"

void printAcceleration(){
	printf( "Acelerometro:   (%f, %f, %f)   [m/s2]\r\n", mpu60X0GetAccelX_mss(), mpu60X0GetAccelY_mss(), mpu60X0GetAccelZ_mss());
}

uint8_t configureVibration(void){
	uint8_t status;
	status = mpu60X0Init(0x68);
	if( status < 0 ){
		return 1;
	} else {
		return 0;
	}

}

void readVibration(void){
	mpu60X0Read();
}

