#include <math.h>

class MyVector
{
public:
	float x;
	float y;
	float z;
	float w;

public:
	//������ ���� ���ϱ�
	float VectorLength3()
	{
		return sqrtf(x * x + y * y + z * z);
	}



	//������ ����ȭ
	void VectorNormal()
	{
		float Length = VectorLength3();
		x /= Length;
		y /= Length;
		z /= Length;

		return;
	}

	//������ ����
	float DotProduct(const MyVector& _Other)
	{
		return x * _Other.x + y * _Other.y + z * _Other.z;
	}

	//������ ����
	MyVector CrossProduct(const MyVector& _Right)
	{
		return MyVector(
			y * _Right.z - z * _Right.y,
			z * _Right.x - x * _Right.z,
			x * _Right.y - y * _Right.x
		);
	}



	//���Ϳ� ��Į���� ����
	MyVector& operator*=(const float _Value)
	{
		x *= _Value;
		y *= _Value;
		z *= _Value;

		return *this;
	}

	//���Ϳ� ��Į���� ����
	MyVector operator*(const float& _Value) const
	{
		return { x * _Value, y * _Value ,z * _Value };
	}

	//���Ͱ��� ���� ����
	MyVector operator+(const MyVector& _Value) const
	{
		return { x + _Value.x, y + _Value.y,z + _Value.z };
	}

	MyVector& operator+=(const MyVector& _Value)
	{
		x += _Value.x;
		y += _Value.y;
		z += _Value.z;

		return *this;
	}

	//���Ͱ��� ���� ����
	MyVector operator-(const MyVector& _Value) const
	{
		return { x - _Value.x, y - _Value.y,z - _Value.z };
	}

	MyVector& operator-=(const MyVector& _Value)
	{
		x -= _Value.x;
		y -= _Value.y;
		z -= _Value.z;

		return *this;
	}

public:
	MyVector(const float _X, const  float _Y, const float _Z) : x(_X), y(_Y), z(_Z) {	}

	MyVector() : x(0.0f), y(0.0f), z(0.0f) {};
	~MyVector() {};
};