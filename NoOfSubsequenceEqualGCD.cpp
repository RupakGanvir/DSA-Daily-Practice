#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int get_gcd(int a, int b)
    {
        while (b)
        {
            a %= b;
            swap(a, b);
        }
        return a;
    }

public:
    int subsequencePairCount(vector<int> &nums)
    {
        int max_num = 0;
        for (int x : nums)
        {
            max_num = max(max_num, x);
        }

        int MOD = 1e9 + 7;

        vector<vector<int>> dp(max_num + 1, vector<int>(max_num + 1, 0));
        dp[0][0] = 1;

        for (int x : nums)
        {
            vector<vector<int>> next_dp = dp;

            for (int g1 = 0; g1 <= max_num; ++g1)
            {
                for (int g2 = 0; g2 <= max_num; ++g2)
                {
                    if (dp[g1][g2] == 0)
                        continue;

                    int ng1 = get_gcd(g1, x);
                    next_dp[ng1][g2] = (next_dp[ng1][g2] + dp[g1][g2]) % MOD;

                    int ng2 = get_gcd(g2, x);
                    next_dp[g1][ng2] = (next_dp[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }
            dp = next_dp;
        }

        int ans = 0;
        for (int g = 1; g <= max_num; ++g)
        {
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> nums1 = {1, 2, 3, 4};
    cout << "--- Test Case 1 ---\n";
    cout << "Output: " << solver.subsequencePairCount(nums1) << "\n\n";

    vector<int> nums2 = {10, 20, 30};
    cout << "--- Test Case 2 ---\n";
    cout << "Output: " << solver.subsequencePairCount(nums2) << "\n\n";

    vector<int> nums3 = {1, 1, 1, 1};
    cout << "--- Test Case 3 ---\n";
    cout << "Output: " << solver.subsequencePairCount(nums3) << "\n";

    return 0;
}