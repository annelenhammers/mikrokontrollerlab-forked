#include "ppi.h"
#include "gpiote.h"

void ppi_init(){
    for(int i = 0; i < 4; i++) {
        PPI -> PPI_CH[i].EEP = (uint32_t)&(GPIOTE -> IN[0]);
        PPI -> PPI_CH[i].TEP = (uint32_t)&(GPIOTE -> OUT[i + 1]);
    }
    PPI -> CHENSET = 0b1111;

}