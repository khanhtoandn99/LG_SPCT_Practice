// Link: https://www.hackerrank.com/contests/app-b2-pretest-7/challenges/tran-and-backtracking
// Vietnamese: To hop!
/**
 * @brief:
 * Array with n=4 elements [1,2,3,4]
 * Then, choose k=3 from Array
 * ==> It should be:
 * 123
 * 124
 * 134
 * 234
*/
#include <iostream>
#include <algorithm>
using namespace std;

int va[10001] = {0,};
int n;
int k;
int num = 0;


int main() {
    cin >> n >> k;
    for (int i = 0; i < n+1; ++i) va[i] = i;

    // print 1st subset:
    for  (int j = 1; j <= k; ++j) cout << va[j];
    cout << endl;
    ++num;
    while (1) {
        int i = k;
        while (i > 0 && va[i] == n-k+i) --i;
        if (i <= 0) return 0;
        ++va[i];
        for (int j = i+1; j <= k; ++j) {
            va[j] = va[j-1] + 1;
        }
        // print subset:
        for  (int j = 1; j <= k; ++j) cout << va[j];
        cout << endl;
        ++num;
    }
    cout << "num of subset: " << num << endl;
    return 0;
}
