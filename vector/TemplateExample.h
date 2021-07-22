#pragma once

template <typename T>
class TemplateExample
{
private:
	T X;
	T Y;
public:
	TemplateExample(T x, T y)
	{
		X = x;
		Y = y;
	}
	int add(int x, int y)
	{
		return x + y;
	}

	float add(float x, float y)
	{
		return x + y;
	}

	T add(T x, T y)
	{
		return x + y;
	}
};

