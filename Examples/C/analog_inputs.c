/* Read analog voltage on slow analog input */

#include <stdio.h>
#include <stdlib.h>

#include "rp.h"

int main (int argc, char **argv) {
    float value;

    // Initialization of API
    if (rp_Init() != RP_OK) {
        fprintf(stderr, "Red Pitaya API init failed!\n");
        return EXIT_FAILURE;
    }

    // Measure each XADC input voltage
    for (int i=0; i<4; i++) {
        rp_ApinGetValue(i+RP_AIN0, &value);
        printf("Measured voltage on AI[%i] = %1.2fV\n", i, value);
    }

    // Releasing resources
    rp_Release();
    
    return EXIT_SUCCESS;
}
