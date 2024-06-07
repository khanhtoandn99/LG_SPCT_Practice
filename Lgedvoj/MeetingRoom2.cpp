#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define dur  first
#define cost second
#define endt first
#define stat second

vector<pair<pair<int,int>,int> > vM;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    vM.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> vM[i].dur.stat >> vM[i].dur.endt >> vM[i].cost;
    }
    sort(vM.begin(), vM.end());

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int maxCost = 0;
        for (int j = 0; j < i; ++j) {
            if (vM[j].dur.endt <= vM[i].dur.stat) {
                maxCost = max(vM[j].cost, maxCost);
            }
        }
        vM[i].cost += maxCost;
        ans = max(ans, vM[i].cost);
    }
    cout <<  ans << "\n";
    return 0;
}