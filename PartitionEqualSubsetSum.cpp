#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums)
        {
            for (int i = target; i >= num; --i)
            {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[target];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << boolalpha;

    Solution solver;

    vector<int> nums1 = {1, 5, 11, 5};
    cout << "--- Test Case 1 ---\n";
    cout << "Can partition: " << solver.canPartition(nums1) << "\n\n";

    vector<int> nums2 = {1, 2, 3, 5};
    cout << "--- Test Case 2 ---\n";
    cout << "Can partition: " << solver.canPartition(nums2) << "\n\n";

    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7};
    cout << "--- Test Case 3 ---\n";
    cout << "Can partition: " << solver.canPartition(nums3) << "\n";

    return 0;
}