#include <bits/stdc++.h>

using namespace std;

// #define DEBUG 1

#ifdef DEBUG
#define LOG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define LOG(fmt, ...) {}
#endif

typedef struct
{
    int row;
    int col;
} CELL_T;

#define MAX_DIR 4
const int ROW[MAX_DIR] = {-1, 0, 1, 0};
const int COL[MAX_DIR] = {0, 1, 0, -1};

int N, M;
int A[101][101] = {0,};
bool engulfedA[101][101] = {false,};
vector<CELL_T> vVolcano;

int BFS(CELL_T v, int A[101][101], bool engulfedA[101][101]) // need use engulfedA because in case island high = 0, 0*(-1) = 0 could not detect visited or not
{
    int ret = 0;
    queue<CELL_T> Q;
    Q.push(v);
    engulfedA[v.row][v.col] = true;
    ++ret;
    while (!Q.empty())
    {
        CELL_T u = Q.front(); Q.pop();
        for (int i = 0; i < MAX_DIR; ++i) {
            CELL_T w = {u.row + ROW[i], u.col + COL[i]};
            if (N-1 < w.row || w.row < 0) continue;
            if (M-1 < w.col || w.col < 0) continue;
            if (engulfedA[w.row][w.col] == false && A[w.row][w.col] >= 0 && abs(A[u.row][u.col]) >= A[w.row][w.col]) {
                engulfedA[w.row][w.col] = true;
                LOG("A[%d][%d] = %d\n", w.row, w.col, A[w.row][w.col]);
                Q.push(w);
                ++ret;
            }
        }
    }
    return ret;
}

int main()
{
    cin >> N >> M;
    LOG("%d %d\n", N, M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
            LOG("%d ", A[i][j]);
            if (A[i][j] < 0) vVolcano.push_back({i,j});
        }
        LOG("\n");
    }
    LOG("\n");

    int res = 0;
    for (int i = 0; i < (int)vVolcano.size(); ++i) {
        if (engulfedA[vVolcano[i].row][vVolcano[i].col] == true) continue;
        res += BFS(vVolcano[i], A, engulfedA);
    }

    cout << res << "\n";
    return 0;
}