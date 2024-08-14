#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int A[100][100] = {0,};
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            A[i][j] = 0;

    int dr[4] = {1,0,-1,0};
    int dc[4] = {0,1,0,-1};
    int r = 0, c = 0;

    if (K == 2) {
        dr[0]=0;dr[1]=-1;dr[2]=0;dr[3]=1;
        dc[0]=1;dc[1]=0;dc[2]=-1;dc[3]=0;
        r = N-1, c = 0;
    }
    else if (K == 3) {
        dr[0]=-1;dr[1]=0;dr[2]=1;dr[3]=0;
        dc[0]=0;dc[1]=-1;dc[2]=0;dc[3]=1;
        r = N-1, c = N-1;
    }
    else if (K == 4) {
        dr[0]=0;dr[1]=1;dr[2]=0;dr[3]=-1;
        dc[0]=-1;dc[1]=0;dc[2]=1;dc[3]=0;
        r = 0, c = N-1;
    }
    int dir = 0;
    for (int n = N*N; n >= 1; --n) {
        A[r][c] = n;
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if (N <= nr || nr < 0 || N <= nc || nc < 0 || A[nr][nc]) {
            dir = (dir + 1)%4;
            r = r + dr[dir];
            c = c + dc[dir];
            continue;
        }
        r = nr;
        c = nc;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i][j] < 10) cout << " ";
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}