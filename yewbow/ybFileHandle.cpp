#include"ybFileHangle.h"
NS_YB_BEGIN
bool FileHandle::Open(const char* name)
{
	if (0 == yb_fopen(&fp, name, "rb"))
		return true;
	else
		return false;
}
bool FileHandle::Create(const char* name)
{
	if (0 == yb_fopen(&fp, name, "wb"))
		return true;
	else
		return false;
}
bool FileHandle::Append(const char* name)
{
	if (0 == yb_fopen(&fp, name, "ab"))
		return true;
	else
		return false;
}
void FileHandle::Close()
{
	fclose(fp);
}
bool FileHandle::Write(void* bytearr, int num)
{
	if(num==fwrite(bytearr,1,num,fp))
		return true;
	return false;
}
bool FileHandle::Read(void* buffer, int num)
{
	if (num == fread(buffer, 1, num, fp))
		return true;
	return false;
}

NS_YB_END