#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream output("data.txt");
    if (!output)
    {
        cerr << "open file error\n";
    }
    output << "hello world!\n";
    output.close();
    ifstream input("data.txt");
    string s;
    input >> s;
    cout << s;
    return 0;
}

