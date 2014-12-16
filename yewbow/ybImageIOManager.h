#pragma once
#include"ybBasicMacro.h"
#include<map>
using namespace std;
NS_YB_BEGIN
class ImageIO;
class Image;
class FileHandle;
class ImageIOManager
{
	YB_SINGLETON_DCLR(ImageIOManager)
public:
	ImageIOManager();
	void AddIO(ImageIO* io);
	Image* Read(FileHandle* name);
	bool Write(Image* img, FileHandle* name);
private:
	map<int, ImageIO*> _io;
};
NS_YB_END