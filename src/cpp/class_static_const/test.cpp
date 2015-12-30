#include "a.h"
#include <iostream>

using namespace std;

void test()
{
    A a;
    cout << a.num << endl;
    cout << &a.num << endl;
}

int main()
{
    test();
    return 0;
}

