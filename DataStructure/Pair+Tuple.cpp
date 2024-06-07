#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define dt(fmt) get<0>(fmt)
#define row(fmt) get<1>(fmt)
#define col(fmt) get<2>(fmt)

int main()
{
    pair<int,string> p1 = {1, "a"};
    cout << p1.first << " " << p1.second << endl;

    tuple<int, string, float> t1 = {1, "b", 1.1};
    cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;

    tuple<int,int,int> dv = {1,2,3};
    cout << dt(dv) << " " << row(dv) << " " << col(dv) << endl;
    return 0;
}