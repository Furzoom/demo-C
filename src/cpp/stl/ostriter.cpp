#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ostream_iterator<int> intWriter(cout, "\n");
    *intWriter = 42;
    *intWriter = 77;
    *intWriter = -2;
    *intWriter = 0;

    vector<int> col;
    col.reserve(10);
    for (int i = 0; i < 9; ++i)
    {
        col.push_back(i);
    }

    copy(col.begin(), col.end(), ostream_iterator<int>(cout));
    cout << endl;

    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " < "));
    cout << endl;

    return 0;
}

