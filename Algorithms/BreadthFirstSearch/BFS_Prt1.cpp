#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct
{
    int row;
    int col;
} NODE_T;

#define MAX_DIR 4 // up-right-down-left
const int r[MAX_DIR] = {-1, 0, 1, 0};
const int c[MAX_DIR] = {0, 1, 0, -1};

int N=0, M=0; // N: n.o.Row;  M: n.o.Col
int orgmap[101][101] = {0, };
bool visited[101][101] = {0, };


void getinput();
void printout();
vector<NODE_T> BFS(const NODE_T& tNode);

void getinput()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> orgmap[i][j];
            visited[i][j] = false;
        }
    }
}

void printout(vector<NODE_T> nodes)
{
    for (int i = 0; i < nodes.size(); ++i) {
        cout << "[" << nodes[i].row << "," << nodes[i].col << "] ";
    }
    cout << endl;
}

vector<NODE_T> BFS(const NODE_T& tNode)
{
    vector<NODE_T> vNode;

    queue<NODE_T> Q;
    Q.push(tNode);
    visited[tNode.row][tNode.col] = true;
    vNode.push_back(tNode);

    while (Q.size() != 0)
    {
        NODE_T currNode = Q.front();
        Q.pop();

        for (int i = 0; i < MAX_DIR; ++i) {
            NODE_T tmpNode = {currNode.row + r[i], currNode.col + c[i]};
            if (tmpNode.row < 0 || tmpNode.row >= N) continue;
            if (tmpNode.col < 0 || tmpNode.col >= M) continue;
            if (orgmap[tmpNode.row][tmpNode.col] == 1 && visited[tmpNode.row][tmpNode.col] == false) {
                Q.push(tmpNode);
                visited[tmpNode.row][tmpNode.col] = true;
                vNode.push_back(tmpNode);
            }
        }
    }
    return vNode;
}

int main()
{
    getinput();

    vector<NODE_T> res;
    for (int ri = 0; ri < N; ++ri) {
        for (int ci = 0; ci < M; ++ci) {
            if (orgmap[ri][ci] == true && visited[ri][ci] == false)
            {
                printf("Check [%d,%d]\n", ri, ci);
                NODE_T node = {ri, ci};
                res = BFS(node);
                printout(res);
            }
        }
    }
}