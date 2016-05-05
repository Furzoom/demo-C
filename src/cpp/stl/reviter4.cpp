#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> col;
    for (int i = 0; i < 9; ++i)
    {
        col.push_back(i);
    }
    list<int>::iterator pos;
    pos = find(col.begin(), col.end(), 5);
    cout << "pos: " << *pos << endl;

    list<int>::reverse_iterator rpos(pos);
    cout << "rpos: " << *rpos << endl;

    list<int>::iterator rrpos;
    // convert reverse iterator back to normal iterator
    rrpos =rpos.base();
    cout << "rrpos: " << *rrpos << endl;

    return 0;
}

