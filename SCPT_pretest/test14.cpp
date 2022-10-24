#include <iostream>
#include <string>
#include <map>
using namespace std;

int N; // candidates
int M; // voting participant

int main()
{
    map<string,int> mpScore;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string sName;
        cin >> sName;
        mpScore.insert({sName, 0});
    }
    
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        string sName;
        int iScore;
        cin >> sName >> iScore;
        map<string,int>::iterator it;
        it = mpScore.find(sName);
        if (it == mpScore.end()) continue;
        it->second += iScore;
        
    }
	return 0;
}