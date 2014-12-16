#pragma once
#include"ybBasicMacro.h"
#include"ybImageIO.h"
NS_YB_BEGIN
class BMPImageIO:public ImageIO
{
public:
	virtual bool Write(Image* img,FileHandle* handle);
	virtual Image* Read(FileHandle* handle);
	virtual int Format();
};
NS_YB_END
