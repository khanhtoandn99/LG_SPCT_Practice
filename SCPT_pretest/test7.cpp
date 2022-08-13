#include <iostream>
using namespace std;

int N;//The number of candidates
int A[100000 + 10];//Temperament value

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
}

int main(){
    InputData();//	Input function

    //	Create the code
    if (A[0] >= 0) cout << A[0] << " " << A[1] << endl;
    int minR = N-1, r = N-1;
    int minL = 0, l = 1;
    int closest = abs(A[minL] + A[minR]);
    for (l = 1; l < r; ++l) {
        while (r > l) {
            // cout << "l: " << l << " r: " << r << endl;
            int absDiff = abs(A[l] + A[r]);
            if (absDiff < closest) {
                closest = absDiff;
                if (r < minR) minR = r;
                minL = l;
            }
            if (A[r] < abs(A[l])) break;
            --r;
        }
    }
    cout << minL << " " << minR << endl;
    return 0;
}