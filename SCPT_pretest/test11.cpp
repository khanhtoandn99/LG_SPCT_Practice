#include <iostream>
#include <algorithm>
using namespace std;

int N; // Number of Factory
int M; // Number of Road
int D[101][101];

int roadmap[101][101];
bool marked[101][101];
int maxFrom[101] = {0};

void input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) {
                D[i][j] = 0;
                roadmap[i][j] = 0;
            }
            else {
                D[i][j] = -1;
                roadmap[i][j] = INT_MAX;
            }
            marked[i][j] = false;
        }
    }

    int A, B, Dist;
    for (int i = 0; i < M; ++i) {
        cin >> A >> B >> Dist;
        D[A][B] = Dist;
        D[B][A] = Dist;
    }
}

void dijkstra(int sfac)
{
    int curFac = sfac;
    while (1)
    {
        int iDmin = INT_MAX;
        int nextFac;
        for (int i = 1; i <= N; ++i) {
            if (D[curFac][i] == 0 || D[curFac][i] == -1) continue;
            roadmap[curFac][i] = min(roadmap[curFac][i], D[curFac][i]);
        }
        for (int j = 0; j <= N; ++j) {
            if (min(iDmin, roadmap[curFac][j]) == roadmap[curFac][j]) {
                iDmin = roadmap[curFac][j];
                nextFac = j;
            }
        }
        marked[]
        curFac = nextFac;
    }
}

int main()
{
    input();
    for (int i = 1; i <= N; ++i) {
        dijkstra(i);
    }
    int ans = INT_MAX;
    for (int i = 1; i <= N; ++i) {
        ans = min(ans, maxFrom[i]);
    }
    cout << ans << endl;
}




