#include <bits/stdc++.h>
using namespace std;

int N;
int D[100000 + 10] = {0,};
int ans = INT_MIN;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    
    int dp[100000+10] = {0,};
    cin >> D[0];
    dp[0] = D[0];
    ans = max(ans, dp[0]);
    for (int i = 1; i < N; ++i) {
        cin >> D[i];
        dp[i] = max(D[i], dp[i-1]+D[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}
