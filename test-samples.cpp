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
 
   printf("\nsample2-\nRange, Readings");
   int sample2[] = {1050, 190, 197, 798, 764, 669, 314, 266};
   n = sizeof(sample2)/sizeof(sample2[0]);
   int outputSample2[10];
   config.bitConversion = 10;
   config.maxAmps = 15;
   size = ConvertAnalogSamplestoDigital(sample2, n, config, outputSample2); 
   nrRange = DetectChargeRangeandCount(outputSample2, size);
   REQUIRE(nrRange == 2);
   REQUIRE(strncmp(str[0], "3-5, 4", strlen("3-5, 4")) == 0);
   REQUIRE(strncmp(str[1], "10-12, 3", strlen("10-12, 3")) == 0);
 
   printf("\nsample3-\nRange, Readings");
   int sample3[]= {1924, 1547}; 
   n = sizeof(sample3)/sizeof(sample3[0]);  
   int outputSample3[10];
   config.bitConversion = 12;
   config.maxAmps = 10;
   size = ConvertAnalogSamplestoDigital(sample3, n, config, outputSample3);
   nrRange = DetectChargeRangeandCount(outputSample3, size);
   REQUIRE(nrRange == 1);
   REQUIRE(strncmp(str[0], "4-5, 2", strlen("4-5, 2")) == 0);
 
   printf("\nsample4-\nRange, Readings");
   int sample4[]= {1146, 1924, 2702};
   n = sizeof(sample4)/sizeof(sample4[0]);
   int outputSample4[10];
   config.bitConversion = 12;
   config.maxAmps = 10;
   size = ConvertAnalogSamplestoDigital(sample4, n, config, outputSample4);
   nrRange = DetectChargeRangeandCount(outputSample4, size);
   REQUIRE(nrRange == 3);
   REQUIRE(strncmp(str[0], "3-3, 1", strlen("3-3, 1")) == 0);
   REQUIRE(strncmp(str[1], "5-5, 1", strlen("5-5, 1")) == 0);
   REQUIRE(strncmp(str[2], "7-7, 1", strlen("7-7, 1")) == 0);
 
   printf("\nsample5-\nEmpty sample");
   size = ConvertAnalogSamplestoDigital(NULL, 0, 0, NULL);
   REQUIRE(size == 0);
   nrRange = DetectChargeRangeandCount(NULL, 0);
   REQUIRE(nrRange == 0);
}




