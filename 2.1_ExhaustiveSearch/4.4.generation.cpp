#include <iostream>
#include <math.h>

using namespace std;

/**
 * k = 3
 * 
 * 000
 * 001
 * 010
 * 011
 * 100
 * 101
 * 110
 * 111
 */

int n; // number of bit
int a[1000] = {0};

void input();
void print(int a[], int n);

void input()
{
    cout << "Input n:";
    cin >> n;
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << endl;
}

void setAllTo0(int a[], int n, int pos)
{
    for (int i = pos; i < n; i++)
        a[i] = 0;
}

void generate(int a[], int n)
{
    print(a, n);
    int i = n - 1;
    while(i >= 0) {
        if (a[i] == 1) {
            i--;
        } else if (a[i] == 0) {
            a[i] = 1;
            setAllTo0(a, n, i + 1);
            print(a, n);
            i = n - 1;
        }
    }
}

int main()
{
    input();
    generate(a, n);
    system("pause");
}