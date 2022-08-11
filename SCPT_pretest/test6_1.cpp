#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
char paper[11][11];

void input()
{
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> paper[i];
    }
}

struct COLOR_T
{
    int srow = 11;
    int scol = 11;
    int erow = -1;
    int ecol = -1;

    int stat = -1;
};

int main() {
    input();

    // Write code here:
    COLOR_T color[10] ;
    for (int ir = 0; ir < N; ++ir) {
        for (int ic = 0; ic < N; ++ic) {
            int colorIdx = (int)(paper[ir][ic] - '0');
            if (colorIdx == 0) continue;
            color[colorIdx].srow = min(color[colorIdx].srow, ir);
            color[colorIdx].scol = min(color[colorIdx].scol, ic);
            color[colorIdx].erow = max(color[colorIdx].erow, ir);
            color[colorIdx].ecol = max(color[colorIdx].ecol, ic);
            color[colorIdx].stat = 0;
        }
    }

    for (int ir = 0; ir < N; ++ir) {
        for (int ic = 0; ic < N; ++ic) {
            int colorIdx = (int)(paper[ir][ic] - '0');
            if (colorIdx == 0 || color[colorIdx].stat == -1) continue;

            for (int i = 1; i < N; ++i) {
                if (paper[ir][ic] == (char)(i + '0') || color[i].srow == 11) continue;
                if (color[i].srow <= ir && ir <= color[i].erow &&
                    color[i].scol <= ic && ic <= color[i].ecol) {
                        color[colorIdx].stat = 1;
                        break;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < 10; ++i) {
        if (color[i].stat == 0) ans++;
    }

    cout << ans << endl;
}