#include <iostream>
#include <set>
#include <iterator>

using namespace std;

template <typename T>
class RuntimeCmp
{
  public:
    enum cmp_mode {normal, reverse};
    
  private:
    cmp_mode mode;

  public:
    RuntimeCmp(cmp_mode m = normal) : mode(m) { }
    bool operator() (const T& t1, const T& t2) const {
        return mode == normal ? t1 < t2 : t2 < t1;
    }
    bool operator==(const RuntimeCmp& rc) {
        return mode == rc.mode;
    }
};

typedef set<int, RuntimeCmp<int> > IntSet;
void fill(IntSet& set);
void printElements(IntSet& set, string s = "set: ");

int main()
{
    IntSet col1;
    fill(col1);
    printElements(col1, "col1: ");

    RuntimeCmp<int> reverse_order(RuntimeCmp<int>::reverse);
    IntSet col2(reverse_order);
    fill(col2);
    printElements(col2, "col2: ");

    col1 = col2;
    col1.insert(3);
    printElements(col1, "col1: ");

    if (col1.value_comp() == col2.value_comp()) 
    {
        cout << "col1 and col2 have same sorting criterion\n";
    }
    else
    {
        cout << "col1 and col2 have different sorting criterion\n";
    }

    return 0;
}

void fill(IntSet& set)
{
    set.insert(4);
    set.insert(7);
    set.insert(5);
    set.insert(1);
    set.insert(6);
    set.insert(2);
    set.insert(5);
}

void printElements(IntSet& set, string s)
{
    cout << s;
    copy(set.begin(), set.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

