#pragma once
#include <iostream>

class VirtualExample
{
public:
	void Func()
	{
		std::cout << "�θ� Ŭ����" << std::endl;
	}

	virtual void VirtualFunc()
	{
		std::cout << "Virtual �θ� Ŭ����" << std::endl;
	}
};

class VirtualExampleSon : public VirtualExample
{
public:
	void Func()
	{
		std::cout << "�ڽ� Ŭ����" << std::endl;
	}

	void VirtualFunc()
	{
		std::cout << "Virtual �ڽ� Ŭ����" << std::endl;
	}
};

