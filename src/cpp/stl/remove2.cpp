#include <iostream>
#include <list>
#include <iterator> // ostream_iterator
#include <algorithm>

using namespace std;

int main()
{
    list<int> col;

    for (int i = 0; i < 6; ++i)
    {
        col.push_back(i);
        col.push_front(i);
    }

    cout << "pre: ";
    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // remove all elements with value 3
    list<int>::iterator end = remove(col.begin(), col.end(), 3);

    cout << "post: ";
    copy(col.begin(), end, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "number of removed elements: " << distance(end, col.end()) << endl;

    col.erase(end, col.end());
    cout << "after removed: ";
    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


    return 0;
}

