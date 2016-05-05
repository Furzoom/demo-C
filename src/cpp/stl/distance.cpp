#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> col;
    for (int i = -3; i < 9; ++i)
    {
        col.push_back(i);
    }
    list<int>::iterator pos;
    pos = find(col.begin(), col.end(), 5);
    if (pos != col.end())
    {
        cout << "difference between beginning and 5: "
             << distance(col.begin(), pos) << endl;
    }
    else
    {
        cout << "5 not found" << endl;
    }
    return 0;
}

