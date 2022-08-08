// Link: https://leetcode.com/problems/longest-increasing-subsequence/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLen = 1, iLen = 1;

    int lengthOfLIS(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            iLen = 1;
            dp(nums, i);
            cout << "maxLen = " << maxLen << endl;
        }
        return maxLen;
    }

     // 0 1 2 
    // [3,1,2]
    int dp(vector<int>& nums, int pos) {
        if (pos >= nums.size() - 1) {

        }
        // 0 1 2 3 4 5
        // 0,1,0,3,2,3
        for (int i = pos + 1; i < nums.size(); ++i) {
            if (nums[pos] < nums[i]) {
                ++iLen;
                if (iLen >= maxLen) maxLen = iLen;
                dp(nums, i);
            }
        }

        return 0;
    }
};

// [0,1,0,3,2,3]
// [7,7,7,7,7,7]
// [10,9,2,5,3,7,101,18]
int main()
{
    vector<int> nums;
    int N = 8;
    int a[N] = {10,9,2,5,3,7,101,18};

    for (int i = 0; i < N; ++i) {
        nums.push_back(a[i]);
    }

    cout << "----------------------" << endl;
    Solution sol;
    cout << sol.lengthOfLIS(nums) << endl;
}