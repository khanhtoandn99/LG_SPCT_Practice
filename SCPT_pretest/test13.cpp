#include <iostream>
#include <string>
using namespace std;

string S;
string C;

int main()
{
    cin >> S >> C;
    long unsigned int cursor = S.length(); // value range: 0 - S.length()
    
    for (long unsigned int Ci = 0; Ci < C.length(); ++Ci)
    {
        switch (C[Ci])
        {
        case 'L': {
            if (cursor == 0) break;
            --cursor;
            while (cursor - 1 > 0 && S[cursor] == '-') --cursor;
        } break;
        case 'R': {
            if (cursor == S.length()) break;
            ++cursor;
            while (cursor + 1 < S.length() && S[cursor] == '-') ++cursor;
        } break;
        case 'B': {
            if (cursor == 0) break;
            --cursor;
            S[cursor] = '-';
            while (cursor - 1 > 0 && S[cursor-1] == '-') --cursor;
        } break;
        default: {
            S.insert(S.begin()+cursor, C[Ci]);
            ++cursor;
            while (cursor + 1 < S.length() && S[cursor] == '-') ++cursor;
        } break;
        }
    }
    
    for (long unsigned int i = 0; i < S.length(); ++i) {
        if (S[i] == '-') continue;
        cout << S[i];
    }
    cout << endl;
}