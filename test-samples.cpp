#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "DetectCurrentRangeFromSensor.h"

TEST_CASE("Test charge range from sensor readings"){
  //Test 1 - Valid sample
  int sample1[]= {1547, 1924}; 
  int n = sizeof(sample1)/sizeof(sample1[0]);  
  ADCType config;
  int nrRange;
  config.bitConversion = 12;
  config.minAmps = 0;
  config.maxAmps = 10; 
  formatOutputValue.formatOutput = formatOutput;
  nrRange = DetectCurrentRangeFromADC(sample1, n, config);
  REQUIRE(nrRange == 1);
  REQUIRE(strncmp(str[0], "4-5, 2", strlen("4-5, 2")) == 0);
  
  //Test 2 - one invalid input
  int sample2[] = {1050, 190, 197, 798, 764, 669, 314, 266};
  n = sizeof(sample2)/sizeof(sample2[0]);
  config.bitConversion = 10;
  config.minAmps = 0;
  config.maxAmps = 15;
  nrRange = DetectCurrentRangeFromADC(sample2, n, config);
  REQUIRE(nrRange == 2);
  REQUIRE(strncmp(str[0], "3-5, 4", strlen("3-5, 4")) == 0);
  REQUIRE(strncmp(str[1], "10-12, 3", strlen("10-12, 3")) == 0);
  
  //Test 3 - Boundary test
  int sample3[] = {10, 190, 197, 798, 764, 669, 314, 1023};
  n = sizeof(sample3)/sizeof(sample3[0]);
  config.bitConversion = 10;
  config.minAmps = -15;
  config.maxAmps = 15;
  nrRange = DetectCurrentRangeFromADC(sample3, n, config);
  REQUIRE(nrRange == 2);
  REQUIRE(strncmp(str[0], "5-9, 6", strlen("5-9, 6")) == 0);
  REQUIRE(strncmp(str[1], "15-15, 2", strlen("15-15, 2")) == 0);
  
  //Test 3 - empty list
  nrRange = DetectCurrentRangeFromADC(NULL, 0, config); 
  REQUIRE(nrRange == 0);
}


TEST_CASE("Test adc conversion")
{
  //Test 1
  int sample1[]= {1547, 1924};
  int outputSample1[10];  
  int TestSample1[] = {4, 5};
  ADCType config;
  int n = sizeof(sample1)/sizeof(sample1[0]);  
  config.bitConversion = 12;
  config.minAmps = 0;
  config.maxAmps = 10;
  int size = ConvertAnalogSamplestoDigital(sample1, n, config, outputSample1);
  REQUIRE(size == 2);
  REQUIRE(memcmp(outputSample1, TestSample1, sizeof(int)*size) == 0);
  
  //Test 2
  int sample2[] = {1050, 190, 197, 798, 764, 669, 314, 266};
  int outputSample2[10];
  int TestSample2[] = {3, 3, 12, 11, 10, 5, 4};
  n = sizeof(sample2)/sizeof(sample2[0]);
  config.bitConversion = 10;
  config.minAmps = 0;
  config.maxAmps = 15;
  size = ConvertAnalogSamplestoDigital(sample2, n, config, outputSample2);
  REQUIRE(size == 7);
  REQUIRE(memcmp(outputSample2, TestSample2, sizeof(int)*size) == 0);
  
  //Test 3
  int sample3[]= {1146, 1924, 2702}; 
  int outputSample3[10];
  int TestSample3[] = {3, 5, 7};
  n = sizeof(sample3)/sizeof(sample3[0]);
  config.bitConversion = 12;
  config.minAmps = 0;
  config.maxAmps = 10;
  size = ConvertAnalogSamplestoDigital(sample3, n, config, outputSample3);
  REQUIRE(size == 3);
  REQUIRE(memcmp(outputSample3, TestSample3, sizeof(int)*size) == 0);
  
  //Test 4 - Boundary values
  int sample4[] = {10, 190, 197, 798, 764, 669, 314, 1023};
  n = sizeof(sample4)/sizeof(sample4[0]);
  int outputSample4[10];
  int TestSample4[] = {15, 9, 9, 8, 7, 5, 6, 15};
  config.bitConversion = 10;
  config.minAmps = -15;
  config.maxAmps = 15;
  size = ConvertAnalogSamplestoDigital(sample4, n, config, outputSample4);
  REQUIRE(size == 8);
  REQUIRE(memcmp(outputSample4, TestSample4, sizeof(int)*size) == 0);
  
  //Test 5
  size = ConvertAnalogSamplestoDigital(NULL, 0, config, NULL);
  REQUIRE(size == 0);
}

TEST_CASE("Test charge samples ranges") 
{ 
   
   printf("\nsample1-\nRange, Readings");
   int sample1[]= {4, 5}; 
   formatOutputValue.formatOutput = formatOutput;
   int nrRange;
   int n = sizeof(sample1)/sizeof(sample1[0]);  
   nrRange = DetectChargeRangeandCount(sample1, n);
   REQUIRE(nrRange == 1);
   REQUIRE(strncmp(str[0], "4-5, 2", strlen("4-5, 2")) == 0);

   printf("\nsample2-\nRange, Readings");
   int sample2[] = {3, 3, 5, 4, 10, 11, 12};
   n = sizeof(sample2)/sizeof(sample2[0]); 
   nrRange = DetectChargeRangeandCount(sample2, n);
   REQUIRE(nrRange == 2);
   REQUIRE(strncmp(str[0], "3-5, 4", strlen("3-5, 4")) == 0);
   REQUIRE(strncmp(str[1], "10-12, 3", strlen("10-12, 3")) == 0);

   printf("\nsample3-\nRange, Readings");
   int sample3[]= {5,4}; 
   n = sizeof(sample3)/sizeof(sample3[0]);  
   nrRange = DetectChargeRangeandCount(sample3, n);
   REQUIRE(nrRange == 1);
   REQUIRE(strncmp(str[0], "4-5, 2", strlen("4-5, 2")) == 0);

   printf("\nsample4-\nRange, Readings");
   int sample4[]= {3, 5, 7};
   n = sizeof(sample4)/sizeof(sample4[0]);
   nrRange = DetectChargeRangeandCount(sample4, n);
   REQUIRE(nrRange == 3);
   REQUIRE(strncmp(str[0], "3-3, 1", strlen("3-3, 1")) == 0);
   REQUIRE(strncmp(str[1], "5-5, 1", strlen("5-5, 1")) == 0);
   REQUIRE(strncmp(str[2], "7-7, 1", strlen("7-7, 1")) == 0);

   printf("\nsample5-\nEmpty sample");
   nrRange = DetectChargeRangeandCount(NULL, 0);
   REQUIRE(nrRange == 0);
}




