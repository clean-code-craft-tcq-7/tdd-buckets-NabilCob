#ifndef A2D_CONVERSION_H_
#define A2D_CONVERSION_H_

typedef struct{
   int maxAmps;
   int bitConversion;
} ADCType;

int checklimits(int , int );
int A2DConvertion(int , int , int );
int ConvertAnalogSamplestoDigital(int [], int , ADCType , int []);
int mapOperatingRange(int , int );

#endif

