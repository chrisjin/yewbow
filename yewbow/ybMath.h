#pragma once
#include"ybBasicMacro.h"
#include"ybMatrix.h"
#include"ybVector.h"
NS_YB_BEGIN


class Math
{
public:
	static void Multiply(Matrix4x4& out, const Matrix4x4& mat1, const Matrix4x4& mat2);
	static void Multiply(Vector4& out, const Matrix4x4& mat, const Vector4& vec);
	static void Identity(Matrix4x4& out);
	static double Distance(const Vector4& vec1,const Vector4& vec2);
	static double Distance(const Vector3& vec1,const Vector3& vec2);
};

NS_YB_END