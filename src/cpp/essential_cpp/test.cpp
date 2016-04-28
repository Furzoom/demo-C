#include <iostream>

using namespace std;

class Foo
{
    public:
        Foo() { cout << "Foo()\n"; }
        ~Foo() { cout << "~Foo()\n"; }
};

void test(Foo f)
{
    cout << "test()\n";
}

int main()
{

    test(Foo());
    cout << "test over\n";
    return 0;
}
