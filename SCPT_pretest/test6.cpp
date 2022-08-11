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

struct COLOR_INFO_T
{
    int srow = 11; // start row
    int scol = 11; // start col
    int erow = -1; // end row
    int ecol = -1; // end col

    bool in_used = false; // there are 9 colors, set to true if the color is used in paper
    bool paintOver = false; // set to true if determined that this color is painted over other color
};

int main()
{
    input();

    // Write code here:
    // scan and save all color information
    COLOR_INFO_T info[10] ;
    for (int ir = 0; ir < N; ++ir) {
        for (int ic = 0; ic < N; ++ic) {
            int iColor = (int)(paper[ir][ic] - '0');
            if (iColor == 0) continue;

            info[iColor].in_used = true;
            info[iColor].srow = min(info[iColor].srow, ir);
            info[iColor].scol = min(info[iColor].scol, ic);
            info[iColor].erow = max(info[iColor].erow, ir);
            info[iColor].ecol = max(info[iColor].ecol, ic);
        }
    }

    // Now scan and determined if the color in used is painted over other color for each position.
    // The color that set as paintOver == true or in_used == false will be skip.
    for (int ir = 0; ir < N; ++ir) {
        for (int ic = 0; ic < N; ++ic) {
            int iColorInCheck = (int)(paper[ir][ic] - '0');
            if (iColorInCheck == 0) continue;
            for (int iColor = 1; iColor < 10; ++iColor) {
                if (iColorInCheck == iColor || info[iColorInCheck].paintOver == true) continue;
                if (info[iColor].srow <= ir && ir <= info[iColor].erow &&
                    info[iColor].scol <= ic && ic <= info[iColor].ecol) {
                        info[iColorInCheck].paintOver = true;
                        break;
                }
            }
        }
    }
    // Counting
    int ans = 0;
    for (int iColor = 0; iColor < 10; ++iColor) {
        if (info[iColor].in_used == true && info[iColor].paintOver == false)
            ++ans;
    }

    // Output here:
    cout << ans << endl;
}