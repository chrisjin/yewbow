#pragma once
#include"ybBasicMacro.h"
NS_YB_BEGIN
#define FORMAT_BMP (1);

class Image;
class FileHandle;
class ImageIO
{
public:
	virtual bool   Write(Image* img, FileHandle* file) = 0;
	virtual Image* Read(FileHandle* name) = 0;
	virtual int    Format()=0;
};
NS_YB_END