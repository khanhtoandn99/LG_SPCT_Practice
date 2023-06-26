#include <iostream>
#include <algorithm>
using namespace std;

int A[100001];
int nA[10] = {0};
int N, M;

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        ++nA[A[i]];
    }
}

int main()
{
    input();
    // initializing
    int trace[M+1][N] = {0};
    int k[M];
    for (int i = 0; i < M; ++i) {
        k[i] = i + 1;
        for (int j = 0; j < N; ++j)
            trace[i+1][j] = -1;
    }

    // tracing...
    int minmove = 999999999;
    do {
        int pos = 0;
        int summove = 0;
        for (int i = 0; i < M; ++i) {
            if (trace[k[i]][pos] != -1) {
                summove += trace[k[i]][pos];
                pos += nA[k[i]];
                continue;
            }
            int move = 0;
            for (int j = 0; j < nA[k[i]]; ++j) {
                if (k[i] != A[pos]) ++move;
                ++pos;
            }
            summove += move;
            if (trace[k[i]][pos - nA[k[i]]] == -1) {
                trace[k[i]][pos - nA[k[i]]] = move;
                // cout << "trace[k[i]][pos - nA[k[i]]] = " << trace[k[i]][pos - nA[k[i]]] << " ";
            }
        }
        // cout << endl;
        minmove = min(summove, minmove);
    } while (next_permutation(k, k+M));

    cout << minmove << endl;
}