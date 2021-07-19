#include <iostream>
#include "MyVector.h"
#include "MyMatrix.h"
#include "VirtualExample.h"


int main()
{
	VirtualExample* ex = new VirtualExampleSon;

	ex->VirtualFunc();

	return 0;
}