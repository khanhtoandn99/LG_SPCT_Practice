#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "math.h"

using namespace std;

int N;//the number of test cases
int B;//number system
char S[110];//first integer
char D[110];//second integer

int iUnsignedSLen;
int iUnsignedDLen;
bool bSNegative;
bool bDNegative;

void InputData()
{
	cin >> B >> S >> D;
}

void convertSD2Decimal()
{
    if (B != 10)
    {
        int iS = 0;
        int iSLen = strlen(S);
        for (int i = 0; i < iSLen; ++i) {
            char x = S[iSLen - 1 - i];
            if ('0' <= x && x <= '9') {
                iS += (x - 48)*pow(B, i);
            } else {
                iS += (x - 65 + 10)*pow(B, i);
            }
        }
        memset(&S, 0x0, sizeof(S));
        sprintf(S, "%d", iS);
        // cout << S << endl;

        int iD = 0;
        int iDLen = strlen(D);
        for (int i = 0; i < iDLen; ++i) {
            char x = D[iDLen - 1 - i];
            if ('0' <= x && x <= '9') {
                iD += (x - 48)*pow(B, i);
            } else {
                iD += (x - 65 + 10)*pow(B, i);
            }
        }
        memset(&D, 0x0, sizeof(D));
        sprintf(D, "%d", iD);
        // cout << D << endl;

        bSNegative = false;
        bDNegative = false;
        return;
    }

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
}

void calculating()
{
    vector<int> vResultList[iUnsignedDLen];
    int iDLastIdx = iUnsignedDLen - 1;
    int iSLastIdx = iUnsignedSLen - 1;
    for (int i = iDLastIdx; i >= 0; --i) {
        vResultList[iDLastIdx - i].resize(iUnsignedSLen + iUnsignedDLen - 1, 0);
        for (int j = iSLastIdx; j >= 0; --j) {
            vResultList[iDLastIdx - i][iSLastIdx - j + iDLastIdx - i] = (int)((D[i] - 48)*(S[j] - 48));
        }
    }

    vector<int> result;
    int iRem = 0;
    for (int i = 0; i < iUnsignedSLen + iUnsignedDLen - 1; ++i) {
        int iRes = 0;
        for (int j = 0; j < iUnsignedDLen; ++j) {
            iRes += vResultList[j].at(i);
        }
        result.push_back( (iRes + iRem) - ((int)(iRes + iRem)/10)*10 );
        iRem = (int)((iRes + iRem)/10);
    }
    if (iRem != 0) result.push_back(iRem);

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
        convertSD2Decimal();
        calculating();

	}
	return 0;
}