// Link: https://www.hackerrank.com/contests/app-b2-pretest-7/challenges/tran-and-backtracking
// Vietnamese: To hop lap!
// Very popular for Exhaustive search!
/**
 * @brief:
 * Array with n=4 elements [1,2,3,4]
 * Then, choose k=3 from Array
 * ==> It should be:
 * 111
 * 112
 * 113
 * 114
 * 121
 * 122
 * 123
 * 124
 * 131
 * 132
 * 133
 * 134
 * 141
 * 142
 * 143
 * 144
 * 211
 * 212
 * 213
 * 214
 * 221
 * 222
 * 223
 * 224
 * 231
 * 232
 * 233
 * 234
 * 241
 * 242
 * 243
 * 244
 * 311
 * 312
 * 313
 * 314
 * 321
 * 322
 * 323
 * 324
 * 331
 * 332
 * 333
 * 334
 * 341
 * 342
 * 343
 * 344
 * 411
 * 412
 * 413
 * 414
 * 421
 * 422
 * 423
 * 424
 * 431
 * 432
 * 433
 * 434
 * 441
 * 442
 * 443
 * 444
*/
#include <iostream>
#include <algorithm>
using namespace std;

int va[10001] = {0,};
int n;
int k;
int num = 0;

void backtrack(int i) {
    if (i == k) {
        for (int j = 0; j < k; ++j) cout << va[j];
        cout << endl;
        ++num;
        return;
    }
    for (int j = 1; j <= n; ++j) {
        va[i] = j;
        backtrack(i+1);
    }

}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) va[i] = i+1;
    backtrack(0);
    cout << "num of subset: " << num << endl;
    return 0;
}
