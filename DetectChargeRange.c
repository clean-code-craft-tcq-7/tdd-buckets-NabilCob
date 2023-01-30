#include <stdio.h>
#include <stdlib.h>

#include "DetectChargeRange.h"
#include "FormatOutput.h"

int comparsioninAscending (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int DetectChargeRangeandCount(int samples[], int len){

    int counter = 0;
    int min = 0, max = 0;

    qsort(samples, len, sizeof(int), comparsioninAscending);
  
    while((counter < len) && (max < len)){
        max = isConsecutive(samples, min, len);
        findRange(min, max - 1, samples, counter);
        min = max;
        counter ++;
    }
    return counter;
}

int isConsecutive(int arr[], int min,  int n)
{
    int i;
    for(i= min + 1; i<n; i++)
    {
        if((arr[i] - (arr[i-1]+1)) > 0)
        {
            return i;
        }
    }
    return i;
}

int findRange(int minidx, int maxidx, int samples[], int strindex){
    int min = samples[minidx];
    int max = samples[maxidx];
    int range = maxidx - minidx + 1;
    (*formatOutputValue.formatOutput)(min, max, range, strindex);
    return 0;
}
