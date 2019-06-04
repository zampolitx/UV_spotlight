#include <xc.h>
#include "UV_Spotlight_main.h"
#include <stdio.h>
#include <stdlib.h>




void main(void) {
    TRISA = 0b00000;
    while(1)
    {   
        relay = 1;
        __delay_ms(1000);
        relay = 0;
        __delay_ms(1000);
        
    }
    return;
}
