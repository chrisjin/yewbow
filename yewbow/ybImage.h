#pragma once
#include"ybBasicMacro.h"
#include"ybBasicTypes.h"
#include"ybImageIterator.h"

NS_YB_BEGIN

class YB_INTERFACE Image
{
	friend class ImageIterator;
public:
	enum ePixelFormat
	{
		RGBA,
		RGB,
		INDEXED_16,
		INDEXED_8,
		INDEXED_1
	};
	Image(int width, int height, ePixelFormat format = RGBA,int padding=4);
	ImageIterator GetIterator();
	tByte* Pixel(int x, int y);
	void Delete();

	int Width(){ return _width; }
	int Height(){ return _height; }
	int PixelFormat(){ return _format; }
	int BytesPerLine(){ return _bytes_per_line; }
	int BytesPerImage(){ return _bytes_per_img; }
	int BytesPerPixel(){ return _bytes_per_pixel; }
	int BitsPerPixel(){ return _bits_per_pixel; }
	tByte* Buffer(){ return _buffer; }
private:

	void _init();
	int _get_pixel_bytes();
	int _get_pixel_bits();
	void _eval_all();

	int _bytes_per_img;
	int _bytes_per_line;
	int _bytes_per_pixel;

	int _bits_per_pixel;
	tByte* _buffer;
	tByte* _palette;

	int _width;
	int _height;
	ePixelFormat _format;
	int _padding;
};


NS_YB_END