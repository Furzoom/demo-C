#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    string tword;
    map<string, int> words;
    while (cin >> tword)
        words[tword] ++;
    map<string, int>::const_iterator it = words.begin();
    for (; it != words.end(); ++it)
        cout << it->first << ": " << it->second << endl;
    return 0;
}

