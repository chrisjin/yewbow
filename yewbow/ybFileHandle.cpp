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
bool FileHandle::Write(tByte* bytearr, int num)
{
	fwrite(bytearr,1,num,fp);
}
bool FileHandle::Read(tByte* buffer, int num)
{
	fread(buffer, 1, num, fp);
}

NS_YB_END