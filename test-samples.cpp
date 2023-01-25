#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"

#include "FormatOutput.h"
#include "DetectChargeRange.h"

TEST_CASE("Test charge samples ranges") {
   int arr[]= {4, 5}; 
   int n = sizeof(arr)/sizeof(arr[0]);
   formatOutputValue.formatOutput = formatOutput;
   int nrRange;
   nrRange = DetectChargeRangeandCount(arr, n);
   REQUIRE(nrRange == 1);
   REQUIRE(strncmp(str[0], "4-5, 2", strlen("4-5, 2")) == 0);
}




