#pragma once
#include <iostream>

class VirtualExample
{
public:
	void VirtualFunc()
	{
		std::cout << "�θ� Ŭ����" << std::endl;
	}
};

class VirtualExampleSon : public VirtualExample
{
public:
	void VirtualFunc()
	{
		std::cout << "�ڽ� Ŭ����" << std::endl;
	}
};

