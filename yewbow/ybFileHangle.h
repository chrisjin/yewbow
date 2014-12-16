#pragma once
#include"ybBasicTypes.h"
#include<stdio.h>
NS_YB_BEGIN
class FileHandle
{
public:
	bool Open(const char* name);
	bool Create(const char* name);
	bool Append(const char* name);
	void Close();
	bool Write(tByte* bytearr, int num);
	bool Read(tByte* buffer, int num);
private:
	FILE* fp;
};

NS_YB_END