#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

template<class T>
inline void print_elements(const T& col, const char* optcstr = "")
{
    typename T::const_iterator pos;
    typedef typename T::value_type v_type;
    std::cout << optcstr;
    copy(col.begin(), col.end(), ostream_iterator<v_type>(cout, " "));
    std::cout << std::endl;
}

int main()
{
    list<int> col;

    for (int i = 0; i < 6; ++i)
    {
        col.push_back(i);
    }
    print_elements(col);

    return 0;
}
