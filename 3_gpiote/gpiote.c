#include "gpiote.h"
#include "gpio.h"

void button_init() {

    GPIO->PIN_CNF[13] = (3 << 2);
    GPIOTE ->CONFIG[0] = 1 + (13 << 8) + (1 << 16);
    GPIOTE ->CONFIG[1] = 3 + (17 << 8) + (3 << 16);
    GPIOTE ->CONFIG[2] = 3 + (18 << 8) + (3 << 16);
    GPIOTE ->CONFIG[3] = 3 + (19 << 8) + (3 << 16);
    GPIOTE ->CONFIG[4] = 3 + (20 << 8) + (3 << 16);
}