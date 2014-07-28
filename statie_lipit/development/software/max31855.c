/* fisier: MAX31855.c
 * 15/07/2014 vadim@anti
 * functii de interfatare
 */
#include <avr/io.h>
#include <stdint.h>

#include "hardware.h"
#include "max31855.h"
#include "spi.h"

/* MAX31855
 *vezi datasheet pentru informatii complete
 *intre timp. este nevoie de 4 citiri pentru un dump complet de informatii
 *inf sunt aranjate astfel:
 *|  nr bit  |31	   |  30 -> 18 |17   |16   |15	    | 14 -> 4	|3	  |2	|1	  |0	|
 *|----------+---------+-----------+-----+-----+--------+-----------+-----+-----+-----+-----+
 *|informatie|semn     |  temp tk  |don't|fault|semn    |temp       |don't|sc v+|sc v-| tk  |
 *|          |temp tk  |           |care |     |temp amb|ambientala |care |     |     |n/a  |
 *|31-----prima citire----24|23-a-doua-citire16|15-citire-nr-iii-8|7-----a patra citire-----|
 *
 *in functia se trateaza doar citirea termocuplei.
 *de adaugat: citire temperatura ambientala, tratare erori.
 *
*/

uint16_t read_temperature(){
	SPI_PORT &= ~(1<<SPI_CS);
	uint32_t v = ((spi_byte_receive()<<24) | (spi_byte_receive()<<16) | (spi_byte_receive()<<8) | (spi_byte_receive()));
	SPI_PORT |= (1<<SPI_CS);
	  // ignore bottom 4 bits - they're just thermocouple data
	  v >>= 4;

	  // pull the bottom 11 bits off
	  float internal = v & 0x7FF;
	  internal *= 0.0625; // LSB = 0.0625 degrees
	  // check sign bit!
	  if (v & 0x800)
	  internal *= -1;
	  //Serial.print("\tInternal Temp: "); Serial.println(internal);
	  return internal;
}