#include <iostream>
using namespace std;

int N;//The number of candidates
// int A[100000 + 10] = {-10,-6,-5,2,7,14,21,30};//Temperament value
int A[100000 + 10] = {-6,-3,-1,0,1,2,4,5};//Temperament value

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
}

int main(){
    InputData();//	Input function

    //	Create the code
    int r = N-1, minR = N-1;
    int l = 0, minL;
    int closest = 1000000000;
    for (l = 0; l < r; ++l) {
        while (r > l) {
            // cout << "l: " << l << " r: " << r << endl;
            int absDiff = abs(A[l] + A[r]);
            if (absDiff < closest) {
                closest = absDiff;
                if (r < minR) minR = r;
                minL = l;
            }
            if (abs(A[r]) < abs(A[l]) && absDiff >= closest) break;
            --r;
        }
        r = minR;
    }
    cout << minL << " " << minR << endl;
    return 0;
}