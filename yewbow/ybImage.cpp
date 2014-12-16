#include"ybImage.h"
#include"ybMemory.h"
#include"ybDebug.h"
NS_YB_BEGIN

Image::Image(int width, int height, ePixelFormat format, int padding)
:_width(width), _height(height), _format(format), _padding(padding)
{
	_init();
}

ImageIterator Image::GetIterator()
{
	return ImageIterator(this);
}
void Image::Delete()
{
	Free(_buffer);
}
tByte* Image::Pixel(int x, int y)
{
	return &_buffer[y*_bytes_per_line+x*_bytes_per_pixel];
}

int Image::_get_pixel_bytes()
{
	switch (_format)
	{
	case RGB:
		return 24;
	case RGBA:
		return 32;
		break;
	default:
		DebugMessage("Not Supported\n!");
		return 0;
	}
}

void  Image::_eval_all()
{
	int linenum = _bytes_per_pixel*_width;
	int remainder = linenum%_padding;
	_bytes_per_line = remainder ? linenum + _padding - remainder : linenum;
	_bytes_per_img = _bytes_per_line*_width;
	_bytes_per_pixel = _get_pixel_bytes();
	
}

void Image::_init()
{
	_eval_all();
	_buffer = (tByte*)Malloc(_bytes_per_img);
}
NS_YB_END
