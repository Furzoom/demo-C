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
        // 1.
//        return text[pos];
        // 2
        return const_cast<char &>(static_cast<const Foo&>(*this)[pos]);
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
