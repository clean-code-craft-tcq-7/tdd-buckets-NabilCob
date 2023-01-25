#include <stdio.h>
#include <stdlib.h>
#include "FormatOutput.h"

char* str[10];
FormatOutputType formatOutputValue;

void formatOutput(int min, int max, int range, int idx){

    str[idx] = (char*)calloc(10, sizeof(char));
    sprintf(str[idx],"%d-%d, %d", min, max, range);
}

