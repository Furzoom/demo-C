#include <iostream>
#include <algorithm>

using namespace std;

bool int_less(int a, int b)
{
    return a < b;
}

void test()
{
    cout << "max(1, 2, int_less): " << max(1, 2, int_less) << endl;
    cout << "min(1, 2, int_less): " << min(1, 2, int_less) << endl;
}

int main()
{
    test();
    return 0;
}

