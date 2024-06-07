/**
Ta sẽ lập chương trình liệt kê các tập con k phần tử của tập {1, 2, …, n} theo thứ tự từ điền
Ví dụ: với n = 5, k = 3, ta phải liệt kê đủ 10 tập con:
1.{1, 2, 3} 2.{1, 2, 4} 3.{1, 2, 5} 4.{1, 3, 4} 5.{1, 3, 5}
6.{1, 4, 5} 7.{2, 3, 4} 8.{2, 3, 5} 9.{2, 4, 5} 10.{3, 4, 5}
*/

#include <iostream>

using namespace std;

int n, k;
int a[101] = {0,};

void input()
{
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) a[i] = i;
}

void print()
{
    for (int i = 1; i <= k; ++i) cout << a[i];
    cout << endl;
}

void generate()
{
    while (1)
    {
        int i = k;
        print();
        while (i > 0 && a[i] == n-k+i) --i;

        if (i == 0) return;
        else {
            ++a[i];
            for (int j = i+1; j <= k; ++j)
                a[j] = a[j-1] + 1;
        }
    }
}

int main()
{
    input();
    generate();
}