#include <iostream>
using namespace std;

int N;//Number of mushrooms
int P[150000 + 10];//Mushroom value

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> P[i];
	}
}

int main(){
	int ans = 0;

	InputData();			//	Input function

	//	Write the code
    bool bOdd = true;
    for (int i = 1; i < N; ++i) {
        if (P[i] < P[i-1] && bOdd == true) {
            ans += P[i-1];
            bOdd = false;
        } else if (P[i] > P[i-1] && bOdd == false) {
            ans -= P[i-1];
            bOdd = true;
        }
    }
    
    if (bOdd == true) ans += P[N-1];
	
	cout << ans << endl;	//	Output answer
	return 0;
}
