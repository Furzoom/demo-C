#ifndef _FILE_B_H
#define _FILE_B_H

#include "file_a.h"
class File_B {
public:
    int _b;
    File_B(File_A& a);
};

extern File_B fb;
#endif
