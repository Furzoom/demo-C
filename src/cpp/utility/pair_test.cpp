#include <iostream>
#include <utility>

using namespace std;

void test()
{
    pair<int, char *> p1 = make_pair(1, 'abc');
    pair<int, char *> p2 = pair(1, 'abd');
    cout << (p1 < p2) << endl;
}

int main()
{
    test();
    return 0;
}

