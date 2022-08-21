#include <iostream>
using namespace std;

int N;//Number of buildings
int H[80010];//Height of buildings

int S[80010] = {0}; // nums of rooftops can be seen of each building S[i]

void Input_Data(void){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> H[i];
	}
}

int main(){
	long long ans = 0;
	Input_Data();//	Input function

	//	Write the code
    int HMaxIdx = N-1;
    S[N-1] = 0;
    S[N-2] = 0;
    if (H[N-2] >= H[N-1]) {
        S[N-2] = 1;
        HMaxIdx = N - 2;
    }
    for (int i = N-3; i >= 0; --i)
    {
        int j = i + 1;
        if (H[i] < H[j]) {
            S[i] = 0; 
            continue;
        }
        while (H[i] >= H[j] && j < N) {
            // if (j == HMaxIdx) {
            //     HMaxIdx = i;
            //     S[i] = S[j] + 1;
            //     break;
            // }
            ++S[i];
            ++j;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        // cout << S[i] << " ";
        ans += S[i];
    }
    // cout << endl;

	cout << ans << endl;	//	Output right answer
	return 0;
}