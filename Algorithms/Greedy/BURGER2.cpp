// Link: https://www.codechef.com/problems/BURGERS2
// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T, X, Y, N, R;
	cin >> T;
	for (int t = 0; t < T; ++t) {
	    cin >> X >> Y >> N >> R;
	    int nX = 0, nY = N;
	    if (N*Y <= R) {
	        cout << nX << " " << nY << "\n";
	        continue;
	    } else if (N*X > R) {
	        cout << -1 << "\n";
	        continue;
	    }
	    bool bAns = false;
	    for (int i = 0; i < N; ++i) {
	        ++nX;
	        --nY;
	        if (nX*X + nY*Y <= R) {
	            cout << nX << " " << nY << "\n";
	            bAns = true;
	            break;
	        }
	    }
	    if (!bAns) cout << -1 << "\n";
	}
}
