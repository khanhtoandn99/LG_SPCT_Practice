#include <iostream>
#include <queue>
#include <limits>
#include <tuple>

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

typedef tuple<unsigned long long, int, int> D2V_T; // distance, row, col
#define dt(fmt)  get<0>(fmt) // distance to [row][col]
#define row(fmt) get<1>(fmt) // row
#define col(fmt) get<2>(fmt) // col

int N, M;
unsigned long A[101][101] = {{0,},{0,}};
unsigned long d[101][101] = {{INT_MAX,},{INT_MAX,}};
bool marked[101][101] = {{false,}, {false,}};
// priority_queue<pair<udistance_t, POINT_T>, vector<pair<udistance_t, POINT_T>>, greater<pair<udistance_t, POINT_T>>> pQ_d; // in decesding order

void Dijkstra()
{
    d[0][0] = A[0][0];
    D2V_T dv = {d[0][0], 0, 0};
    LOGLN("----dv = {%lu, [%d][%d]", dt(dv), row(dv), col(dv));

    priority_queue<D2V_T, vector<D2V_T>, greater<D2V_T>> pQ;
    pQ.push(dv);
    while (!pQ.empty())
    {
        D2V_T du = pQ.top(); pQ.pop();
        marked[row(du)][col(du)] = true;
        for (int i = 0; i < ADJ_DIR; ++i) {
            D2V_T dw = {0, row(du) + ROW[i], col(du) + COL[i]};
            if (N-1 < row(dw) || row(dw) < 0) continue;
            if (M-1 < col(dw) || col(dw) < 0) continue;
            dt(dw) = d[row(dw)][col(dw)];
            LOGLN("d = %lu", d[row(dw)][col(dw)]);
            if (marked[row(dw)][col(dw)] == false) {
                d[row(dw)][col(dw)] = min(d[row(dw)][col(dw)], d[row(du)][col(du)] + A[row(dw)][col(dw)]);
                dt(dw) = d[row(dw)][col(dw)];
                LOGLN("d[%d][%d] = %lu", row(dw), col(dw), dt(dw));
                pQ.push(dw);
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
            d[i][j] = INT_MAX;
            marked[i][j] = false;
        }
    }

    Dijkstra();
    cout << d[N-1][M-1] << endl;
}