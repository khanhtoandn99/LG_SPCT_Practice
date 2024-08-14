// Link: https://www.hackerrank.com/contests/app-b2-pretest-7/challenges/tran-and-backtracking
#include <iostream>
using namespace std;

bool vbin[10001] = {0,};
int n;

void backtrack(int i) {
    if (i == n) {
        for (int j = 0; j < n; ++j) cout << (int)vbin[j];
        cout << endl;
        return;
    }
    for (int j = 0; j < 2; ++j) {
        vbin[i] = (bool)j;
        backtrack(i+1);
    }
}

int main() {
    cin >> n;
    backtrack(0);
    return 0;
}
