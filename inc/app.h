/*!
 *	File:	app.h
 *	Author:	Martin Mello Teggia
 *  Date:	2020-12-08
 *
 */

#ifndef MISCODIGOS_APP_H_
#define MISCODIGOS_APP_H

#include "UARTDriver.h"
#include "messageParser.h"
#include "vibrationProcessing.h"
#include "leds.h"

typedef enum{
	AwaitingMessage = 0,
	ProcessingRequest = 1,
	AquiringData = 2,
	ProccesingData = 3,
	ReportingResults = 4
}actions_t;

#define ERROR_MAX_LENGTH_EXCEDED "Mensaje excedido en largo\r\n"
#define ERROR_WRONG_MESSAGE "Mensaje no reconocido\r\n"
#define ERROR_VIBRATION_INICIALIZATION_FAILED "No se puede conectar con el sensor\r\n"

#endif /* MISCODIGOS_APP_H */
