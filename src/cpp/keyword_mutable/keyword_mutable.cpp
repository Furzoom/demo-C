#include <iostream>
#include <string>

using namespace std;

class Foo {
private:
    string text;
    mutable size_t text_length;
    mutable bool length_is_valid;
public:
    size_t length() const {
        if (!length_is_valid) {
            text_length = text.length();
            length_is_valid = true;
        }
        return text_length;
    }
};

void test()
{
    Foo f;
    f.length();
}

int main()
{
    test();
    return 0;
}

