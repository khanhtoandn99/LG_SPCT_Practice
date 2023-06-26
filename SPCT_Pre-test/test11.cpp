#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int N; // Number of factory
int M; // Number of road
int D[102][102];

void input ()
{
    cin >> N >> M;
    int A, B, Distance;
    for (int i = 0; i < M; ++i) {
        cin >> A >> B >> Distance;
        D[A][B] = Distance;
        D[B][A] = Distance;
    }
}

int dijkstra(int sFac)
{
    int Farthest = 0;
    vector<int> map(N+1,INT_MAX);
    bool marked[N+1] = {false};
    map[sFac] = 0;
    int curFac = sFac;
    while (1)
    {
        marked[curFac] = true;
        for (int i = 1; i <= N; ++i) {
            if (D[curFac][i] != 0 && D[curFac][i] != -1) {
                map[i] = min(map[i], map[curFac] + D[curFac][i]);
            }
        }
        int FacMin = INT_MAX;
        int nextFac = -1;
        for (int i = 1; i <= N; ++i) {
            if (min(FacMin, map[i]) == map[i] && marked[i] == false) {
                nextFac = i;
                FacMin = map[i];
            }
        }
        if (nextFac == -1) break;
        curFac = nextFac;
    }
    for (int i = 1; i <= N; ++i) {
        Farthest = max(Farthest, map[i]);
    }
    return Farthest;
}

int main()
{
    for (int i = 0; i < 102; ++i)
        for (int j = 0; j < 102; ++j)
            if (i == j) D[i][j] = 0;
            else D[i][j] = -1;

    input();
    int Farthest[N+1] = {0};
    int minFarthest = INT_MAX;
    for (int i = 1; i <= N; ++i) {
        Farthest[i] = dijkstra(i);
        minFarthest = min(minFarthest, Farthest[i]);
    }
    cout << minFarthest << endl;
}
