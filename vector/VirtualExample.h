#pragma once
#include <iostream>

class VirtualExample
{
public:
	void Func()
	{
		std::cout << "부모 클래스" << std::endl;
	}

	virtual void VirtualFunc()
	{
		std::cout << "Virtual 부모 클래스" << std::endl;
	}
};

class VirtualExampleSon : public VirtualExample
{
public:
	void Func()
	{
		std::cout << "자식 클래스" << std::endl;
	}

	void VirtualFunc()
	{
		std::cout << "Virtual 자식 클래스" << std::endl;
	}
};

