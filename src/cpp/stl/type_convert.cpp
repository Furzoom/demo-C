#include <iostream>

using namespace std;

class Foo
{
  public:
    class Bar
    {
      public:
        operator bool() const
        {
            cout << "Foo::Bar::bool()\n";
            return false;
        }
    };
    Foo(bool b = 0) { }
    Bar at(int n)
    {
        return bar;
    }
  private:
    Bar bar;
};

int main()
{
    Foo f;
    cout << std::boolalpha;
    cout << f.at(1) << endl;
    return 0;
}

