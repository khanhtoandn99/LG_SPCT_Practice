#include <iostream>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include "math.h"

using namespace std;

int N;//the number of test cases
int B;//number system
char S[110];//first integer
char D[110];//second integer

// Input properties:
int iSArr[110];
int iDArr[110];
int iSLen;
int iDLen;
bool bSNegative;
bool bDNegative;

void InputData()
{
	cin >> B >> S >> D;
}

void ParseInput()
{
    iSLen = strlen(S);
    iDLen = strlen(D);
    bSNegative = false;
    bDNegative = false;

    if (B == 10 && S[0] == '-') {
        bSNegative = true;
        iSLen -= 1;
    }
    if (B == 10 && D[0] == '-') {
        bDNegative = true;
        iDLen -= 1;
    }
    for (int i = 0; i < iSLen; ++i) {
        iSArr[i] = ('0' <= S[i + bSNegative] && S[i + bSNegative] <= '9') ? (int)(S[i + bSNegative] - 48) : (int)(S[i + bSNegative] - 65 + 10);
        // cout << (int)iSArr[i];
    }
    // cout << endl;
    for (int i = 0; i < iDLen; ++i) {
        iDArr[i] = ('0' <= D[i + bDNegative] && D[i + bDNegative] <= '9') ? (int)(D[i + bDNegative] - 48) : (int)(D[i + bDNegative] - 65 + 10);
        // cout << (int)iDArr[i];
    }
}

void calculating()
{
    // cout << endl;
    vector<int> vResultList[iDLen];
    int iDLastIdx = iDLen - 1;
    int iSLastIdx = iSLen - 1;
    for (int i = iDLastIdx; i >= 0; --i) {
        vResultList[iDLastIdx - i].resize(iSLen + iDLen - 1, 0);
        for (int j = iSLastIdx; j >= 0; --j) {
            vResultList[iDLastIdx - i][iSLastIdx - j + iDLastIdx - i] = iDArr[i]*iSArr[j];
        }
    }

    // // Debug result
    // for (int i = 0; i < iDLen; ++i) {
    //     for (int j = 0; j < vResultList[i].size(); ++j) {
    //         cout << vResultList[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<char> result;
    int iRem = 0;
    for (int i = 0; i < iSLen + iDLen - 1; ++i) {
        int iRes = 0;
        for (int j = 0; j < iDLen; ++j) {
            iRes += vResultList[j].at(i);
        }
        int iRedundant = (iRes + iRem) - (int)((iRes + iRem)/B)*B;
        if (iRedundant > 9) result.push_back((char)(iRedundant + 65 - 10));
        else result.push_back((char)(iRedundant + 48));
        // cout << iRedundant << " ";
        iRem = (int)((iRes + iRem)/B);
    }
    if (iRem != 0) result.push_back((char)(iRem + 48));

    // output
    if (bSNegative ^ bDNegative) cout << "-";
    for (int j = result.size() - 1; j >= 0; --j) {
        cout << result.at(j);
    }
}

int main(){
	int i;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		InputData();//input function
		//	write the code
        ParseInput();
        calculating();

	}
	return 0;
}