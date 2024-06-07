#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

// #define DEBUG 1
#ifdef DEBUG
#define LOG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define LOGLN(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#else
#define LOG(fmt, ...) {}
#define LOGLN(fmt, ...) {}
#endif

#define ADJ_DIR 4
const int ROW[ADJ_DIR] = {-1, 0, 1, 0};
const int COL[ADJ_DIR] = {0, 1, 0, -1};

typedef struct
{
    int row;
    int col;
} POINT_T;


int N, M;
long long A[101][101] = {{0,},{0,}};
unsigned long long d[101][101] = {{ULLONG_MAX,},{ULLONG_MAX,}};
bool marked[101][101] = {{false,}, {false,}};

void Dijkstra()
{
    d[0][0] = A[0][0];
    queue<POINT_T> Q;
    Q.push({0,0});
    while (!Q.empty())
    {
        POINT_T u = Q.front(); Q.pop();
        marked[u.row][u.col] = true;
        for (int i = 0; i < ADJ_DIR; ++i) {
            POINT_T w = {u.row + ROW[i], u.col + COL[i]};
            if (N-1 < w.row || w.row < 0) continue;
            if (M-1 < w.col || w.col < 0) continue;
            LOGLN("d = %llu", d[w.row][w.col]);
            if (marked[w.row][w.col] == false) {
                d[w.row][w.col] = min(d[w.row][w.col], d[u.row][u.col] + A[w.row][w.col]);
                LOGLN("d[%d][%d] = %llu", w.row, w.col, d[w.row][w.col]);
            }
        }
        POINT_T *next_u = nullptr;
        unsigned long long min_w = ULLONG_MAX;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (marked[i][j] == false && d[i][j] < min_w) {
                    min_w = d[i][j];
                    if (next_u == nullptr) next_u = new POINT_T();
                    next_u->row = i; next_u->col = j;
                }
            }
        }
        if (next_u != nullptr) Q.push(*next_u);
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
            d[i][j] = ULLONG_MAX;
            marked[i][j] = false;
        }
    }

    Dijkstra();
    cout << d[N-1][M-1] << endl;
}