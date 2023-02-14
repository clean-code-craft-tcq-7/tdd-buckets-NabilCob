#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"

#include "A2DConversion.h"

TEST_CASE("Test adc conversion"){

  //Test 1
  int sample1[]= {1547, 1924};
  int outputSample1[10];  
  int TestSample1[] = {4, 5};
  ADCType config;
  int n = sizeof(sample1)/sizeof(sample1[0]);  
  config.bitConversion = 12;
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
  config.maxAmps = 10;
  size = ConvertAnalogSamplestoDigital(sample3, n, config, outputSample3);
  REQUIRE(size == 3);
  REQUIRE(memcmp(outputSample3, TestSample3, sizeof(int)*size) == 0);
  
  //Test 4
  size = ConvertAnalogSamplestoDigital(NULL, 0, config, NULL);
  REQUIRE(size == 0);
}
