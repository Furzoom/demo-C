#include "file_a.h"
#include <iostream>

using namespace std;

File_A::File_A(int a) : _a(a)
{
    cout << "In File_A(int a): _a = " << a << endl;
}

File_A file(5);
