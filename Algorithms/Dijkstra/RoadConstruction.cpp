#include <bits/stdc++.h>
#include "limits.h"
using namespace std;

#ifdef DEBUG
#define log(fmt) printf(fmt, ##__VA_ARGS__)
#else
#define log(fmt) {}
#endif

typedef pair<int,int> CELL_T;
#define row first
#define col second

#define DMAX 4
const int DR[4] = {-1,0,1,0};
const int DC[4] = {0,1,0,-1};

int N;//Map Size
char Map[110][110];//Map information
int vD[110][110];
bool visited[110][110];

void Input_Data() {
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> Map[i];
    }
}

void Dijkstra(CELL_T s) {
    queue<CELL_T> Q;
    Q.push(s);
    vD[s.row][s.col] = 0;
    while (!Q.empty()) {
        CELL_T u = Q.front(); Q.pop();
        visited[u.row][u.col] = true;

        for (int i = 0; i < DMAX; ++i) {
            CELL_T w = {u.row + DR[i], u.col + DC[i]};
            if (N-1 < w.row || w.row < 0) continue;
            if (N-1 < w.col || w.col < 0) continue;
            vD[w.row][w.col] = min(vD[w.row][w.col], vD[u.row][u.col] + ((int)Map[w.row][w.col]-'0'));
        }

        int minW = INT_MAX;
        CELL_T nw = {-1,-1};
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (vD[i][j] < minW && visited[i][j] == false) {
                    minW = vD[i][j];
                    nw.row = i; nw.col = j;
                }
            }
        }
        if (nw.row == -1 || nw.col == -1) return;
        Q.push(nw);
    }
}

int main() {
    int ans = -1;
    Input_Data(); // Input function

    // Write the code
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            vD[i][j] = INT_MAX;
            visited[i][j] = false;
        }
    }

    Dijkstra({0,0});
    ans = vD[N-1][N-1];

    cout << ans << endl; // Output answer

    return 0;
}
