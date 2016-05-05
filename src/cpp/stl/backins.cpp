#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> col;
    back_insert_iterator<vector<int> > iter(col);
    *iter = 1;
    *iter = 2;
    *iter = 3;

    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    back_inserter(col) = 44;
    back_inserter(col) = 55;

    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    col.reserve(2 * col.size());
    copy(col.begin(), col.end(), back_inserter(col));

    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}


