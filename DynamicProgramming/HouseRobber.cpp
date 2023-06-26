/**
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that
adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into 
on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police. 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400

 */

#include <iostream>
#include <vector>

using namespace std;

int N;
int mem[100];

int rob(vector<int>& nums);
int max(int a, int b);

int max(int a, int b)
{
    return a > b ? a : b;
}

int solve(vector<int>& nums, int i)
{
    if (i < 0) return 0;
    if (mem[i] != -1) return mem[i];
    mem[i] = max(solve(nums, i - 1), solve(nums, i - 2) + nums.at(i));
    return mem[i];
}

int rob(vector<int>& nums)
{
    return solve(nums, N - 1);
}

int main()
{
    vector<int> vNums;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        mem[i] = -1;
        int x;
        cin >> x;
        vNums.push_back(x);
    }
    cout << rob(vNums);
    cout << endl;
}