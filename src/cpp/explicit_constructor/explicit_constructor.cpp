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
    do_something(20);
    return 0;
}
