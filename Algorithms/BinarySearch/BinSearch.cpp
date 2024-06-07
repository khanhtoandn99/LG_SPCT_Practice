#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binSearch(int a[], int n, int x)
{
    int mi = 0, li = 0, ri = n-1;
    while (li < ri)
    {
        mi = (ri + li) / 2;
        if (a[mi] == x) return mi;
        else if (a[mi] > x) {
            ri = mi-1;
        } else {
            li = mi+1;
        }
    }
    return -1;
}

int main()
{
    int a[15] = {1,3,5,7,9,10,12,14,22,45,50};
    vector<int> vA(a, a+15);
    int k;
    cin >> k;
    // cout << binSearch(a, 11, k) << endl;
    vector<int>::iterator lowwer = lower_bound(vA.begin(), vA.end(), k);
    cout << (lowwer - vA.begin()) << endl;

    cin >> k;
    vector<int>::iterator upper = upper_bound(vA.begin(), vA.end(), k);
    cout << (upper - vA.begin()) << endl;
    return 0;
}