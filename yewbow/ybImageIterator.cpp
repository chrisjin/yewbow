#include"ybImageIterator.h"
#include"ybImage.h"
NS_YB_BEGIN
ImageIterator::ImageIterator(Image* img) :_image(img)
{
	_step = img->_bytes_per_pixel;
	_curentpos = img->_buffer;
	int bytenum = img->_bytes_per_line*img->_height;

	_beginpos = _image->_buffer;
	_endpos = _image->_buffer + bytenum;

	_curentpos = _beginpos;
}
bool ImageIterator::MoveToNext()
{
	if (_curentpos <= _endpos)
	{
		_curentpos += _step;
		return true;
	}
	else
		return false;

}
tByte* ImageIterator::CurrentPixel()
{
	return _curentpos;
}
void ImageIterator::Reset()
{
	_curentpos = _beginpos;
}
NS_YB_END