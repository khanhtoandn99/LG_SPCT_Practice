#include <bits/stdc++.h>

using namespace std;

string S = "";
string cmd = "";

int main()
{
    cin >> S >> cmd;
    size_t cursor = S.length();
    for (size_t i = 0; i < cmd.length(); ++i)
    {
        if (cmd.at(i) == 'L' && cursor > 0) --cursor;
        else if (cmd.at(i) == 'R' && cursor < S.length()) ++cursor;
        else if (cmd.at(i) == 'B')
        {
            if (cursor == 0) continue;
            S.erase(S.begin()+cursor-1);
            if (cursor > 0) --cursor;
        }
        else if ('a' <= cmd.at(i) && cmd.at(i) <= 'z') // "If it is a lowercase letter, add the lowercase letter to the left..." --> means the rest uppercase letters will be ignored
        {
            if (cursor == S.length()) {
                S.push_back(char(cmd.at(i)));
            }
            else {
                S.insert(S.begin()+cursor, char(cmd.at(i)));
            }
            if (cursor < S.length()) ++cursor;
        }
        // cout << S << " - " <<cursor << endl;
    }
    cout << S << endl;
	return 0;
}