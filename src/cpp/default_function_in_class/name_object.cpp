#include <iostream>
#include <string>

using namespace std;

template<class T> class NameObject {
public:
    NameObject(std::string& name, const T& value) : name_value(name), object_value(value) {}
    void print() { std::cout << name_value << ": " << object_value << std::endl;}
private:
    std::string& name_value;
    const T object_value;
};

void test()
{
    string new_dog("Haul");
    string old_dog("Satch");
    NameObject<int> h(new_dog, 2);
    h.print();
    NameObject<int> s(old_dog, 3);
    s.print();
    h = s;
    h.print();
}

int main() 
{
    test();
    return 0;
}
