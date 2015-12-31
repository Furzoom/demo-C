#include "base.h"
#include "derived.h"

void test()
{
    Base b1;
    // error
//    Base b2(b1);
    Derived d1;
    // error
//    Derived d2(d1);
}

int main()
{
    test();
    return 0;
}

