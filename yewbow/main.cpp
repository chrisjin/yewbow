#include<stdio.h>
#include"ybImage.h"
#include"ybBMPImageIO.h"
#include"ybFileHangle.h"
#include<memory>
using namespace yewbow;
int main()
{
	Image* a = new Image(10, 10, Image::ePixelFormat::RGB);
	memset(a->Buffer(), 0, a->BytesPerImage());
	*a->Pixel(9, 0) = 255;
	FileHandle* file = new FileHandle();
	file->Create("test.bmp");
	BMPImageIO* io = new BMPImageIO();
	io->Write(a, file);
	file->Close();

}