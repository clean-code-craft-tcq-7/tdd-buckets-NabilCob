#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"

#include "FormatOutput.h"
#include "DetectChargeRange.h"
#include "A2DConversion.h"

TEST_CASE("Test charge samples ranges") {
 
   formatOutputValue.formatOutput = formatOutput;
   int nrRange;
   ADCType config;
   printf("\nsample1-\nRange, Readings");
   int sample1[]= {1547, 1924}; 
   int n = sizeof(sample1)/sizeof(sample1[0]);  
   int outputSample1[10];  
   config.bitConversion = 12;
   config.maxAmps = 10;
   int size = ConvertAnalogSamplestoDigital(sample1, n, config, outputSample1);
   nrRange = DetectChargeRangeandCount(outputSample1, size);
   REQUIRE(nrRange == 1);
   REQUIRE(strncmp(str[0], "4-5, 2", strlen("4-5, 2")) == 0);
}




