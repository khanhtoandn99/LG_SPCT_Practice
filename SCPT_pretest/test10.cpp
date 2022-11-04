#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int r[4] = {-1,0,1,0};
const int c[4] = {0,1,0,-1};
int N, M; // N: n.o Row, M: n.o Col
int orgmap[51][51];
bool visited[51][51] = {0,0};

typedef struct
{
    int row;
    int col;
} POINT_T;

vector<POINT_T> BFS(POINT_T s)
{
    vector<POINT_T> vPoint;
    queue<POINT_T> Q;
    Q.push(s);
    visited[s.row][s.col] = true;
    vPoint.push_back(s);
    while (Q.size() != 0)
    {
        POINT_T curPoint = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            POINT_T p = {curPoint.row + r[i], curPoint.col + c[i]};
            if (p.row < 0 || p.row > N-1) continue;
            if (p.col < 0 || p.col > M-1) continue;
            if (visited[p.row][p.col] == false && orgmap[p.row][p.col] == 1) {
                Q.push(p);
                visited[p.row][p.col] = true;
                vPoint.push_back(p);
            }
        }
    }
    return vPoint;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> orgmap[i][j];
        }
    }
    
    vector<POINT_T> L1;
    vector<POINT_T> L2;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (orgmap[i][j] == 1 && visited[i][j] == false) {
                if (L1.size() == 0) {
                    L1 = BFS({i,j});
                    i = 0; j = 0; // re-scan to find L2
                } else { // x = 2
                    L2 = BFS({i,j});
                }
            }
        }
    }

    int minPath = INT_MAX;
    for (unsigned int i = 0; i < L1.size(); ++i) {
        for (unsigned int j = 0; j < L2.size(); ++j) {
            minPath = min(minPath, abs(L2[j].row - L1[i].row) + abs(L2[j].col - L1[i].col) - 1);
        }
    }
    cout << minPath << endl;
}

/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int r[4] = {-1, 0, 1, 0};
const int c[4] = {0, 1, 0, -1};

typedef struct
{
    int row;
    int col;
} POINT_T;

int N, M;
int map[52][52];
vector<POINT_T> V1;
vector<POINT_T> V2;

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];
}

vector<POINT_T> BFS(POINT_T sp)
{
    vector<POINT_T> vRet;
    queue<POINT_T> Q;
    Q.push(sp);
    vRet.push_back(sp);
    while (Q.size() > 0)
    {
        POINT_T p = Q.front();
        Q.pop();
        map[p.row][p.col] = 2; // visited
        for (int i = 0; i < 4; ++i) {
            POINT_T nb = {p.row + r[i], p.col + c[i]};
            if (nb.row < 0 || nb.row > N - 1) continue;
            if (nb.col < 0 || nb.col > M - 1) continue;
            if (map[nb.row][nb.col] == 1) {
                Q.push(nb);
                map[nb.row][nb.col] = 2;
                vRet.push_back(nb);
            }
        }
    }
    return vRet;
}

int main()
{
	input();
    // Determine V1, V2
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] == 1) {
                POINT_T startPoint = {i,j};
                if (V1.size() == 0) V1 = BFS(startPoint);
                else V2 = BFS(startPoint);
                i = 0; j = 0;
            }
        }
    }
    int minDist = INT_MAX;
    for (int i = 0; i < (int)V1.size(); ++i) {
        for (int j = 0; j < (int)V2.size(); ++j) {
            int distance = abs(V2[j].col - V1[i].col);
            distance += abs(V2[j].row - V1[i].row) - 1;
            minDist = min(minDist, distance);
        }
    }
    cout << minDist << endl;
}
*/