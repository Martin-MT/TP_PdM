/*!
 *	File:	messageParser.c
 *	Author: Martin Mello Teggia
 *  Date:	2020-12-09
 *
 */

#include "../inc/messageParser.h"

request_t parceInput(message_t *message){
	if (0 == message){
		return ErrorWrongPointer;
	}
	if (('*' != message->inputMessageString[0]) || ('#' != message->inputMessageString[message->lastPossition])){
		emptyMessage(message);
		return ErrorWrongMessage;
	}
	if ('1' == message->inputMessageString[1]){
		emptyMessage(message);
		return AcquireVibration;
	} else {
		emptyMessage(message);
		return ErrorWrongMessage;
	}
}





