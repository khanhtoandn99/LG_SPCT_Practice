#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N; // candidates
int M; // voting participant

int main()
{
    map<string,int> mpScore;
    map<string,int> mpOrder_name2order;
    map<int,string> mpOrder_order2name;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string sName;
        cin >> sName;
        mpScore.insert({sName, 0});
        mpOrder_name2order[sName] = i;
        mpOrder_order2name[i] = sName;
    }
    
    cin >> M;
    int score_1st = 0, score_2nd = 0, score_3rd = 0;
    string name_1st, name_2nd, name_3rd;
    for (int i = 0; i < M; ++i)
    {
        string sName;
        int iScore;
        cin >> sName >> iScore;
        map<string,int>::iterator it;
        it = mpScore.find(sName);
        if (it == mpScore.end()) continue;
        it->second += iScore;
        
        if (it->second >= score_1st) {
            score_3rd = score_2nd;
            score_2nd = score_1st;
            score_1st = it->second;
        }
        else if (it->second >= score_2nd) {
            score_3rd = score_2nd;
            score_2nd = it->second;
        }
        else if (it->second > score_3rd) {
            score_3rd = it->second;
        }
    }
    vector<int> ls_1stCandiates_byOder;
    vector<int> ls_2ndCandiates_byOder;
    vector<int> ls_3rdCandiates_byOder;
    for (map<string,int>::iterator it = mpScore.begin(); it != mpScore.end(); ++it) {
        if (it->second == score_1st) {
            ls_1stCandiates_byOder.push_back(mpOrder_name2order[it->first]);
        }
        else if (it->second == score_2nd) {
            ls_2ndCandiates_byOder.push_back(mpOrder_name2order[it->first]);
        }
        else if (it->second == score_3rd) {
            ls_3rdCandiates_byOder.push_back(mpOrder_name2order[it->first]);
        }
    }
    int count = 0;
    sort(ls_1stCandiates_byOder.begin(), ls_1stCandiates_byOder.end());
    for (int i = 0; i < ls_1stCandiates_byOder.size(); ++i) {
        cout << mpOrder_order2name[ls_1stCandiates_byOder[i]] << " " << score_1st << endl;
        ++count;
        if (count == 3) return 0;
    }
    sort(ls_2ndCandiates_byOder.begin(), ls_2ndCandiates_byOder.end());
    for (int i = 0; i < ls_2ndCandiates_byOder.size(); ++i) {
        cout << mpOrder_order2name[ls_2ndCandiates_byOder[i]] << " " << score_2nd << endl;
        ++count;
        if (count == 3) return 0;
    }
    sort(ls_3rdCandiates_byOder.begin(), ls_3rdCandiates_byOder.end());
    for (int i = 0; i < ls_3rdCandiates_byOder.size(); ++i) {
        cout << mpOrder_order2name[ls_3rdCandiates_byOder[i]] << " " << score_3rd << endl;
        ++count;
        if (count == 3) return 0;
    }
	return 0;
}