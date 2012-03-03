/*********************************************************************************

 Copyright 2006-2008 MakingThings

 Licensed under the Apache License, 
 Version 2.0 (the "License"); you may not use this file except in compliance 
 with the License. You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0 
 
 Unless required by applicable law or agreed to in writing, software distributed
 under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 CONDITIONS OF ANY KIND, either express or implied. See the License for
 the specific language governing permissions and limitations under the License.

*********************************************************************************/

/* 
  BASIC INTERRUPT DRIVEN DRIVER FOR USB. 

  This file contains all the usb components that must be compiled
  to ARM mode.  The components that can be compiled to either ARM or THUMB
  mode are contained in analogin.C

*/

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

/* Demo application includes. */
#include "Board.h"

#include "analogin_internal.h"

/*-----------------------------------------------------------*/

extern struct AnalogIn_* AnalogIn;

/*-----------------------------------------------------------*/

/* The interrupt entry point is naked so we can control the context saving. */
void AnalogInIsr_Wrapper( void ) __attribute__ ((naked));

/* The interrupt handler function must be separate from the entry function
to ensure the correct stack frame is set up. */
void AnalogInIsr_Handler( void );

/*-----------------------------------------------------------*/


void AnalogInIsr_Handler( void )
{
  portCHAR cTaskWokenByPost = pdFALSE; 

  int status = AT91C_BASE_ADC->ADC_SR;
  if ( status & AT91C_ADC_DRDY )
  	cTaskWokenByPost = xSemaphoreGiveFromISR( AnalogIn->doneSemaphore, cTaskWokenByPost );

  int value = AT91C_BASE_ADC->ADC_LCDR;
  (void)value;

	/* Clear AIC to complete ISR processing */
	AT91C_BASE_AIC->AIC_EOICR = 0;

	/* If a task was woken by either a frame being received then we may need to 
	switch to another task.  If the unblocked task was of higher priority then
	the interrupted task it will then execute immediately that the ISR
	completes. */
	if( cTaskWokenByPost )
	{
		portYIELD_FROM_ISR();
	}
}

void  AnalogInIsr_Wrapper( void )
{
	/* Save the context of the interrupted task. */
	portSAVE_CONTEXT();

	/* Call the handler to do the work.  This must be a separate
	function to ensure the stack frame is set up correctly. */
	AnalogInIsr_Handler();

	/* Restore the context of whichever task will execute next. */
	portRESTORE_CONTEXT();
}

