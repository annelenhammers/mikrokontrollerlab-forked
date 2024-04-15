#include <stdint.h>
#include "uart.h"
#include <stdio.h>
#include <sys/types.h> 
#include "gpio.h"



void button_init(){ 
	GPIO->PIN_CNF[13] = (3 << 2); //0b1100
	GPIO->PIN_CNF[14] = (3 << 2); 
	// Fill inn the configuration for the remaining buttons 
}

int main(){

    /*ssize_t _write(int fd, const void *buf, size_t count){
        char * letter = (char *)(buf);
        for(int i = 0; i < count; i++){
            uart_send(*letter);
            letter++;
        }
        return count;
    }
    iprintf("The average grade in TTK%d was in %d was: %c\n\r",4235,2022,'B'); */

	// Configure LED Matrix
	for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	button_init();
    uart_init();
	// Configure buttons -> see button_init()

	int sleep = 0;
    int leds_on = 0;
	while(1){

		if(!(GPIO->IN & (1 << 13))){
            uart_send('A');

		}

		if(!(GPIO->IN & (1 << 14))){
            uart_send('B');

		}
        if (uart_read() != '\0') {
            if(!leds_on){
                leds_on = 1;
                GPIO -> OUTSET =(1<<17);
                GPIO -> OUTSET =(1<<18);
                GPIO -> OUTSET =(1<<19);
                GPIO -> OUTSET =(1<<20);

            }
            else {
                leds_on = 0;
                GPIO -> OUTCLR =(1<<17);
                GPIO -> OUTCLR =(1<<18);
                GPIO -> OUTCLR =(1<<19);
                GPIO -> OUTCLR =(1<<20);

            }
        }
        

		sleep = 10000;
		while(--sleep); // Delay
	}




	return 0;
}
