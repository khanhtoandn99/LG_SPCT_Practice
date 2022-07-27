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

int chtoint(char x)
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

    bool bSNegative = (S[0] == '-') ? true : false;
    bool bDNegative = (D[0] == '-') ? true : false;
    int iSLen = strlen(S);
    int iDLen = strlen(D);

    int vRes[iDLen - bDNegative][iSLen - bSNegative + iDLen - bDNegative - 1];
    memset(vRes, 0x0, sizeof(vRes));

    for (int i = iDLen - 1; i >= bDNegative; --i) {
        for (int j = iSLen - 1; j >= bSNegative; --j) {
            vRes[i - bDNegative][iSLen - 1 - j + iDLen - 1 - i] = chtoint(D[i])*chtoint(S[j]);
        }
    }

    char res[iSLen - bSNegative + iDLen - bDNegative]{0};
    int iRem = 0;
    for (int i = 0; i < iSLen - bSNegative + iDLen - bDNegative - 1; ++i) {
        int iSum = 0;
        for (int j = 0; j < iDLen - bDNegative; ++j) {
            iSum += vRes[j][i];
        }
        res[i] = itoch((iSum + iRem)%B);
        iRem = (int)(iSum + iRem)/B;
        // cout << res[i] << " " << iRem << " -- ";
    }
    if (iRem > 0) res[strlen(res)] = itoch(iRem);

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