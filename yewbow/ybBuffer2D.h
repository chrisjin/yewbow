#pragma once
#include"ybBasicMacro.h"
NS_YB_BEGIN
template<class T>
class Buffer2D
{
public:
	typedef T ElementType;
	Buffer2D(int width, int height,bool init=0)
		:_width(width), _height(height)
	{
		_buffer = new T[_width*_height];
		if (init)
		{
			memset(_buffer, 0, sizeof(T)*_width*_height);
		}
	}
	T* Element(int x, int y)
	{
		return &_buffer[y*_width + x];
	}
	~Buffer2D()
	{
		delete[] _buffer;
	}
private:
	int _width;
	int _height;
	T* _buffer;

};

NS_YB_END