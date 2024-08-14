#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int, greater<int>> ss;
    for (int i = 0; i < 10; ++i) {
        ss.insert(i);
    }
    ss.insert(1);
    ss.insert(2);
    ss.insert(3);
    cout << ss.size() << "\n";

    for (set<int, greater<int>>::iterator it = ss.begin(); it != ss.end(); ++it) {
        // int idx = &it - ss.begin();
        cout << "index " << it - ss.begin() << " = " << *it << endl;
    }
    // if (ss.find(8) != ss.end()) cout << "ss.find(8) found!" << endl;
    // if (ss.count(8) != 0) cout << "ss.count(8) found!" << endl;
    return 0;
}