#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

int N;//the number of test cases
int B;//number system
char S[110];//first integer
char D[110];//second integer

void InputData()
{
	cin >> B >> S >> D;
}

int iUnsignedSLen;
int iUnsignedDLen;
bool bSNegative;
bool bDNegative;

void convertSDInfo()
{
    if (S[0] == '-') {
        bSNegative = true;
        iUnsignedSLen = strlen(S) - 1;
        for (int i = 0; i < iUnsignedSLen; ++i) {
            S[i] = S[i + 1];
        }
        S[iUnsignedSLen] = 0;
    } else {
        bSNegative = false;
        iUnsignedSLen = strlen(S);
    }

    if (D[0] == '-') {
        bDNegative = true;
        iUnsignedDLen = strlen(D) - 1;
        for (int i = 0; i < iUnsignedDLen; ++i) {
            D[i] = D[i + 1];
        }
        D[iUnsignedDLen] = 0;
    } else {
        bDNegative = false;
        iUnsignedDLen = strlen(D);
    }

    // cout << iUnsignedSLen << endl;
    // cout << iUnsignedDLen << endl;
    // cout << bSNegative << endl;
    // cout << bDNegative << endl;
    // cout << S << endl;
    // cout << D << endl;
    // cout << endl;
}

void calculating()
{
    vector<int> vResultList[iUnsignedDLen];

    for (int i = iUnsignedDLen - 1; i >= 0; --i) {
        for (int j = iUnsignedSLen - 1; j >= 0; --j) {
            vResultList[iUnsignedDLen - 1 - i].push_back( (int)((D[i] - 48)*(S[j] - 48)) );
        }
    }

    for (int i = 0; i < iUnsignedDLen; ++i) {
        for (int j = 0; j < i; ++j) {
            vResultList[i].insert(vResultList[i].begin(), 0);
        }
        vResultList[i].resize(iUnsignedSLen + iUnsignedDLen - 1, 0);
    }

    vector<int> vResult;
    for (int i = 0; i < vResultList[0].size(); ++i) {
        int res = 0;
        for (int j = 0; j < iUnsignedDLen; ++j) {
            res += vResultList[j].at(i);
        }
        vResult.push_back(res);
    }

    // print debug
    for (int i = 0; i < iUnsignedDLen; ++i) {
        for (int j = 0; j < vResultList[i].size(); ++j) {
            cout << vResultList[i].at(j) << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < vResult.size(); ++i) {
        cout << vResult[i] << " ";
    }
}

int main(){
	int i;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		InputData();//input function
		//	write the code
        convertSDInfo();
        calculating();

	}
	return 0;
}