#include <iostream>

using namespace std;

int main()
{
    char str[] = "char str[]";
    char str2[] = "char str2[]";
    
    const char *const cpc =str;
    const char *pc = str;
    char *const cp = str;

    cout << cpc << endl;
    cout << pc << endl;
    cout << cp << endl;

    cp[1] = 'x';
    cout << cp << endl;
    //cp = str2;              // error
    //pc[1] = 'Z';            // error
    pc = str2;
    //char *const cp2 = pc;   // error
    const char *pc2 = cpc;

    
    return 0;
}

