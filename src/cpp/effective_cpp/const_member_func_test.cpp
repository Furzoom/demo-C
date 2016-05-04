#include "const_member_func.h"
#include <iostream>

using namespace std;

int main()
{
    TextBlock tb("qwertyuiopasdfghjklzxcvbnm");
    const TextBlock ctb("qwertyuiopasdfghjklzxcvbnm");
    cout << tb[1] << endl;
    cout << ctb[1] << endl;
    tb[0] = 'a';
    ctb[0] = 'b';
    cout << ctb[0] << endl;
    return 0;
}

