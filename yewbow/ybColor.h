#pragma once
#include"ybBasicTypes.h"
NS_YB_BEGIN
struct RGB
{
	RGB(tUChar rr, tUChar gg, tUChar bb):R(rr),G(bb),B(bb){}
	tUChar R;
	tUChar G;
	tUChar B;
};
struct RGBA
{
	RGBA(tUChar rr, tUChar gg, tUChar bb,tUChar aa) :R(rr), G(bb), B(bb),A(aa){}
	tUChar R;
	tUChar G;
	tUChar B;
	tUChar A;
};

NS_YB_END