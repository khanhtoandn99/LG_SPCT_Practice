// Link: https://leetcode.com/problems/flood-fill/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int color) {
        // Solution: using Breadth First Search algorithm
        vector<vector<int> > visited = image;
        int color_old = image[sr][sc];
        queue<int> Q;
        Q.push(sr); Q.push(sc);

        while (Q.size() > 0)
        {
            int pr = Q.front(); Q.pop();
            int pc = Q.front(); Q.pop();
            image[pr][pc] = color;
            if (pc - 1 >= 0) {
                if (visited[pr][pc-1] == color_old) {
                    visited[pr][pc-1] = -1;
                    image[pr][pc-1] = color;
                    Q.push(pr); Q.push(pc-1);
                }
            }
            if (pc + 1 <= image[0].size() - 1) {
                if (visited[pr][pc+1] == color_old) {
                    visited[pr][pc+1] = -1;
                    image[pr][pc+1] = color;
                    Q.push(pr); Q.push(pc+1);
                }
            }
            if (pr - 1 >= 0) {
                if (visited[pr-1][pc] == color_old) {
                    visited[pr-1][pc] = 1;
                    image[pr-1][pc] = color;
                    Q.push(pr-1); Q.push(pc);
                }
            }
            if (pr + 1 <= image.size() - 1) {
                if (visited[pr+1][pc] == color_old) {
                    visited[pr+1][pc] = -1;
                    image[pr+1][pc] = color;
                    Q.push(pr+1); Q.push(pc); 
                }
            }
        }
        return image;
    }
};

int main()
{
    vector<vector<int> > image(3, vector<int> (4,0));
    image[0][0] = 1; image[0][1] = 1; image[0][2] = 1; image[0][3] = 1;
    image[1][0] = 1; image[1][1] = 1; image[1][2] = 0; image[1][3] = 0;
    image[2][0] = 1; image[2][1] = 0; image[2][2] = 1; image[2][3] = 1;

    Solution sol;
    sol.floodFill(image, 1, 1, 5);

    for (int i = 0; i < image.size(); ++i) {
        for (int j = 0; j < image[0].size(); ++j)
            cout << image[i][j] << " ";
        cout << endl;
    }
}