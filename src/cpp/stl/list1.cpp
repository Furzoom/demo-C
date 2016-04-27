#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<char> col1;

    for (char c = 'a'; c <= 'z'; ++c)
    {
        col1.push_back(c);
    }

    list<char>::iterator pos;
    for (pos = col1.begin(); pos != col1.end(); ++pos)
    {
        cout << *pos << ' ';
        *pos = toupper(*pos);
    }
    cout << endl;

    while (!col1.empty()) 
    {
        cout << col1.front() << ' ';
        col1.pop_front();
    }
    cout << endl;

    return 0;
}
