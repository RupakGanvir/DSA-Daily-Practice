#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > sum || (sum + target) % 2 != 0)
        {
            return 0;
        }

        int subsetSum = (sum + target) / 2;
        if (subsetSum < 0)
            return 0;

        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;

        for (int num : nums)
        {
            for (int i = subsetSum; i >= num; --i)
            {
                dp[i] += dp[i - num];
            }
        }

        return dp[subsetSum];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;
    cout << "--- Test Case 1 ---\n";
    cout << "Ways to build target: " << solver.findTargetSumWays(nums1, target1) << "\n\n";

    vector<int> nums2 = {1};
    int target2 = 1;
    cout << "--- Test Case 2 ---\n";
    cout << "Ways to build target: " << solver.findTargetSumWays(nums2, target2) << "\n\n";

    vector<int> nums3 = {1, 2, 3, 4, 5};
    int target3 = 3;
    cout << "--- Test Case 3 ---\n";
    cout << "Ways to build target: " << solver.findTargetSumWays(nums3, target3) << "\n";

    return 0;
}