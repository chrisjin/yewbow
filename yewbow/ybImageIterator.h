#pragma once
#include"ybBasicTypes.h"

NS_YB_BEGIN
class Image;
class ImageIterator
{
public:
	ImageIterator(Image* m);
	bool MoveToNext();
	tByte* CurrentPixel();
	void Reset();
private:
	Image* _image;
	int _step;
	tByte* _endpos;
	tByte* _beginpos;
	tByte* _curentpos;
};
NS_YB_END