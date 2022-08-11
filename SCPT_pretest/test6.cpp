#include <iostream>
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

enum DIRECTION
{
    TOP = 0,
    RIGHT = 3,
    BOTTOM = 6,
    LEFT = 9
};

char getColor(DIRECTION dir, int row, int col)
{
    switch (dir)
    {
    case TOP:
        if (row - 1 >= 0) return paper[row-1][col];
        return '-';
    case RIGHT:
        if (col + 1 < N) return paper[row][col+1];
        return '-';
    case BOTTOM:
        if (row + 1 < N) return paper[row+1][col];
        return '-';
    case LEFT:
        if (col - 1 >= 0) return paper[row][col-1];
        return '-';
    }
    return '-';
}

int main() {
    input();
    // // debug
    // for (int i = 0; i < N; ++i) {
    //     cout << paper[i] << endl;
    // }

    // Write code here:
    int bOver[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    for (int ir = 0; ir < N; ++ir) {
        for (int ic = 0; ic < N; ++ic) {
            if (paper[ir][ic] == '0' || bOver[paper[ir][ic] - '0'] == 1) continue;
            // Review 4 color around:
            if (bOver[paper[ir][ic] - '0'] == -1) bOver[paper[ir][ic] - '0'] = 0;
            bool bSameColor = false; // At least one same its color?
            bool bDiffAdjacent = false; // Two same color, but diff its color, and adjacent?

            char top = getColor(TOP, ir, ic); //cout << "top: " << top << endl;
            if (top == paper[ir][ic]) bSameColor = true;
            else {
                if (top != '-' && top != '0' && top == getColor(RIGHT,ir,ic)) bDiffAdjacent = true;
            }

            char right = getColor(RIGHT, ir, ic); //cout << "right: " << right << endl;
            if (right == paper[ir][ic]) bSameColor = true;
            else {
                if (right != '-' && right != '0' && right == getColor(BOTTOM,ir,ic)) bDiffAdjacent = true;
            }

            char bottom = getColor(BOTTOM, ir, ic); //cout << "bottom: " << bottom << endl;
            if (bottom == paper[ir][ic]) bSameColor = true;
            else {
                if (bottom != '-' && bottom != '0' && bottom == getColor(LEFT,ir,ic)) bDiffAdjacent = true;
            }

            char left = getColor(LEFT, ir, ic); //cout << "left: " << left << endl;
            if (left == paper[ir][ic]) bSameColor = true;
            else {
                if (left != '-' && left != '0' && left == getColor(TOP,ir,ic)) bDiffAdjacent = true;
            }

            if (bSameColor == true && bDiffAdjacent == true) bOver[paper[ir][ic] - '0'] = 1;
        }
    }
    int noNotOver = 0;
    for (int i = 1; i < N; ++i) {
        if (bOver[i] == 0) noNotOver++;
    }
    cout << noNotOver << endl;
}