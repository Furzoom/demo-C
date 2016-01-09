#include <iostream>

using namespace std;

class B {
public:
    virtual void print() = 0;
    virtual ~B() = 0;
};

B::~B() {
    cout << "~B()\n";
}

void B::print() {
    cout << "B::print()\n";
}

class D : public B {
public:
    void print() { cout << "D::print()\n"; }
    ~D() { cout << "~D()\n"; }
};

void test()
{
    D d;
    d.print();
}

int main()
{
    test();
    return 0;
}

