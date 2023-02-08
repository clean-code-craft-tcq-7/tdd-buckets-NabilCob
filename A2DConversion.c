#include <math.h>
#include "A2DConversion.h"


int ConvertAnalogSamplestoDigital(int inputsample[], int sampleSize,
                ADCType config, int outputsample[])
{
   int sampleCnt = 0;
   int outputCnt = 0;
   for (sampleCnt = 0; sampleCnt < sampleSize; sampleCnt ++){

       if(checklimits(inputsample[sampleCnt], config.bitConversion)){
           outputsample[outputCnt]= A2DConvertion(inputsample[sampleCnt],config.maxAmps,
                           config.bitConversion);
           outputCnt ++;
       }
   }
   return outputCnt;
}

int checklimits(int value, int bitconverter){
 if (value > (1 << bitconverter)){
    return 0;
 }
 return 1;
}

int A2DConvertion(int value, int maxAmps, int bitconverter){
     return (int)ceil((maxAmps * (float)value)/(1 << bitconverter));
}
