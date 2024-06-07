#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1000000000;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i = 0 ; i < n; i++) {
        cin >> c[i];
        for(int j = 0 ; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = INF;
    vector<int> regis(n, false);
    function<void(int)> backtrack = [&](int courseIdx) {
        if (courseIdx == n) {
            int cost = 0;
            vector<int> understanding_level(m);
            for(int i = 0 ; i < n; i++) {
                if (regis[i]) {
                    cost += c[i];
                    for(int j = 0 ; j < m; j++) {
                        understanding_level[j] += a[i][j];
                    }  
                }                                
            }
            for(int i = 0 ; i < m; i++) {
                if (understanding_level[i] < x) return;
            }
            if (cost < ans) {
                ans = cost;
            }
            return;
        }
        for(int i = 0; i < 2; i++) {
            regis[courseIdx] = i;
            backtrack(courseIdx + 1);
        }
    };
    backtrack(0);
    cout << (ans == INF ? -1 : ans);
    return 0;
}