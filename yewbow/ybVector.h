#include"ybBasicMacro.h"
#include<math.h>
NS_YB_BEGIN
template<class T, int num>
class Vector
{
public:
	enum
	{
		Length = num
	};
	Vector() 
	{
		memset(_data, 0, sizeof(T)*num);
	}
	T& operator()(int index)
	{
		return _data[index];
	}
	T Element(int index) const
	{
		return _data[index];
	}

	static double Distance(Vector<T, num> vec1, Vector<T, num> vec2)
	{
		double ret = 0;
		for (int i = 0; i < vec1.Length; i++)
		{
			ret += (vec1.Element(i) - vec2.Element(i))*(vec1.Element(i) - vec2.Element(i));
		}
		return sqrt(ret);
	}
private:
	T _data[num];
};
typedef Vector<double, 3> Vector3;
typedef Vector<double, 4> Vector4;
typedef Vector<double, 3> Point3;
typedef Vector<double, 2> Point2;
NS_YB_END