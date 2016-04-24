#include <iostream>

using namespace std;

template <class  T>
inline const T& c_max (const T& a, const T& b)
{
    return a < b ? b : a;
}

void test()
{
    // implicitly
    cout << c_max(1, 2) << endl;
    // explicitly
    cout << c_max<double>(1, 5.4) << endl;
}

int main()
{
    test();
    return 0;
}

