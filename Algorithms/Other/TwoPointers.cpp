#include <iostream>

using namespace std;

int a[10] = {1,2,4,6,7,8,9,11,16,20};
int b[10] = {0,2,5,10,12,13,14,15,18,21};
int c[20] = {0,};

int main()
{
    int i = 0, j = 0, k = 0;
    while (i < 10 && j < 10)
    {
        if (a[i] <= b[j]) {
            c[k] = a[i];
            ++i;
        } else if (a[i] > b[j]) {
            c[k] = b[j];
            ++j;
        }
        ++k;
    }

    for (int x = 0; x < 20; ++x) cout << c[x] << " ";
    cout << endl;
    
}