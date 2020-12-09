/*!
 * app.c
 * Martin Mello Teggia <martinmt139@gmail.com>
 * Date: 2020/12/08
 *===========================================================================*/

#include "sapi.h"
#include "app.h"

int main( void ){

	// ---------- CONFIGURACIONES ------------------------------
	// Inicializar y configurar la plataforma
	boardInit();

	uartConfig( UART_USB, 115200 );

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
						break;
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
						status = configureVibration();
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
				readVibration();
				currentAction = ProccesingData;
				break;
			case ProccesingData:
				currentAction = ReportingResults;
				break;
			case ReportingResults:
				printAcceleration();
				currentAction = AwaitingMessage;
				break;
		}
	}

	return 0;
}

