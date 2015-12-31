#include "file_b.h"
#include <iostream>

using namespace std;

File_B::File_B(File_A& a) : _b(a._a)
{
    cout << "In File_B(File_A& a): _b = " << _b << endl;
}

File_B fb(file);
