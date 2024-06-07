#include "bits/stdc++.h"
// #include <iostream>
// #include <queue>
// #include <map>

using namespace std;

int getIsoscelesPairs(const int& n)
{
    int ret = 0;
    for (int i = 0; i < n; ++i) ret += n-i-1;
    return ret;
}

int main()
{
    int N;
    cin >> N;

    vector<unsigned int> vA;
    map<unsigned int, int> mpANum;

    unsigned int Ai;
    for (int i = 0; i < N; ++i)
    {
        cin >> Ai;
        if (mpANum[Ai] == 0) vA.push_back(Ai);
        ++mpANum[Ai];
    }

    // sort(vA.begin(), vA.end(), greater<unsigned int>());

    map<unsigned int, int> mpPairANum;
    for (int i = 0; i < vA.size(); ++i) {
        mpPairANum[vA[i]] = getIsoscelesPairs(mpANum[vA[i]]);
    }

    int ret = 0;
    for (int i = 0; i < (int)vA.size()-1; ++i) {
        for (int j = i+1; j < (int)vA.size(); ++j) {
            if (mpANum[vA[i]] == 1 && mpANum[vA[j]] == 1) continue;
            if (mpANum[vA[i]] > 1) ret += mpPairANum[vA[i]]*mpANum[vA[j]];
            if (mpANum[vA[j]] > 1 && (vA[j]*2 > vA[i])) ret += mpPairANum[vA[j]]*mpANum[vA[i]];
        }
    }

    cout << ret << endl;
}