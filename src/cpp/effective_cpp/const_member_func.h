#ifndef CONST_MEMBER_FUNC_H
#define CONST_MEMBER_FUNC_H

#include <string>
#include <cstring>

class TextBlock
{
  public:
//    explicit TextBlock(const std::string& s = "") : text(s) {}
    explicit TextBlock(const char* s = NULL)
    { 
        if (s != NULL) 
        {
            text = new char[std::strlen(s) + 1];
            std::strcpy(text, s);
        }
        else
        {
            text = NULL;
        }
    }
    ~TextBlock() { if (text) { delete [] text; text = NULL; } }
    const char& operator[] (size_t position) const
    { return text[position]; }
    char& operator[] (size_t position)
    { return text[position]; }
  private:
//    std::string text;
    char* text;
};

#endif
