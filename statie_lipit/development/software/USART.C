/* fisier: usart.c
 * 18/07/2014 vadim@home
 * Bazat pe codul original de la: https://www.openhub.net/p/avr-pid-solder-station?ref=sample
 * initializare uart
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "hardware.h"
#include "usart.h"

ISR(USART_RXC_vect)
{
	//got byte
	char c;
	c = UDR;

	// minimal processing to make stdio functions happy
	if (c == '\r')
		c = '\n';

	RxBuf[rx_end++ & RXMASK] = c;

}

ISR(USART_UDRE_vect)
{
	//send byte
	if(tx_end != tx_start)
	{
		UDR = TxBuf[tx_start++ & TXMASK];
	}
	else
	{
		//ring buffer empty
		UCSRB &= ~(1<<UDRIE);
	}
}

int USART_putchar(char c, FILE *fp)
{
	//send char or wait if buffer is full
	while((tx_end-tx_start)>TXBUFSIZE-1);

		TxBuf[tx_end++ & TXMASK] = c;

	UCSRB |= (1<<UDRIE);			// Enable UDR empty interrupt

	return (uint8_t)c;
}

int USART_getchar(FILE *fp)
{

	while((rx_end - rx_start) == 0);

	return RxBuf[rx_start++ & RXMASK];
}

void USART_init(void)
{
	// set baudrate
	UBRRH = UBRRH_VALUE;
	UBRRL = UBRRL_VALUE;

#ifdef USART_2X
	UCSRA |= (1<<U2X);
#endif

	// enable receiver and transmitter
	// enable receiver interrupt
	// set frame format to 8bit and 1 stop bit
	UCSRB = (1<<RXCIE)|(1<<TXEN)|(1<<RXEN);
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}



