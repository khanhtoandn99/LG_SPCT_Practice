#include <iostream>
using namespace std;

int N;//The number of goods to send 
int C[10];//The number of BOXes(in order of 1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000)
int sol[10] = {0};//The number of boxes to send

void InputData() {
    int i;
    cin >> N;
    for(i = 0; i < 10; i++){
        cin >> C[i];
    }
}

void OutputData(int ans) {
    int i;
    cout << ans << endl;
    for(i = 0; i < 10; i++){
        cout << sol[i] << " ";
    }
    cout << endl;
}

int main() {
    int ans = -1;

    InputData();//	Input function

    //	Create the code
    const int Type[10] = {1,5,10,50,100,500,1000,3000,6000,12000};
    int iSum = 0;

    for (int i = 0; i < 10; ++i) {
        for (int j = C[i]; j > 0; --j) {
            int iRest = N - (j*Type[i] + iSum);
            if (iRest == 0) { // compeleted
                sol[i] = j;
                break;
            }
            if (iRest < Type[i+1]) continue;
            if (iRest%Type[i+1] == 0) {
                iSum += j*Type[i];
                sol[i] = j;
                break;
            }
        }
    }
    ans = sol[0] + sol[1] + sol[2] + sol[3] + sol[4] + sol[5] + sol[6] + sol[7] + sol[8] + sol[9];

    OutputData(ans);//	Output function

    return 0;
}