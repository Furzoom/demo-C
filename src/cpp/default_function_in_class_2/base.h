#ifndef _BASH_H
#define _BASH_H

class Base {
public:
    Base() {};
    ~Base() {};
private:
    Base(const Base& b);
    Base& operator=(const Base& b);
};

#endif
