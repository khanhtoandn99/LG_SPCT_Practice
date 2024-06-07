/**
 * input n,k
 * 
 */

#include <iostream>

using namespace std;

int a[100];
int n;
int i = 0, k = 0, l = 0, r = 0;

void getInput()
{
    cout << "Input n:" << endl;
    cin >> n;

    for (int i = 0; i <= n; ++i) {
        a[i] = i;
    }
}

void print(int a[], int n)
{
    for (int i = 1; i <= n; ++i) {
        cout << a[i];
    }
    cout << endl;
}

int generate()
{
    i = n - 1;
    while ((i > 0) && (a[i] > a[i+1])) --i;
    if (i == 0) return 0;
    // determined i

    k = n;
    while (a[k] < a[i]) --k;
    swap(a[i], a[k]);
    // determined least greater than a[i]

    // Now sorting, just swap near-left and near-right 
    l = i + 1;
    r = n;
    while (l < r) {
        swap(a[l], a[r]);
        ++l;
        --r;
    }
    print(a, n);
    return 1;
}

int main()
{
    cout << "Hello world" << endl;
    getInput();
    print(a, n);
    while (generate() == 1); // Thís generate() should not use recursion, it cause stack overflow
    return 0;
}