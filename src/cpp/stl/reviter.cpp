#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void print(int elem)
{
    cout << elem << " ";
}

int main()
{
    list<int> col;
    for (int i = 0; i < 9; ++i)
    {
        col.push_back(i);
    }

    for_each(col.begin(), col.end(), print);
    cout << endl;
    for_each(col.rbegin(), col.rend(), print);
    cout << endl;
    return 0;
}

