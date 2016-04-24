#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

template<typename elemType>
void display_message(const string& msg, const vector<elemType>& vec);

bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int));

const vector<int>* fab_seq(int size);

const vector<int>* pen_seq(int size);

inline bool is_size_ok(int size);

int main()
{
    int arr1[] = {1, 2, 3};
    vector<int> v1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    display_message("first", v1);
    int result;
    if (seq_elem(30, result, fab_seq))
    {
        cout << result << endl;
    }
    else
    {
        cout << "failed" << endl;;
    }
    return 0;
}

template<typename elemType>
void display_message(const string& msg, const vector<elemType>& vec)
{
    cout << msg << ": ";
    for (unsigned int ix = 0; ix < vec.size(); ++ix)
    {
        cout << vec[ix] << ' ';
    }
    cout << endl;
}

bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int))
{
    const vector<int> *pseq = seq_ptr(pos);
    if (!pseq)
    {
        elem = 0;
        return false;
    }
    elem = (*pseq)[pos - 1];
    return true;
}

const vector<int>* fab_seq(int size)
{
    static vector<int> vec;
    if (!is_size_ok(size))
        return 0;
    for (int ix = vec.size(); ix < size; ++ix)
    {
        if (ix == 0 || ix == 1)
        {
            vec.push_back(1);
        }
        else
        {
            vec.push_back(vec[ix - 1] + vec[ix - 2]);
        }
    }
    return &vec;
}

const vector<int>* pen_seq(int size)
{
    // Pn = n*(3n-1)/2  1,5,12,22,35...
    const int max_size = 1024;
    if (size <= 0 || size > max_size)
    {
        return 0;
    }

    static vector<int> vec;
    for (int ix = vec.size(); ix < size; ++ix)
    {
        vec.push_back(ix * (3 * ix - 1) / 2);
    }
    return &vec;
}

inline bool is_size_ok(int size)
{
    const int max_size = 1024;
    if (size <= 0 || size > max_size)
    {
        cerr << "Oops: " << size << endl;
        return false;
    }
    return true;
}
