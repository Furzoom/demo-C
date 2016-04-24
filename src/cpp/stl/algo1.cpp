#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> col1;
    vector<int>::iterator pos;

    col1.push_back(2);
    col1.push_back(5);
    col1.push_back(4);
    col1.push_back(1);
    col1.push_back(6);
    col1.push_back(3);

    // find and print minimum and maximum elements
    pos = min_element(col1.begin(), col1.end());
    cout << "min: " << *pos << endl;
    pos = max_element(col1.begin(), col1.end());
    cout << "max: " << *pos << endl;

    // sort all elements
    sort(col1.begin(), col1.end());

    // find the first element with value 3
    pos = find(col1.begin(), col1.end(), 3);
    reverse(pos, col1.end());

    for (pos = col1.begin(); pos != col1.end(); ++pos)
    {
        cout << *pos << ' ';
    }
    cout << endl;
    return 0;
}

