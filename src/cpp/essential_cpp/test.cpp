#include <iostream>

using namespace std;

class Foo
{
    public:
        Foo() { cout << "Foo()\n"; }
        Foo(const Foo& f) { cout << "Foo(const Foo& f)\n"; }
        Foo(Foo& f) { cout << "Foo(Foo& f)\n"; }
        ~Foo() { cout << "~Foo()\n"; }
};

void test(Foo f)
{
    cout << "test()\n";
}

void test1(const Foo f)
{
    cout << "test1()\n";
}

int main()
{
    Foo f;
    test(f);
    cout << "test over\n";
    const Foo f1;
    test1(f1);
    cout << "test over\n";
    return 0;
}
