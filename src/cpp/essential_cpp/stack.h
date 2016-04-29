#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Stack {
  public:
    bool push(const string&);
    bool pop(string &elem);
    bool peek(string &elem);
    bool empty();
    bool full();
    int size() { return _stack.size(); }
    bool find(const string& s);
    int count(const string& s);
  private:
    vector<string> _stack;
};

inline bool Stack::empty()
{
    return _stack.empty();
}

inline bool Stack::full()
{
    return _stack.size() == _stack.max_size();
}

inline bool Stack::find(const string& s)
{
    return _stack.end() != std::find(_stack.begin(), _stack.end(), s); 
}

inline int Stack::count(const string& s)
{
    return std::count(_stack.begin(), _stack.end(), s);
}
