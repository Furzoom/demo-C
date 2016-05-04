#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> col;
    for (int i = 0; i < 9; ++i)
    {
        col.push_back(i);
    }
    vector<int>::iterator pos;
    pos = find(col.begin(), col.end(), 5);
    
    cout << "pos: " << *pos << endl;
    
    vector<int>::reverse_iterator rpos(pos);
    cout << "rpos: " << *rpos << endl;
    return 0;
}

