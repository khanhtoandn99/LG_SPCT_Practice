#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stack>
#include <vector>

using namespace std;

#define MAX_DIR 4 // up-right-down-left
const int r[MAX_DIR] = {-1, 0, 1, 0};
const int c[MAX_DIR] = {0, 1, 0, -1};

int N=0, M=0; // N: n.o.Row;  M: n.o.Col
vector<int> node[101];
bool visited[101] = {0, };

void getinput()
{
    cin >> N;
    for (int j = 0; j < N; ++j) {
        int x, y; cin >> x >> y;
        // cout << x << " " << y << endl;
        node[x].push_back(y);
        visited[node[x][y]] = false;
    }
}

vector<int> DFS(const int& sV)
{
    vector<int> ret;

    visited[sV] = true;
    stack<int> S;
    S.push(sV);
    // ret.push_back(sV);

    while (!S.empty())
    {
        int V = S.top();
        S.pop();
        // cout << V;
        ret.push_back(V);
        for (int nV = 0; nV < node[V].size(); ++nV) {
            if (visited[node[V][nV]] == false) {
                S.push(node[V][nV]);
                visited[node[V][nV]] = true;
                // ret.push_back(node[V][nV]);
            }
        }
    }
    return ret;
}

int main()
{
    getinput();
    vector<int> ret = DFS(1);
    // cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); ++i) {
        int x = ret[i];
        cout << x;
    }
    cout << endl << endl;
    return 0;
}