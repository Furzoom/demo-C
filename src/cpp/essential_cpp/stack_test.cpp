#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

void test()
{
    Stack s;
    cout << "empty(): " << s.empty() << "\nsize(): " << s.size();
    cout << "\nfull(): " << s.full() << endl; 
    s.push("a");
    s.push("b");
    s.push("c");
    s.push("d");
    s.push("f");
    s.push("e");
    s.push("e");
    string str;
    cout << "empty(): " << s.empty() << "\nsize(): " << s.size();
    cout << "\nfull(): " << s.full() << endl; 

    s.peek(str);
    cout << "s.peek(): " << str << endl;

    string to_find("f");
    cout << "find(\"f\"): " << s.find(to_find) << endl;
    to_find = "g";
    cout << "find(\"g\"): " << s.find(to_find) << endl;

    cout << "count(\"" << to_find << "\"): " << s.count(to_find) << endl;
    to_find = "e";
    cout << "count(\"" << to_find << "\"): " << s.count(to_find) << endl;

    while (!s.empty())
    {
        s.pop(str);
        cout << "s.pop(): " << str << endl; 
    }
    cout << endl;
    
    cout << "empty(): " << s.empty() << "\nsize(): " << s.size();
    cout << "\nfull(): " << s.full() << endl; 
}

int main()
{
    test();
    return 0;
}
