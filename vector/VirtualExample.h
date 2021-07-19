#pragma once
#include <iostream>

class VirtualExample
{
public:
	void VirtualFunc()
	{
		std::cout << "부모 클래스" << std::endl;
	}
};

class VirtualExampleSon : public VirtualExample
{
public:
	void VirtualFunc()
	{
		std::cout << "자식 클래스" << std::endl;
	}
};

