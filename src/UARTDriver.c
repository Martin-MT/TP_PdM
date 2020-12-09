/*!
 *	File:	UARTDriver.c
 *	Author: Martin Mello Teggia
 *  Date:	2020-12-09
 *
 */

#include "sapi.h"
#include "../inc/UARTDriver.h"


newMessage_t checkForMessages(message_t *message){
	uint8_t data;
	newMessage_t newMessage;
	if(uartReadByte(UART_USB, &data)){
		 newMessage = addChar(message,(char)data);
		 switch(newMessage){
			 case NewMessageReceived:
				return NewMessageReceived;
				break;
			 case MessageLengthExceded:
				return MessageLengthExceded;
				break;
		 }
	} else {
		return NoNewMessage;
	}
}

newMessage_t addChar(message_t *message, char data){
	if (message->lastPossition >= MAX_MESSAGE_LENGTH){
		message->lastPossition = 0;
		return MessageLengthExceded;
	}
	switch(data){
		case '*':
			message->lastPossition = 0;
			message->inputMessageString[message->lastPossition++] = data;
			return NewCharAdded;
			break;
		case '#':
			message->inputMessageString[message->lastPossition] = data;
			return NewMessageReceived;
			break;
		default:
			message->inputMessageString[message->lastPossition++] = data;
			return NewCharAdded;
			break;
	}
	return NewCharAdded;
}
