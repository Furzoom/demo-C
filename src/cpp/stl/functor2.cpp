#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class AddValue {
  private:
    int value;
  public:
    AddValue(int v) : value(v) { }
    void operator() (int& elem) const {
        elem += value;
    }
};

int main()
{
    vector<int> col;
    for (int i = 0; i < 10; ++i)
    {
        col.push_back(i);
    }

    cout << "Initialized: ";
    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for_each(col.begin(), col.end(), AddValue(10));

    cout << "After adding 10: ";
    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for_each(col.begin(), col.end(), AddValue(*col.begin()));

    cout << "After adding first element: ";
    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

