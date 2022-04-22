#include <iostream>
#include "MyVector.h"
#include "MyMatrix.h"
#include "VirtualExample.h"


class FriendExampleB;
class FriendExampleA
{
    friend FriendExampleB;
private:
    void Func() {
        std::cout << "FriendExampleA Func" << std::endl;
    }
};

class FriendExampleB
{
private:
    FriendExampleA* m_pA;

public:
    void Func() {
        m_pA->Func();
    }

public:
    FriendExampleB(FriendExampleA& _Other)
    {
        m_pA = &_Other;
    }
};


int main()
{
    FriendExampleA FEA = FriendExampleA();
    FriendExampleB FEB = FriendExampleB(FEA);

    FEB.Func();   



	return 0;
}

