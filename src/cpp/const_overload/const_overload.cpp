#include <iostream>
#include <string>

using namespace std;

class Foo {
private:
    string text;
public:
    Foo(string s) : text(s) {}
    const char& operator[](size_t pos) const {
        cout << "in operator[] const \n";
        return text[pos];
    }
    const char& operator[](size_t pos) {
        cout << "in operator[]\n";
        return text[pos];
    }
};

void test()
{
    Foo f("hello");
    f[1];
    const Foo f2("hello");
    f2[1];
}

int main()
{
    test();
    return 0;
}
