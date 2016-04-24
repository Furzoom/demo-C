#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

template<int value>
void add(int& elem)
{
    elem += value;
}

int main()
{
    vector<int> col;
    for (int i = 0; i < 10; ++i)
    {
        col.push_back(i);
    }
    for_each(col.begin(), col.end(), add<10>);
    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}

