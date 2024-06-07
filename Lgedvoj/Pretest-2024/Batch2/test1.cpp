#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <algorithm>
using namespace std;

int N;
long long M;
uint8_t P[101];
vector<uint8_t> vAB[101];
vector<bool> visited;

int BFS(int v) {
    int retMin = INT_MAX;
    queue<int> Q;
    Q.push(v);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        visited[u] = true;
        retMin = min(retMin, (int)P[u]);
        for (int i = 0; i < (int)vAB[u].size(); ++i) {
            int w = vAB[u][i];
            if (visited[w] == false) {
                visited[w] = true;
                retMin = min(retMin, (int)P[w]);
                Q.push(w);
            }
        }
    }
    cout << "min=" << retMin << endl;
    return retMin;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    visited.resize(N+1, false);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    uint8_t a,b;
    for (long long i = 0; i < M; ++i) {
        cin >> a >> b;
        vAB[a-1].push_back(b-1);
        vAB[b-1].push_back(a-1);
    }
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        if (visited[i] == false) {
            ret += BFS(i);
        }
    }
    cout << ret << "\n";
    return 0;
}
