#include <iostream>
#include <list>
#include <algorithm>
//#include <functional>

using namespace std;

int main()
{
    list<int> col1;
    list<int>::iterator pos;

    for (int i = 20; i <= 40; ++i)
    {
        //col1.push_back(i);
        col1.push_front(i);
    }

    pos = find(col1.begin(), col1.end(), 3);
    reverse(pos, col1.end());
    
    list<int>::iterator pos25, pos35;
    pos25 = find(col1.begin(), col1.end(), 25);
    pos35 = find(col1.begin(), pos25, 35);

    if (pos35 != pos25)
    {
        cout << "max: " << *max_element(pos35, ++pos25) << endl;
    }
    else
    {
        pos35 = find(pos25, col1.end(), 35);
        cout << "max: " << *max_element(pos25, ++pos35) << endl;
    }


    //cout << "max: " << *max_element(pos25, pos35) << endl;
    //cout << "max: " << *max_element(pos25, ++pos35) << endl;
// TODO:
/*    pos = find_if(col1.begin(), col1.end(), 
            compose_f_gx_hx(logical_or<bool>(),
                            bind2nd(equal_to<int>(), 25),
                            bind2nd(equal_to<int>(), 35)));
*/
    switch (*pos)
    {
        case 25:
            pos25 = pos;
            pos35 = find(++pos, col1.end(), 35);
            cout << "25 come first\n";
            break;
        case 35:
            pos25 = pos;
            pos35 = find(++pos, col1.end(), 25);
            cout << "35 com first\n";
            break;
        default:
            cout << "not found\n";
            break;
    }
    return 0;
}
   
