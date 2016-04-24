#include <iostream>

using namespace std;

class MyClass
{
public:
    template <class T>
    void f(T t) { }
};

template <class T>
class MyClass2
{
private:
    T value;
public:
    void assign (const MyClass2<T>& x) { value = x.value; }
    template <class X>
    void assign2 (const MyClass2<X>& x) { value = x.getValue(); }
    T getValue() const { return value; }
};



void test()
{
    MyClass cls;
    cls.f(1);
    cls.f(1.1);

    MyClass2<double> d;
    MyClass2<int> i;
    d.assign(d);
    //d.assign(i);            // error

    d.assign2(d);
    d.assign2(i);


}

int main()
{
    test();
    return 0;
}
