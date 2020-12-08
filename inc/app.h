/*!
 *	File:	app.h
 *	Author:	Martin Mello Teggia
 *  Date:	2020-12-08
 *
 */

#ifndef MISCODIGOS_APP_H_
#define MISCODIGOS_APP_H

typedef enum{
	AwaitingMessage = 0,
	ProcessingRequest = 1,
	AquiringData = 2,
	ProccesingData = 3,
	ReportingResults = 4
}actions_t;

#define MAX_MESSAGE_LENGTH 5
typedef struct{
	char inputMessageString[MAX_MESSAGE_LENGTH];
	uint8_t lastPossition;
}message_t;

typedef enum{
	NewMessageReceived = 0,
	NewCharAdded = 1,
	MessageLengthExceded = 2
}newMessage_t;

typedef enum{
	ErrorWrongMessage = 0,
	AcquireVibration = 1,
	AcquireTemperature = 2,
	ErrorWrongPointer = 3
}request_t;

#define ERROR_MAX_LENGTH_EXCEDED "Excedido\r\n"
#define ERROR_WRONG_MESSAGE "Mensaje no reconocido\r\n"
#define ERROR_VIBRATION_INICIALIZATION_FAILED "No se puede conectar con el sensor\r\n"

newMessage_t addChar(message_t *message, char data);
request_t parceInput(message_t *);
uint8_t initializeVibration(void);
void emptyMessage(message_t *);

#endif /* MISCODIGOS_APP_H */
