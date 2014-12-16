#include"ybImageIOManager.h"
#include"ybImageIO.h"
#include"ybDebug.h"
#include"ybBMPImageIO.h"
NS_YB_BEGIN
YB_SINGLETON_IMPL(ImageIOManager)
ImageIOManager::ImageIOManager()
{
	AddIO(new BMPImageIO());
}


void ImageIOManager::AddIO(ImageIO* io)
{
	_io[io->Format()] = io;
}

int __getformat(FileHandle* filehandle)
{
	return FORMAT_BMP;
}

Image* ImageIOManager::Read(FileHandle* name)
{
	int format = __getformat(name);
	map<int,ImageIO*>::iterator itr=_io.find(format);
	if (_io.end() != itr)
	{
		return _io[format]->Read(name);
	}
	else
	{
		DebugMessage("Not Supported!\n");
		return 0;
	}
}
bool ImageIOManager::Write(Image* img, FileHandle* name)
{
	int format = __getformat(name);
	map<int, ImageIO*>::iterator itr = _io.find(format);
	if (_io.end() != itr)
	{
		return _io[format]->Write(img,name);
	}
	else
	{
		DebugMessage("Not Supported!\n");
		return 0;
	}
}

NS_YB_END