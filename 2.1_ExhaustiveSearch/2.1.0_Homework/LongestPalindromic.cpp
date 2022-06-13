#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    int iStrLen = s.length();
    string longestPalindrome;
    string str = s;
    for (int nL = 0; nL < iStrLen; ++nL) {
        for (int nR = iStrLen; nR > nL; --nR) {
            string str_swaped;
            int iStrLen = str.length();

            if (iStrLen%2 == 0 && str[iStrLen/2] != str[iStrLen/2 - 1]) { // edge reduction process
                str.pop_back();
                continue;
            }
            // else if (iStrLen%2 == 1 && str[iStrLen/2 - 1] != str[iStrLen/2 + 2]) {
            //     str.pop_back();
            //     continue;
            // }

            for (int i = 0; i < iStrLen; ++i)
                str_swaped.push_back(str[iStrLen - 1 - i]);

            if (str == str_swaped && iStrLen > longestPalindrome.length()) longestPalindrome = str;
            str.pop_back();
        }
        str = s;
        str.erase(0, nL + 1);
    }
    return longestPalindrome;
}

int main()
{
    string strInput;
    cin >> strInput;
    cout<<"longestPalindrome = " << longestPalindrome(strInput);

    return 0;
}