#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000

int N;//Map Size
char map[110][110];//Map information

bool marked[110][110] = {{false},{false}}; // Marked infomation
int  roadmap[110][110] = {{INF},{INF}};

typedef struct
{
    int row;
    int col;
} POINT_T;

void Input_Data()
{
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> map[i];
    }
}


void dijkstra(int sr, int sc)
{
    roadmap[0][0] = 0;
    int mapchecked = 3;
    int ur = sr, uc = sc;

    while (mapchecked > 0)
    {
        int uMin = INF, up, right, down, left; // check value of its around roads and find min
        int nr, nc; // next row,col

        up = (ur > 0 && marked[ur-1][uc] == false) ? (int)(map[ur-1][uc] - '0') : INF;
        if (min(up, uMin) == up) {nr = ur-1; nc = uc; uMin = up;}

        right = (uc < N-1 && marked[ur][uc+1] == false) ? (int)(map[ur][uc+1] - '0') : INF;
        if (min(right, uMin) == right) {nr = ur; nc = uc+1; uMin = right;}

        down = (ur < N-1 && marked[ur+1][uc] == false) ? (int)(map[ur+1][uc] - '0') : INF;
        if (min(down, uMin) == down) {nr = ur+1; nc = uc; uMin = down;}

        left = (uc > 0 && marked[ur][uc-1] == false) ? (int)(map[ur][uc-1] - '0') : INF;
        if (min(left, uMin) == left) {nr = ur; nc = uc-1; uMin = left;}

        marked[ur][uc] = true;
        cout << map[nr][nc] << endl;
        ur = nr; uc = nc;

        mapchecked -= 1;
    }
}

int main()
{
    int ans = -1;
    Input_Data();		//	Input function

    //  Write the code
    dijkstra(0, 0);

    // cout << ans << endl;	//	Output answer
    return 0;
}