#include <math.h>
#include "A2DConversion.h"


int ConvertAnalogSamplestoDigital(int inputsample[], int sampleSize,
                ADCType config, int outputsample[])
{
   int sampleCnt = 0;
   int outputCnt = 0;
   int range = 0;
   int value = 0;
   for (sampleCnt = 0; sampleCnt < sampleSize; sampleCnt ++){

       if(checklimits(inputsample[sampleCnt], config.bitConversion)){
           //Calculate range
           range = config.maxAmps - config.minAmps;
           value = mapOperatingRange(A2DConvertion(inputsample[sampleCnt],range,
                           config.bitConversion), config.minAmps);
           outputsample[outputCnt] = abs(value);
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
     return (int)round((maxAmps * (float)value)/(1 << bitconverter));
}

int mapOperatingRange(int value, int minamps){
      return value + minamps;
}
