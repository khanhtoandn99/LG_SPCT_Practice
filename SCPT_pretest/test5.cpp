#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;//Number of mushrooms
int P[150000 + 10];//Mushroom value

int posIdx[150000];

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> P[i];
        posIdx[i] = -1;
	}
}

bool myfunction (int i,int j) { return (i<j); }

int main(){
	int ans = -1;

	InputData(); //	Input function

	//	Write the code
    int sum = 0;
    int iPos = 0;
    for (int i = 0; i < N; i += 2) {
        if (P[i] > P[i+1] && P[i+1] > P[i+2] ||
            P[i] <= P[i+1] && P[i+1] < P[i+2]) {
            posIdx[iPos++] = i;
            sum += P[i];
        }
        else if (P[i] <= P[i+1] && P[i+1] > P[i+2]) {
            posIdx[iPos++] = i + 1;
            sum += P[i+1];
        }
    }

    // // debug:
    // for (int i = 0; posIdx[i] != -1; ++i) {
    //     cout << P[posIdx[i]] << " ";
    // }
    // cout << endl;

    // posIdx[] = {0, 3, 7};
    // 0   1   2   3   4   5   6   7
    // 7   2   1   8   4   3   5   6
    // 0   -   -   3   -   -   -   7

    cout << "sum = " << sum << endl;
    for (int i = 0; i < iPos; ++i) {
        int *pBegin = P, iLen = 0;
        pBegin = pBegin + posIdx[i] + 1;
        if (posIdx[i+1] != -1) iLen = posIdx[i+1] - posIdx[i];

        std::sort(pBegin, pBegin + iLen);

        if (posIdx[i+1] == -1) sum -= 0;
        else sum -= pBegin[0];
    }

    ans = sum;
	cout << ans << endl;	//	Output answer
	return 0;
}
