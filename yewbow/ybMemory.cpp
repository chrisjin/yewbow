#include"ybMemory.h"
#include<stdlib.h>

NS_YB_BEGIN
void* YB_INTERFACE Malloc(int size)
{
	return malloc(size);
}

void YB_INTERFACE Free(void* a)
{
	if (a)
		free(a);
}
NS_YB_END