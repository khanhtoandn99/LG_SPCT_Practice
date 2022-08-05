// Link: https://leetcode.com/problems/coin-change/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <limits.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int rem[10001];
        for (int i = 0; i < 10001; ++i) rem[i] = -1;
        int result = dp(coins, amount, rem);
        if (result == INT_MAX) return -1;
        return result;
    }

    int dp(vector<int>& coins, int amount, int rem[]) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;
        if (rem[amount] != -1) return rem[amount];
        
        int iMin = INT_MAX;
        for (int i = 0; i < coins.size(); ++i) {
            iMin = min(dp(coins, amount - coins.at(i), rem), iMin);
        }
        if (iMin < INT_MAX) ++iMin;
        rem[amount] = iMin;

        return iMin;
    }
    
};

int main()
{
    int N = 0;
    cout << "Input number of coins, N: ";
    cin >> N;

    vector<int> coins;
    for (int i = 0; i < N; ++i) {
        int k; cin >> k;
        coins.push_back(k);
    }

    int amount;
    cout << "Input amount:";
    cin >> amount;

    Solution sol;
    cout << sol.coinChange(coins, amount) << endl;
}