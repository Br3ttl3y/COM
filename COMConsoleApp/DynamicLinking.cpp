#include "DynamicLinking.h"
#include <stdio.h>

extern "C" __declspec(dllexport) 
void _stdcall Cluck()
{
	printf("C-style cluck");
};
