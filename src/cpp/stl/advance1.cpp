#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> col;
    for (int i = 1; i <= 9; ++i)
    {
        col.push_back(i);
    }

    list<int>::iterator pos = col.begin();
    cout << *pos << endl;
    advance(pos, 3);
    cout << *pos << endl;
    advance(pos, -1);
    cout << *pos << endl;

    return 0;
}
