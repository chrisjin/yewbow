#pragma once
#include"ybBasicMacro.h"
NS_YB_BEGIN
template<class T, int row, int column>
class Matrix
{
public:
	enum 
	{
		Row = row,
		Column = column
	};
	Matrix(bool init=1)
	{
		memset(_data,0,sizeof(T)*row*column);
	}
	double& operator()(int row, int column)
	{
		return _data[row][column];
	}
	double Element(int row, int column) const
	{
		return _data[row][column];
	}
private:
	T _data[row][column];
};

typedef Matrix<double, 4, 4> Matrix4x4;
typedef Matrix<double, 3, 3> Matrix3x3;
NS_YB_END