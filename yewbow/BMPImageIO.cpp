#include "ybBMPImageIO.h"

NS_YB_BEGIN
bool BMPImageIO::Write(Image* img, FileHandle* handle)
{
	return 0;
}
Image* BMPImageIO::Read(FileHandle* handle)
{
	return 0;
}
int BMPImageIO::Format()
{
	return FORMAT_BMP;
}

NS_YB_END