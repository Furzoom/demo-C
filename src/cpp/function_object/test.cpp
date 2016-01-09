#include <iostream>

using namespace std;

template<class ObjPtr, class ObjFunPtr>
class Functor {
private:
    ObjPtr _obj;
    ObjFunPtr _objfn;
public:
    Functor(const ObjPtr& obj, const ObjFunPtr& objfn) 
        : _obj(obj), _objfn(objfn) {}
    void operator()() {
        ((*_obj).*_objfn)();
    }
};


class Foo {
public:
    void print() { cout << "Foo::print()\n"; }
};

typedef void (Foo::*fntype)(void);

int main()
{
    Foo f;
    Functor<Foo *, fntype> fn(&f, &Foo::print);
    fn();
    return 0;
}
