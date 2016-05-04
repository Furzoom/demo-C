#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void print(int elem)
{
    cout << elem << " ";
}

int main()
{
    deque<int> col;
    for (int i = 0; i < 9; ++i)
    {
        col.push_back(i);
    }
    deque<int>::iterator pos1;
    pos1 = find(col.begin(), col.end(), 2);
    deque<int>::iterator pos2;
    pos2 = find(col.begin(), col.end(), 7);
    for_each(pos1, pos2, print);
    cout << endl;

    deque<int>::reverse_iterator rpos1(pos1), rpos2(pos2);
    for_each(rpos2, rpos1, print);
    cout << endl;

    return 0;
}


