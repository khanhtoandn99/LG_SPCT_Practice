#include <iostream>
#include <bitset>
#include <string>
using namespace std;



int main()
{
    uint32_t n;
    cin >> n;
    int x = pow(2,n);
    cout << x << endl;
    for (int i = 0; i < x; ++i) {
        int ii = i;
        for (int j = 0; j < n; ++j) {
            bitset<12> b(ii);
            cout << b << endl;
            // string x = b.to_string();
        }
    }
}