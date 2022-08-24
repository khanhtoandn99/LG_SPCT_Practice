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