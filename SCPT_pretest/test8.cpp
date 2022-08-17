#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000

int N;//Map Size
char map[110][110];//Map information

bool marked[110][110] = {{false},{false}}; // Marked infomation
int  roadmap[110][110] = {{INF},{INF}};

void Input_Data()
{
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> map[i];
    }
}


int dijkstra(int start_row, int start_col)
{
    int cur_row = start_row, cur_col = start_col;
    int up_row, up_col, right_row, right_col, down_row, down_col, left_row, left_col;
    int mapCheckedNum = N*N;

    while (mapCheckedNum > 0)
    {
        int min_val = INF, min_row, min_col;
        // cout << "[" << cur_row << "," << cur_col << "] = " << (int)(map[cur_row][cur_col] - '0') << endl;
        up_row    = cur_row - 1; up_col    = cur_col;
        right_row = cur_row;     right_col = cur_col + 1;
        down_row  = cur_row + 1; down_col  = cur_col;
        left_row  = cur_row;     left_col  = cur_col - 1;

        if (up_row >= 0) { // UP nearby
            roadmap[up_row][up_col] = min(roadmap[up_row][up_col], roadmap[cur_row][cur_col] + (int)(map[up_row][up_col] - '0'));
            if (marked[up_row][up_col] == false && min(roadmap[up_row][up_col], min_val) == roadmap[up_row][up_col]) {
                min_row = up_row;
                min_col = up_col;
                min_val = roadmap[up_row][up_col];
            }
        }

        if (right_col < N) { // UP nearby
            roadmap[right_row][right_col] = min(roadmap[right_row][right_col], roadmap[cur_row][cur_col] + (int)(map[right_row][right_col] - '0'));
            if (marked[right_row][right_col] == false && min(roadmap[right_row][right_col], min_val) == roadmap[right_row][right_col]) {
                min_row = right_row;
                min_col = right_col;
                min_val = roadmap[right_row][right_col];
            }
        }

        if (down_row < N) { // UP nearby
            roadmap[down_row][down_col] = min(roadmap[down_row][down_col], roadmap[cur_row][cur_col] + (int)(map[down_row][down_col] - '0'));
            if (marked[down_row][down_col] == false && min(roadmap[down_row][down_col], min_val) == roadmap[down_row][down_col]) {
                min_row = down_row;
                min_col = down_col;
                min_val = roadmap[down_row][down_col];
            }
        }

        if (left_col >= 0) { // UP nearby
            roadmap[left_row][left_col] = min(roadmap[left_row][left_col], roadmap[cur_row][cur_col] + (int)(map[left_row][left_col] - '0'));
            if (marked[left_row][left_col] == false && min(roadmap[left_row][left_col], min_val) == roadmap[left_row][left_col]) {
                min_row = left_row;
                min_col = left_col;
                min_val = roadmap[left_row][left_col];
            }
        }
        marked[cur_row][cur_col] = true;
        cur_row = min_row; cur_col = min_col;

        mapCheckedNum -= 1;
    }
    // Debug:
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << roadmap[i][j] << " ";
        }
    }
    return roadmap[N-1][N-1];
}

int main()
{
    int ans = -1;
    Input_Data();		//	Input function

    //  Write the code
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            roadmap[i][j] = INF;
        }
    }
    roadmap[0][0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            marked[i][j] = false;
        }
    }

    ans = dijkstra(0, 0);

    cout << ans << endl;	//	Output answer
    return 0;
}