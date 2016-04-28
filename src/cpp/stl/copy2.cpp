#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    list<int> col1;

    for (int i = 1; i <= 9; ++i)
    {
        col1.push_back(i);
    }

    vector<int> col2;
    copy(col1.begin(), col1.end(), back_inserter(col2));
    for (vector<int>::iterator it = col2.begin(); it != col2.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    deque<int> col3;
    copy(col1.begin(), col1.end(), back_inserter(col3));
    for (deque<int>::iterator it = col3.begin(); it != col3.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    set<int> col4;
    copy(col1.begin(), col1.end(), inserter(col4, col4.begin()));
    for (set<int>::iterator it = col4.begin(); it != col4.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}

