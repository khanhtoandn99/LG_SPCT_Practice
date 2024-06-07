#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define INF 1000000000

int N;//Map Size
char map[110][110];//Map information

bool marked[110][110];// Marked infomation
int  roadmap[110][110];
const int r[4] = {-1, 0, 1, 0}; // UP - RIGHT - DOWN - LEFT
const int c[4] = {0, 1, 0, -1}; // UP - RIGHT - DOWN - LEFT


void Input_Data()
{
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> map[i];
    }
}


int dijkstra(int srow, int scol)
{
    int numMarked = N*N;
    int row = srow, col = scol;
    // int nextRow, nextCol;
    while (numMarked > 0)
    {
        int minPoint = INT_MAX;
        int nextRow = -1, nextCol = -1;
        marked[row][col] = true;
        for (int i = 0; i < 4; ++i)
        {
            int nbrRow = row + r[i]; // Neighbor row
            int nbrCol = col + c[i]; // Neighbor col
            if (nbrRow < 0 || nbrRow > N-1) continue;
            if (nbrCol < 0 || nbrCol > N-1) continue;
            // Update roadmap:
            roadmap[nbrRow][nbrCol] = min(roadmap[nbrRow][nbrCol], roadmap[row][col] + (int)(map[nbrRow][nbrCol] - '0'));

            for (int ri = 0; ri < N; ++ri) {
                for (int ci = 0; ci < N; ++ci) {
                    if (roadmap[ri][ci] < minPoint && marked[ri][ci] == false) {
                        minPoint = roadmap[ri][ci];
                        nextRow = ri;
                        nextCol = ci;
                    }
                }
            }
            if (nextRow == -1 || nextCol == -1) return roadmap[N-1][N-1]; // if do not find any point ==> return;
        }
        row = nextRow;
        col = nextCol;
        --numMarked;
    }
    return roadmap[N-1][N-1];
}

int main()
{
    int ans = -1;
    Input_Data();		//	Input function

    //  Write the code
    // Init data:
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            roadmap[i][j] = INT_MAX;
            marked[i][j] = false;
        }
    }
    roadmap[0][0] = 0;

    ans = dijkstra(0, 0);

    cout << ans << endl;	//	Output answer
    return 0;
}