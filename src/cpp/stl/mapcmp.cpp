#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

/*
 * function object to compare strings
 */
class RuntimeStringCmp
{
  public:
    enum cmp_mode {normal, nocase};
  private:
    const cmp_mode mode;
    static bool nocase_compare(char c1, char c2)
    {
        return toupper(c1) < toupper(c2);
    }
  public:
    RuntimeStringCmp(cmp_mode m = normal) : mode(m) { }

    bool operator() (const string& s1, const string& s2) const
    {
        if (mode == normal)
        {
            return s1 < s2;
        }
        else
        {
            return lexicographical_compare(s1.begin(), s1.end(), 
                                           s2.begin(), s2.end(), 
                                           nocase_compare);
        }
    }
};

typedef map<string, string, RuntimeStringCmp> StringStringMap;
void fillAndPrint(StringStringMap& col);

int main()
{
    StringStringMap col;
    fillAndPrint(col);

    RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);
    StringStringMap col2(ignorecase);
    fillAndPrint(col2);

    return 0;
}

void fillAndPrint(StringStringMap& col)
{
    col["Deutschland"] = "Germany";
    col["deutsch"]     = "German";
    col["Haken"]       = "snag";
    col["arbeiten"]    = "work";
    col["Hund"]        = "dog";
    col["gehen"]       = "go";
    col["Unternehmen"] = "enterprise";
    col["unternehmen"] = "undertake";
    col["gehen"]       = "walk";
    col["Bestatter"]   = "undertaker";

    StringStringMap::iterator pos;
    cout.setf(ios::left, ios::adjustfield);
    for (pos = col.begin(); pos != col.end(); ++pos)
    {
        cout << setw(25) << pos->first.c_str() << " "
             << pos->second << endl;
    }
    cout << endl;
}
