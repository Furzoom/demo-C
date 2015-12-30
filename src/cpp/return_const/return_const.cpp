#include <iostream>

using namespace std;
class Foo {
public:
    int a;
};

const Foo operator*(const Foo &f1, const Foo &f2)
{
    return f1;
}

Foo operator+(const Foo &f1, const Foo &f2)
{
    return f1;
}

void test()
{
    Foo f, result;
    result = f * f; // ok
    (f + f) = f;    // ok

//    (f * f) = f;    // error
}

int main()
{
    test();
    return 0;
}
