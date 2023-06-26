#include <iostream>
using namespace std;

int N;//Number of sponsored goods
int D[100000 + 10];//Preference
int sol = -30001;//Maximum preference of the first method

void InputData(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> D[i];
	}
}

void Solve()
{
	int i, sum = 0;
	for (i = 0; i < N - 2; i++) {
		sum = D[i] + D[i + 1] + D[i + 2];
		if (sum > sol) sol = sum;
	}
}

void Solve2()
{
    for (int i = 0; i < N; i++) {
        int k_max = N - i;
        cout << "k_max = " << k_max << endl;
        for (int k = 0; k < k_max; k++) {
            int sum = 0;
            for (int j = 0; j < k + 1; j++) {
                cout << D[i + j] << " ";
                sum += D[i + j];
            }
            cout << "sum = " << sum << endl;
            if (sum > sol) sol = sum;
        }
        cout << endl << endl;
    }
}


int main(){
	InputData(); // Input function
	Solve2();
	cout << sol << endl; // Output
    system("pause");
	return 0;
}