#include <iostream>
#include <set>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    set<int> col;
    insert_iterator<set<int> > iter(col, col.begin());
    *iter = 1;
    *iter = 2;
    *iter = 3;

    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    inserter(col, col.begin()) = 44;
    inserter(col, col.end()) = 55;
    
    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    list<int> col2;
    copy(col.begin(), col.end(), inserter(col2, col2.begin()));
    
    copy(col2.begin(), col2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    copy(col.begin(), col.end(), inserter(col2, ++col2.begin()));

    copy(col2.begin(), col2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

