#include<stdio.h>
#include"ybImage.h"
#include"ybBMPImageIO.h"
#include"ybFileHangle.h"
#include<memory>
#include"ybMatrix.h"
#include"ybMath.h"
using namespace yewbow;
int main()
{
	Matrix4x4 mat;
	Math::Identity(mat);
	Vector4 vec;
	vec(0) = 1; vec(1) = 2; vec(2) = 3; vec(3) = 4;
	Math::Multiply(vec, mat, vec);
	for (int i = 0; i < vec.Length; i++)
	{
		printf("%1.1f ", vec.Element(i));
	}

	Image* a = new Image(10, 10, Image::ePixelFormat::RGB);
	memset(a->Buffer(), 0, a->BytesPerImage());
	*a->Pixel(9, 0) = 255;
	FileHandle* file = new FileHandle();
	file->Create("test.bmp");
	BMPImageIO* io = new BMPImageIO();
	io->Write(a, file);
	file->Close();
	getchar();

}