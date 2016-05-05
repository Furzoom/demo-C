#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

template<typename T>
void print(const T& t)
{
    copy(t.begin(), t.end(), ostream_iterator<typename T::value_type>(cout, " "));
    cout << endl;
}

int main()
{
    vector<int> vec;
    list<int> li;

    for (int i = 1; i < 9; ++i)
    {
        vec.push_back(i);
        li.push_front(i);
    }

    print(vec);
    print(li);
    iter_swap(vec.begin(), li.begin());
    print(vec);
    print(li);

    return 0;
}

