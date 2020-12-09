/*!
 *	File:	UARTDriver.h
 *	Author:	Martin Mello Teggia
 *  Date:	2020-12-09
 *
 */

#ifndef MISCODIGOS_UARTDRIVER_H
#define MISCODIGOS_UARTDRIVER_H

typedef enum{
	NewMessageReceived = 0,
	NewCharAdded = 1,
	MessageLengthExceded = 2,
	NoNewMessage = 3
}newMessage_t;

#define MAX_MESSAGE_LENGTH 5
typedef struct{
	char inputMessageString[MAX_MESSAGE_LENGTH];
	uint8_t lastPossition;
}message_t;


newMessage_t checkForMessages(message_t *);
newMessage_t addChar(message_t *message, char data);

#endif /* MISCODIGOS_UARTDRIVER_H */
