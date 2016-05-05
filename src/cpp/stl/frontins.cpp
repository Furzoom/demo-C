#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    list<int> col;
    front_insert_iterator<list<int> > iter(col);
    *iter = 1;
    *iter = 2;
    *iter = 3;

    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    front_inserter(col) = 44;
    front_inserter(col) = 55;

    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    copy(col.begin(), col.end(), front_inserter(col));

    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

