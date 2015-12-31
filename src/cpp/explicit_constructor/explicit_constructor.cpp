#include <iostream>

class A {
    public:
        explicit A(int a = 0):_a(a){ std::cout << _a << std::endl;}
    private:
        int _a;
};

void do_something(const A &a){
}

int main()
{
    do_something(A());
    do_something(A(10));
    
    // this will cause error
//    do_something(20);

    // call explicit conversion
    do_something(static_cast<A>(20));

    // not recommanded
    do_something((A)30);
    return 0;
}
