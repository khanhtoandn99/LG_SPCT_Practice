#include <iostream>
#include <vector>
using namespace std;

int N;//Number of buildings
int H[80010];//Height of buildings

int S[80010] = {0};

typedef struct
{
    int maxAt;
    int minAt;
} DECS_T;

void Input_Data(void){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> H[i];
	}
}

int main(){
	long long ans = 0;
	Input_Data();		//	Input function

	//	Write the code
    // Idea: divide the array H into decsreasing series DECS_T
    vector<DECS_T> vDecs;
    int i = 0;
    while (i < N-1)
    {
        DECS_T tmp;
        tmp.maxAt = i;
        while (H[i] > H[i+1] && i < N-1) ++i;
        tmp.minAt = i;
        vDecs.push_back(tmp);
        ++i;
    }

    int vDecSz = vDecs.size();
    for (i = 0; i < vDecSz; ++i) {
        for (int j = vDecs[i].maxAt; j < vDecs[i].minAt + 1; ++j) {
            S[j] = vDecs[i].minAt - j;
            for (int k = i + 1; k < vDecSz; ++k) {
                if (H[j] <= H[vDecs[k].maxAt]) break;
                S[j] += vDecs[k].minAt - vDecs[k].maxAt + 1;
            }
        }
    }
	for (i = 0; i < N; ++i) {
        ans += S[i];
    }
	cout << ans << endl;	//	Output right answer
	return 0;
}
