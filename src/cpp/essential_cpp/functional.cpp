#include <iostream>
#include <functional>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> filter(const vector<int> &vec, int val, const less<int> &lt)
{
    vector<int> nvec;
    vector<int>::const_iterator iter = vec.begin();
    while ((iter = find_if(iter, vec.end(), bind2nd(lt, val))) != vec.end())
    {
        nvec.push_back(*iter);
        iter++;
    }
    return nvec;
}

int main()
{
    vector<int> vec;
    for (int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }
    vec[5] = 7;
    vector<int> result = filter(vec, 7, less<int>());
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
