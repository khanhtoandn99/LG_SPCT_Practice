#include <bits/stdc++.h>
using namespace std;

int N, M;
map<int, string> mpNameById;
map<string, int> mpIdByName;
map<string, int> mpScoreByName;

void output(int ranking)
{
    for (int i = 1; i <= N; ++i) {
        if (mpScoreByName[mpNameById[i]] >= ranking) {
            cout << mpNameById[i] << " " << mpScoreByName[mpNameById[i]] << endl;
            mpScoreByName[mpNameById[i]] = -1;
            break;
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> mpNameById[i];
        mpIdByName[mpNameById[i]] = i;
        mpScoreByName[mpNameById[i]] = 0;
    }

    cin >> M;
    for (int i = 0; i < M; ++i) {
        string canName = "";
        int score;
        cin >> canName;
        cin >> score;
        if (mpIdByName[canName] == 0) continue;
        mpScoreByName[canName] += score;
    }

    vector<int> rank(N);
    for (int j = 0; j < N; ++j) {
        rank[j] = mpScoreByName[mpNameById[j+1]];
    }
    sort (rank.begin(), rank.end()); // Sort by accending
    output(rank[N-1]);
    output(rank[N-2]);
    output(rank[N-3]);
	return 0;
}