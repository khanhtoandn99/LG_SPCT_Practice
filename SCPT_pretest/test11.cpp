#include <iostream>
using namespace std;

int N; // Number of Factory
int M; // Number of Road
int D[101][101];

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            D[i][j] = -1;

    int A, B, Dist;
    for (int i = 0; i < M; ++i) {
        cin >> A >> B >> Dist;
        D[A][B] = Dist;
    }
}

int main()
{
    input();
}