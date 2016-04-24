#include <iostream>
#include <vector>
#include <string>
#include <iterator> // istream_iterator and ostream_iterator
#include <algorithm>

using namespace std;

int main()
{
    vector<string> col1;

    copy(istream_iterator<string>(cin), istream_iterator<string>(),
            back_inserter(col1));
    sort(col1.begin(), col1.end());
    unique_copy(col1.begin(), col1.end(), 
            ostream_iterator<string>(cout, "\n"));
    return 0;
}
