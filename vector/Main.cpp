#include <iostream>
#include "MyVector.h"
#include "MyMatrix.h"
#include "VirtualExample.h"


class B;
class A
{
    friend B;
private:
    void Func() {
        std::cout << "A Func" << std::endl;
    }
};

class B
{
private:
    A* m_pA;

public:
    void Func() {
        m_pA->Func();
    }

public:
    B(A& _Other)
    {
        m_pA = &_Other;
    }
};


int main()
{
    A aa = A();
    B bb = B(aa);

    bb.Func();

	return 0;
}

