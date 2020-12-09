/*!
 * app.c
 * Martin Mello Teggia <martinmt139@gmail.com>
 * Date: 2020/12/08
 *===========================================================================*/

#include "sapi.h"
#include "UARTDriver.h"
#include "leds.h"
#include "app.h"

int main( void ){

	// ---------- CONFIGURACIONES ------------------------------
	// Inicializar y configurar la plataforma
	boardInit();

	uartConfig( UART_USB, 115200 );

	uint8_t data;
	message_t message;
	actions_t currentAction;
	newMessage_t newMessage;
	request_t request;
	int8_t status;

	emptyMessage(&message);
	while( TRUE ){
		switch(currentAction){
			case AwaitingMessage:
				newMessage = checkForMessages(&message);
				switch(newMessage){
					case NewMessageReceived:
						currentAction = ProcessingRequest;
						break;
					case MessageLengthExceded:
						uartWriteString(UART_USB, ERROR_MAX_LENGTH_EXCEDED);
				}
				break;
			case ProcessingRequest:
				request = parceInput(&message);
				switch (request){
					case ErrorWrongMessage:
						uartWriteString(UART_USB, ERROR_WRONG_MESSAGE);
						currentAction = AwaitingMessage;
						break;
					case ErrorWrongPointer:
						currentAction = AwaitingMessage;
						break;
					case AcquireVibration:
						status = initializeVibration();
						if (0 != status){
							uartWriteString(UART_USB, ERROR_VIBRATION_INICIALIZATION_FAILED);
							currentAction = AwaitingMessage;
						} else{
							currentAction = AquiringData;
						}
						break;
				}
				break;
			case AquiringData:
				mpu60X0Read();
				printf( "Acelerometro:   (%f, %f, %f)   [m/s2]\r\n", mpu60X0GetAccelX_mss(), mpu60X0GetAccelY_mss(), mpu60X0GetAccelZ_mss());
				currentAction = ProccesingData;
				break;
			case ProccesingData:
				currentAction = ReportingResults;
				break;
			case ReportingResults:
				currentAction = AwaitingMessage;
				break;
		}
	}

	return 0;
}

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

uint8_t initializeVibration(void){
	uint8_t status;
	status = mpu60X0Init(0x68);
	if( status < 0 ){
		return 1;
	}
	return 0;
}

void emptyMessage(message_t * message){
	message->lastPossition = 0;
}




