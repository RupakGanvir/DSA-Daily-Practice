#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = nums[i];
        }

        for (int len = 2; len <= n; ++len)
        {
            for (int i = 0; i <= n - len; ++i)
            {
                int j = i + len - 1;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 5, 2};
    cout << (solver.predictTheWinner(nums1) ? "true" : "false") << "\n";

    vector<int> nums2 = {1, 5, 233, 7};
    cout << (solver.predictTheWinner(nums2) ? "true" : "false") << "\n";

    return 0;
}