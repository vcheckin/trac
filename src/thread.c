/*
 * thread.c
 *
 */
#include <inttypes.h>
#include <avr/interrupt.h>

#include "thread.h"

struct thread {
	/** saved stack pointer */
	uint8_t *sp;
};

volatile uint8_t current_thread = 1;
struct thread threads[2] = {{0}};

uint8_t *schedule(uint8_t *sp)
{
        threads[current_thread].sp = sp;
        current_thread = 1 - current_thread;
        return threads[current_thread].sp;
}

void yield()
{
	cli();
	save_context();
	asm volatile (
		"in   r24, 0x3d\n\t" // SPL
		"in   r25, 0x3e\n\t" // SPH
		"call schedule\n\t"
		"out 0x3d ,r24\n\t" //
		"out 0x3e ,r25\n\t"
	);
	restore_context();
	reti();
}

void init_thread(uint_fast8_t idx, void (*entry)(), uint8_t *stack, int stack_sz)
{
	uint8_t *sp = stack + stack_sz - 1;
	*sp-- = ((uint16_t)entry) & 0x0ff;
	*sp-- = (((uint16_t)entry) >> 8) & 0xff;
#ifdef __AVR_ATmega2560__
	*sp-- = 0;
#endif
	sp -= 32;
	*sp-- = SREG;
	threads[idx].sp = sp;
}
