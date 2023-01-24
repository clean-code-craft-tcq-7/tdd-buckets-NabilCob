#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentRange.h"

TEST_CASE("Test charging current samples") {
  int currentSample1[] = {4, 5};
  const int sampleCount1 = 1;
  char *sampleList1[sampleCount1];
  int samples = CheckBatteryRange(currentSample1, &sampleList1[0]);
  
  REQUIRE(samples == sampleCount1);
  REQUIRE(strncmp(sampleList1[0], "4-5, 2", strlen("4-5, 2")));
  

  int currentSample2[] = {5, 4};
  const int sampleCount2 = 1;
  char *sampleList2[sampleCount2];
  int samples = CheckBatteryRange(currentSample2, &sampleList2[0]);

  REQUIRE(samples == sampleCount2);
  REQUIRE(strncmp(sampleList2[0], "4-5, 2", strlen("4-5, 2")));   
}




