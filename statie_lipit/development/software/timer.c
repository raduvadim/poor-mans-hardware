#include <avr/io.h>
#include "hardware.h"
#include "timer.h"


void TIMER0_init(void){
	// read setpoint
	//Timer0 upcounting clk/256 interrupt enabled
	TCCR0 |= (1<<CS02);		// clk/256
	TIMSK |= (1<<TOIE0);	// enable overflow interrupt
}
void TIMER1_init(void){
	// Timer1 Phase correct PWM 9bit clk/64 ~15Hz with 1MHz clock
	// In this mode if OCR1A=0 we have truly 0 power applied
	TCCR1B |= (1<<CS11)|(1<<CS10);
	TCCR1A |= (1<<COM1A1)|(1<<WGM11);
	OCR1A = 0;
	DDRB |= (1<<PB1);
}
void TIMER2_init(void){
	// read temperature
	//Timer2 upcounting clk/1024 interrupt enabled
	TCCR2 |= (1<<CS22)|(1<<CS21)|(1<CS20);	// clk/1024
	TIMSK |= (1<<TOIE2);					// enable interrupt
}
