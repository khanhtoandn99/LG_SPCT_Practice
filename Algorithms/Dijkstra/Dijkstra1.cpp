#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int N=0, M=0;
vector<int> node[101];
int len[101][101] = {0,};

int result[101][101] = {0,};


void getinput()
{
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int x, y, l; cin >> x >> y >> l;
        node[x].push_back(y);
        len[x][y] = l;
        len[y][x] = l;
    }
}

int Dijkstra(const int& start)
{
    bool marked[101] = {false,};
    unsigned int d[101] = {INT_MAX,};
    memset(&d, INT_MAX, sizeof(int)*101);

    marked[start] = true;
    d[start] = 0;

    queue<int> Q; Q.push(start);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        marked[u] = true;
        for (int i = 0; i < node[u].size(); ++i) {
            int v = node[u][i];
            if (marked[v] == false) {
                d[v] = min(d[v], (d[u] + len[u][v]));
            }
        }

        int minmin = INT_MAX, nextU = -1;
        for (int i = 1; i <= N; ++i) {
            if (marked[i] == false && d[i] < minmin) {
                minmin = d[i];
                nextU = i;
            }
        }
        if (nextU != -1) Q.push(nextU);
    }
    // print result
    for (int i = 1; i <= N; ++i) {
        cout << d[i] << " ";
        result[start][i] = d[i]; // record result
    }
    cout << endl;
    return 0;
}

int main()
{
    getinput();
    Dijkstra(1);
    return 0;
}