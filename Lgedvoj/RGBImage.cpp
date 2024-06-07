// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef struct
{
    int row;
    int col;
} PIXEL_T;

const int ROW[4] = {-1, 0, 1, 0};
const int COL[4] = {0, 1, 0, -1};

int N, M;
char image[101][101] = {' ',};
vector<PIXEL_T> vPixelR, vPixelG, vPixelB;
int numPixelR = 0, numPixelG = 0, numPixelB = 0;
map<char, int> numBlock;
int numBlockMax = 0;


void BFS(char color, PIXEL_T v, char image[101][101])
{
    queue<PIXEL_T> Q;
    Q.push(v);
    image[v.row][v.col] = 'v';
    while (!Q.empty())
    {
        PIXEL_T u = Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
            PIXEL_T w = {u.row + ROW[i], u.col + COL[i]};
            if (N-1 < w.row || w.row < 0) continue;
            if (M-1 < w.col || w.col < 0) continue;
            if (image[w.row][w.col] == color) {
                Q.push(w);
                image[w.row][w.col] = 'v'; // visited
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Input
    cin >> N >> M;

    char tmp;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> tmp;
            image[i][j] = tmp;
            if (tmp == 'R') vPixelR.push_back({i,j});
            else if (tmp == 'G') vPixelG.push_back({i,j});
            else vPixelB.push_back({i,j});
        }
    }

    // Solving v2 --> reduce O(n^2) for loop
    for (int i = 0; i < (int)vPixelR.size(); ++i) {
        if (image[vPixelR[i].row][vPixelR[i].col] == 'R') {
            BFS('R', vPixelR[i], image);
            ++numBlock['R'];
        }
    }
    numBlockMax = max(numBlockMax, numBlock['R']);
    for (int i = 0; i < (int)vPixelG.size(); ++i) {
        if (image[vPixelG[i].row][vPixelG[i].col] == 'G') {
            BFS('G', vPixelG[i], image);
            ++numBlock['G'];
        }
    }
    numBlockMax = max(numBlockMax, numBlock['G']);
    for (int i = 0; i < (int)vPixelB.size(); ++i) {
        if (image[vPixelB[i].row][vPixelB[i].col] == 'B') {
            BFS('B', vPixelB[i], image);
            ++numBlock['B'];
        }
    }
    numBlockMax = max(numBlockMax, numBlock['B']);

    map<char, int> total;
    int largest = 0;

    if (numBlock['R'] == numBlockMax) {
        total['R'] = (int)vPixelR.size() * numBlockMax;
        largest = max(largest, total['R']);
    }
    if (numBlock['G'] == numBlockMax) {
        total['G'] = (int)vPixelG.size() * numBlockMax;
        largest = max(largest, total['G']);
    }
    if (numBlock['B'] == numBlockMax) {
        total['B'] = (int)vPixelB.size() * numBlockMax;
        largest = max(largest, total['B']);
    }

    // Output
    if (total['R'] == largest) cout << 'R' << "\n";
    else if (total['G'] == largest) cout << 'G' << "\n";
    else cout << 'B' << "\n";

}