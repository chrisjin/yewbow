#include"ybDebug.h"
#include<stdarg.h>
#include <stdio.h> 
#define LENGTH (255) 
NS_YB_BEGIN

void DebugMessage(const char* fmt, ...)
{
	char format[LENGTH];
	va_list argp;
	va_start(argp, fmt);
	yb_vsprintf(format, LENGTH, fmt, argp);
	va_end(argp);
	printf("%s", format);
}

NS_YB_END