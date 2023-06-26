#include <iostream>

using namespace std;

int binarySearch(int k[], int n, int X) {
    int inf = 1, sup = n, median;
    while (inf <= sup) {
        median = (inf + sup) / 2;
        if (k[median] == X)
            return median;
        if (k[median] < X)
            inf = median + 1;
        else
            sup = median -1;
    }
    return 0;
}

int main()
{
    int a[15] = {1,3,5,7,9,10,12,14,22,45,50};
    int k;
    cin >> k;
    cout << binarySearch(a, 11, k) << endl;
    return 0;
}