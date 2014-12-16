#include "ybBMPImageIO.h"
#include"ybImage.h"
#include<windows.h>
#include"ybFileHangle.h"
NS_YB_BEGIN
bool BMPImageIO::Write(Image* img, FileHandle* handle)
{
	int header_offset = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	int debug = img->BytesPerImage();
	BITMAPFILEHEADER  header = { 0x4d42, debug + header_offset, 0, 0, header_offset };

	BITMAPINFOHEADER  info = { sizeof(BITMAPINFOHEADER), 
		img->Width(), img->Height(), 1, img->BitsPerPixel(), 0, img->BytesPerImage(), 0, 0, 0, 0 };
	handle->Write(&header, sizeof(BITMAPFILEHEADER));
	handle->Write(&info, sizeof(BITMAPINFOHEADER));
	handle->Write(img->Buffer(),img->BytesPerImage());
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