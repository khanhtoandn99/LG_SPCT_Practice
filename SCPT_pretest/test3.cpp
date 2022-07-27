#include <iostream>
#include <cstring>

using namespace std;

int N; //the number of test cases
int B; //number system
char S[110]; //first integer
char D[110]; //second integer

void InputData() {
    cin >> B >> S >> D;
}

int chtoi(char x)
{
    return ('0' <= x && x <= '9') ? (int)(x - 48) : (int)(x - 65 + 10);
}

char itoch(int x)
{
    return (0 <= x && x <= 9) ? (char)(x + 48) : (char)(x + 65 - 10);
}

void Solve()
{
    if (S[0] == '0' || D[0] == '0') {
        cout << "0" << endl;
        return;
    }

    bool bSNegative = false;
    bool bDNegative = false;
    int iSLen = strlen(S);
    int iDLen = strlen(D);

    if (B == 10 && S[0] == '-') {
        bSNegative = true;
        iSLen -= 1;
        for (int i = 0; i < iSLen; ++i) {
            S[i] = S[i + 1];
        }
        S[iSLen] = 0;
    }

    if (B == 10 && D[0] == '-') {
        bDNegative = true;
        iDLen -= 1;
        for (int i = 0; i < iDLen; ++i) {
            D[i] = D[i + 1];
        }
        D[iDLen] = 0;
    }

    int vResLen = iSLen + iDLen - 1;
    int vRes[iDLen][vResLen];
    memset(vRes, 0x0, sizeof(vRes));

    for (int i = iDLen - 1; i >= 0; --i) {
        for (int j = iSLen - 1; j >= 0; --j) {
            vRes[i][iSLen - 1 - j + (iDLen - 1 - i)] = chtoi(D[i])*chtoi(S[j]);
        }
    }

    int iResLen = iSLen + iDLen;
    char res[iResLen]{0};
    int iRem = 0;
    for (int i = 0; i < vResLen; ++i) {
        int iSum = 0;
        for (int j = 0; j < iDLen; ++j) {
            iSum += vRes[j][i];
        }
        res[i] = itoch((iSum + iRem)%B);
        iRem = (int)(iSum + iRem)/B;
        // cout << res[i] << " " << iRem << " -- ";
    }
    if (iRem > 0) res[iResLen - 1] = itoch(iRem);

    if (bSNegative ^ bDNegative) cout << "-";
    for (int i = strlen(res) - 1; i >= 0; --i)
        cout << res[i];
    cout << endl;
}

int main() {
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        InputData(); //input function
        // 	write the code
        Solve();
    }
    return 0;
}