#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int square(int value)
{
    return value * value;
}

int main()
{
    set<int> col1;
    vector<int> col2;

    for (int i = 1; i < 10; ++i)
    {
        col1.insert(i);
    }

    copy(col1.begin(), col1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    transform(col1.begin(), col1.end(), back_inserter(col2), square);
    
    copy(col2.begin(), col2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
