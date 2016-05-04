#include <iostream>
#include <string>

using namespace std;

class Foo
{
  public:
    int i;
    float f;
    double d;
    short s;
    string str;
    Foo() {}
    void display()
    {
        cout << "i: " << i
             << "\nf: " << f
             << "\nd: " << d
             << "\ns: " << s
             << "\nstr: " << str << endl;
    }
};

void test()
{
    Foo f;
    cout << "\tf:\n";
    f.display();
}

int main()
{
    test();
    return 0;
}

