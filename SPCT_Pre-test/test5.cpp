#include <iostream>
using namespace std;

int N;//Number of mushrooms
int P[150000 + 10];//Mushroom value

void InputData() {
    cin >> N;
    for (int i = 0; i < N; i++){
       cin >> P[i];
    }
}

int main() { 
    int ans = -1;

    InputData();			//	Input function

    //	Write the code
    /**
     * Use Greedy Algorithm:
     * Find descreasing subsequences one by one
     * Then let First Element value subtract Last Element (max - min)
     * Plus to iSum variable
     * Finally, plus the P[N-1] in 
     * case Last Element of most recent equal to N - 1 or not.
     */
    int iSum = 0;
    int iPLastIdx = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (P[i] <= P[i+1]) continue;

        int iLen = 2;
        for (int j = i + 1; j < N - 1; ++j) {
            if (P[j] > P[j+1]) ++iLen;
            else break;
        }

        iSum += (P[i] - P[i + iLen - 1]);
        // cout << "iSum = " << iSum << endl;
        iPLastIdx = i + iLen - 1;

        i += iLen - 1;
    }

    ans = iSum + P[N-1];
    cout << ans << endl;	//	Output answer
    return 0;
}
