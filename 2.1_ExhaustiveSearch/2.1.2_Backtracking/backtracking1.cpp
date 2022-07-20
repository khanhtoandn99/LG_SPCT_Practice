/**
 * Xay dung xau nhi phan co do dai n
 * 
**/

#include <iostream>
using namespace std;

int N, X[100];

void input()
{
    cout << "Input N: ";
    cin >> N;
}

void print()
{
    for (int i = 1; i <= N; ++i) {
        cout << X[i];
    }
    cout << endl;
}

void Try(int i)
{
    for (int j = 0; j <= 1; ++j) {
        X[i] = j;
        if (i == N) {
            print();
        }
        else {
            Try(i + 1);
        }
    }
}


int main()
{
    input();
    Try(1);
}