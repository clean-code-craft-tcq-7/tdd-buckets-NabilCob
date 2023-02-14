
#include <stdlib.h>
#include "DetectCurrentRangeFromSensor.h"

int DetectCurrentRangeFromADC(int inputsample[], int sampleSize, ADCType config){
    int size = 0;
    int nrRange = 0;
    int *outputSample = (int*)calloc(sampleSize, sizeof(int));
    size = ConvertAnalogSamplestoDigital(inputsample, sampleSize, config, outputSample);
    nrRange = DetectChargeRangeandCount(outputSample, size);
    return nrRange;
}
