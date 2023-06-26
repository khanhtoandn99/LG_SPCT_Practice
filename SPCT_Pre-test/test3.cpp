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

    char *pS = S, *pD = D;
    if (S[0] == '-') pS++;
    if (D[0] == '-') pD++;
    int iSLen = strlen(pS), iDLen = strlen(pD);

    int iRes[iDLen][iDLen + iSLen - 1];
    memset(iRes, 0x0, sizeof(iRes));

    for (int d = iDLen - 1; d >= 0; --d) {
        for (int s = iSLen - 1; s >= 0; --s) {
            iRes[iDLen - 1 - d][iSLen - 1 - s + (iDLen - 1 - d)] = chtoi(pD[d])*chtoi(pS[s]);
        }
    }

    char result[220] = {0};
    int iRem = 0;
    for (int i = 0; i < iDLen + iSLen - 1; ++i) {
        int iSum = 0;
        for (int d = 0; d < iDLen; ++d) {
            iSum += iRes[d][i];
        }
        iSum += iRem;
        result[i] = itoch((int)(iSum%B));
        iRem = (int)(iSum/B);
    }

    // Xu ly phan du con lai:
    for (int i = iDLen + iSLen - 1; iRem%B > 0; ++i) {
        result[i] = itoch((int)(iRem%B));
        iRem = iRem/B;
    }

    // In ket qua
    if ((S[0] == '-') ^ (D[0] == '-')) cout << "-";
    for (int i = strlen(result) - 1; i >= 0; --i) {
        cout << (char)result[i];
    }
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