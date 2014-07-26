/* variabile si definitii pentru program
*
*/

#define LINE_SIZE	32				//line buffer size
#define NOP() __asm__ __volatile__ ("nop")

#define MAX_TEMP_CONSTANT 450

// constante PID stocate in eeprom
//nu treb volatile?
uint8_t EEMEM EEMEM_KP;
uint8_t EEMEM EEMEM_KI;
uint8_t EEMEM EEMEM_KD;
uint8_t EEMEM EEMEM_KT;


//comportament
volatile uint8_t log_enable;

//din nou oare volatile?cel putin la ultima?

int16_t tmp;

