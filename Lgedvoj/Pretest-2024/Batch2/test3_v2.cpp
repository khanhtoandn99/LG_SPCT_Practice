#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int>c(n);
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        for(int j = 0 ; j < m; j++) {
            cin >> a[i][j];
        }
    }
    auto getbit = [&](int n, int k) {
        return (n >> k) & 1;  
    };
    auto call = [&](int x) {
        vector<int> s(m);
        int cost = 0;
        for(int i = 0 ; i < n; i++) {
            if (getbit(x, i)) {
                cost += c[i];
                for(int j = 0 ; j < m; j++) {
                    s[j] += a[i][j];
                }
            }
        }
        for(int i = 0; i < m; i++) {
            if (s[i] < k) return INF;
        }
        return cost;
    };
    int ret = INF;
    for(int i = 0 ; i < (1 << n); i++) {
        ret = min(ret, call(i));
    }
    cout << (ret == INF ? -1 : ret) ;
    return 0;
}