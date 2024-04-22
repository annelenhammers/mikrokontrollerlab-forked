#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"

int main(){

    button_init();
    ppi_init();

    while(1){
        continue;
    }
    return 0;

}