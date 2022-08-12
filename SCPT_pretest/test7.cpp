#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;//The number of candidates
int A[100000 + 10];//Temperament value

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
}

int main()
{
    InputData();//	Input function

    //	Create the code
    vector<int> iIntro;
    vector<int> iExtro;
    for (int i = 0; i < N; i++) {
        if (A[i] < 0) iIntro.push_back(A[i]);
        else iExtro.push_back(A[i]);
    }

    sort(iIntro.begin(), iIntro.end());
    sort(iExtro.begin(), iExtro.end());

    int iLen = (iIntro.size() < iExtro.size()) ? iIntro.size() : iExtro.size();
    int iCmp[iLen] = {0};
    for (int i = 0; i < iLen; ++i) {
        iCmp[i] = iIntro[i] + iExtro[i];
    }

    sort(iCmp, iCmp + iLen);

    return 0;
}
