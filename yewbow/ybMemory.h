#pragma once
#include"ybBasicMacro.h"

NS_YB_BEGIN

void* YB_INTERFACE Malloc(int size); 
void YB_INTERFACE Free(void* a);
NS_YB_END