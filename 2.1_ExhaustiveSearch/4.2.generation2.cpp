/**
 * input n,k
 * 
 */

#include <iostream>

using namespace std;

int a[100];
int n, k;

void getInput()
{
    cout << "Input n, k" << endl;
    cin >> n >> k;

    for (int i = 0; i <= n; ++i) {
        a[i] = i;
    }
}

void print(int a[], int k)
{
    for (int i = 1; i <= k; ++i) {
        cout << a[i];
    }
    cout << endl;
}

void generate()
{
    int i = k;
    while ((i > 0) && a[i] == n - k + i) {
        --i;
    }
    if (i <= 0) return;
    ++a[i];
    for (int j = i + 1; j <= k; ++j) {
        a[j] = a[j - 1] + 1;
    }
    print(a, k);
    generate();
}

int main()
{
    cout << "Hello world" << endl;
    getInput();
    print(a, k);
    generate();
    return 0;
}