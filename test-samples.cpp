#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"

#include "FormatOutput.h"
#include "DetectChargeRange.h"

TEST_CASE("Test charge samples ranges") {
 
   formatOutputValue.formatOutput = formatOutput;
   int nrRange;
   
   int sample1[]= {4, 5}; 
   int n = sizeof(sample1)/sizeof(sample1[0]);  
   nrRange = DetectChargeRangeandCount(sample1, n);
   REQUIRE(nrRange == 1);
   REQUIRE(strncmp(str[0], "4-5, 2", strlen("4-5, 2")) == 0);
   
   int sample2[] = {3, 3, 5, 4, 10, 11, 12};
   n = sizeof(sample2)/sizeof(sample2[0]); 
   nrRange = DetectChargeRangeandCount(sample2, n);
   REQUIRE(nrRange == 2);
   REQUIRE(strncmp(str[0], "3-5, 4", strlen("3-5, 4")) == 0);
   REQUIRE(strncmp(str[1], "10-12, 3", strlen("10-12, 3")) == 0);
}




