// Link: https://leetcode.com/problems/longest-increasing-subsequence/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> L(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) L[i] = 1;

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    L[i] = max(L[i], L[j] + 1);
                }
            }
        }
        sort(L.begin(), L.begin() + nums.size());
        return L.at(L.size() - 1);
    }
};

int main()
{
    vector<int> nums;
    int a[6] = {0,1,0,3,2,3};

    for (int i = 0; i < 6; ++i) {
        nums.push_back(a[i]);
    }

    Solution sol;
    cout << sol.lengthOfLIS(nums) << endl;
}