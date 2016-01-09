#include <iostream>

using namespace std;

class A {
public:
    explicit A() { cout << "in A()\n"; }
    A(const A& r) { cout << "in A(const A&)\n"; }
    A& operator=(const A& r) { cout << "in operator=(const A&)\n"; }
};

void test()
{
    A a1;
    A a2(a1);
    a1 = a2;
    A a3 = a2;
}

int main()
{
    test();
    return 0;
}


