// #include <bits/stdc++.h>
// #include <limits.h>
#include <iostream>
#include <queue>
#include <limits>

using namespace std;

typedef struct
{
    int row;
    int col;
} POINT_T;

#define MAX_DIR 4
const int ROW[MAX_DIR] = {-1, 0, 1, 0};
const int COL[MAX_DIR] = {0, 1, 0, -1};

int N, M;
char g[101][101] = {'\0',};
POINT_T S, D;
int d[101][101] = {0,};


int BFS(POINT_T S, char map[101][101])
{
    queue<POINT_T> Q;
    Q.push(S);
    int minD = INT_MAX;

    while (!Q.empty())
    {
        POINT_T u = Q.front(); Q.pop();
        for (int i = 0; i < MAX_DIR; ++i) {
            POINT_T w = {u.row + ROW[i], u.col + COL[i]};
            if (N <= w.row || w.row < 0) continue;
            if (M <= w.col || w.col < 0) continue;
            if (map[w.row][w.col] == '-') {
                Q.push(w);
                map[w.row][w.col] = 'v';
                d[w.row][w.col] = d[u.row][u.col] + 1;
            } else if (map[w.row][w.col] == 'D') {
                d[w.row][w.col] = d[u.row][u.col] + 1;
                minD = min(minD, d[w.row][w.col]);
            }
        }
    }
    return minD == INT_MAX ? -1 : minD;
}


int main()
{
    cin >> N >> M;

    char tmp;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> tmp;
            g[i][j] = tmp;
            if (tmp == 'S') {S.row = i; S.col = j;}
            else if (tmp == 'D') {D.row = i; D.col = j;}
        }
    }

    cout << BFS(S, g) << "\n";
}