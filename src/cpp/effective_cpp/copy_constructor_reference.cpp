#include <iostream>
#include <string>
using namespace std;

template<typename T>

class NamedObject
{
  public:
    NamedObject(string& s, const T& t) : name(s), val(t) { }
    void display()
    {
        cout << "name: " << name
             << "\nval: " << val << endl;
    }
    string& name;
    const T val;
};

void test()
{
    string newDog("new");
    string oldDog("old");
    NamedObject<int> n(newDog, 2);
    NamedObject<int> o(n);
    n.display();
    o.display();
    n.name = "what";
    n.display();
    o.display();

    // error
    //n = o;

}

int main()
{
    test();
    return 0;
}

