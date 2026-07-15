#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr(n + 2, 1);
        for (int i = 0; i < n; ++i)
        {
            arr[i + 1] = nums[i];
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 2; len <= n + 1; ++len)
        {
            for (int i = 0; i <= n + 1 - len; ++i)
            {
                int j = i + len;
                for (int k = i + 1; k < j; ++k)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j]);
                }
            }
        }

        return dp[0][n + 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> nums1 = {3, 1, 5, 8};
    cout << "--- Test Case 1 ---\n";
    cout << "Max Coins: " << solver.maxCoins(nums1) << "\n\n";

    vector<int> nums2 = {1, 5};
    cout << "--- Test Case 2 ---\n";
    cout << "Max Coins: " << solver.maxCoins(nums2) << "\n\n";

    vector<int> nums3 = {4, 2, 3, 7};
    cout << "--- Test Case 3 ---\n";
    cout << "Max Coins: " << solver.maxCoins(nums3) << "\n";

    return 0;
}