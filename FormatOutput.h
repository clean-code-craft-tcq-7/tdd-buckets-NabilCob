#ifndef FORMAT_OUTPUT_H
#define FORMAT_OUTPUT_H

typedef struct
{
   void (*formatOutput)(int, int, int, int);

} FormatOutputType;

extern char* str[10];
extern FormatOutputType formatOutputValue;

void formatOutput(int min, int max, int range, int);

#endif
