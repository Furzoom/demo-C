#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    set<int> col1;

    for (int i = 0; i <= 9; ++i)
    {
        col1.insert(i);
    }

    copy(col1.begin(), col1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    int num = col1.erase(3);
    cout << "number of removed elements: " << num << endl;

    copy(col1.begin(), col1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    return 0;
}
