#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> myvector;
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        myvector.push_back(i);
    }
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); )
    {
        print(myvector);
        
        myvector.erase(it);
    }
    return 0;
}
