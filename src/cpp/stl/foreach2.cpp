#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PrintInt {
  public:
    void operator() (int elem) const
    {
        cout << elem << " ";
    }
};

int main()
{
    vector<int> col;
    for (int i = 1; i < 10; ++i)
    {
        col.push_back(i);
    }
    for_each(col.begin(), col.end(), PrintInt());
    cout << endl;
    return 0;
}

