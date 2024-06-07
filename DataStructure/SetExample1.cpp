// #include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <string>

using namespace std;

string sInput;
multiset<long, greater<long> > lSet;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> sInput)
    {
        if (sInput == "-") {
            if (!lSet.empty()) lSet.erase(*lSet.begin());
        }
        else if (lSet.size() < 15000) {
            lSet.insert(std::stol(sInput, nullptr));
        }
        sInput.clear();
    }

    set<long, greater<long> > ret(lSet.begin(), lSet.end()); // To remove duplicated element value
    cout << ret.size() << "\n";
    for (set<long, greater<long> >::iterator it = ret.begin(); it != ret.end(); ++it) {
        cout << *it << "\n";
    }
    return 0;
}