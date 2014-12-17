#include<math.h>
#include"ybMath.h"
NS_YB_BEGIN

void Math::Multiply(Matrix4x4& out,const Matrix4x4& mat1,const Matrix4x4& mat2)
{
	for (int i = 0; i < out.Row; i++)
	{
		for (int j = 0; j < out.Column; j++)
		{
			double result = 0;
			for (int k = 0; k < out.Row; k++)
			{
				result += (mat1.Element(i, k)*mat2.Element(k,j));
			}
			out(i, j) = result;
		}
	}
}

void Math::Multiply(Vector4& out, const Matrix4x4& mat, const Vector4& vec)
{
	for (int i = 0; i < out.Length; i++)
	{
		double result = 0;
		for (int j = 0; j < out.Length; j++)
		{
			result += mat.Element(i, j)*vec.Element(j);
		}
		out(i) = result;
	}
}
void Math::Identity(Matrix4x4& out)
{
	for (int i = 0; i < out.Row; i++)
	{
		out(i, i) = 1.0;
	}
}


double Math::Distance(const Vector4& vec1, const Vector4& vec2)
{
	return Vector4::Distance(vec1, vec2);
}
double Math::Distance(const Vector3& vec1, const Vector3& vec2)
{
	return Vector3::Distance(vec1, vec2);
}
NS_YB_END