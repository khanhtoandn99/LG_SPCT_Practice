// Link: https://www.hackerrank.com/contests/app-b2-pretest-7/challenges/tran-and-backtracking
// Vietnamese: Hoan vi!
#include <iostream>
#include <algorithm>
using namespace std;

int va[10001] = {0,};
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) va[i] = i+1;
    while(next_permutation(begin(va), begin(va)+n)) {
        for (int i = 0; i < n; ++i) cout << va[i];
        cout << endl;
    }
    return 0;
}
