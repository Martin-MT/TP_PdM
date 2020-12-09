/*!
 *	File:	messageParser.h
 *	Author:	Martin Mello Teggia
 *  Date:	2020-12-09
 *
 */

#ifndef MISCODIGOS_MESSAGEPARSER_H
#define MISCODIGOS_MESSAGEPARSER_H

#include "sapi.h"
#include "../inc/UARTDriver.h"

typedef enum{
	ErrorWrongMessage = 0,
	AcquireVibration = 1,
	AcquireTemperature = 2,
	ErrorWrongPointer = 3
}request_t;

request_t parceInput(message_t *);


#endif /* MISCODIGOS_MESSAGEPARSER_H */
