#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long maximumProfit(vector<int> &prices, int k)
    {
        if (prices.empty() || k == 0)
            return 0;

        const long long INF = 1e15;
        vector<vector<long long>> dp(k + 1, vector<long long>(3, -INF));

        for (int j = 0; j <= k; ++j)
        {
            dp[j][0] = 0;
        }

        for (long long price : prices)
        {
            for (int j = k; j >= 1; --j)
            {
                long long old_1 = dp[j][1];
                long long old_2 = dp[j][2];
                long long prev_0 = dp[j - 1][0];

                dp[j][0] = max({dp[j][0], old_1 + price, old_2 - price});
                dp[j][1] = max(old_1, prev_0 - price);
                dp[j][2] = max(old_2, prev_0 + price);
            }
        }

        return dp[k][0];
    }
};

int main()
{
    Solution solver;

    vector<int> prices1 = {1, 7, 9, 8, 2};
    int k1 = 2;
    cout << solver.maximumProfit(prices1, k1) << "\n";

    vector<int> prices2 = {12, 16, 19, 19, 8, 1, 19, 13, 9};
    int k2 = 3;
    cout << solver.maximumProfit(prices2, k2) << "\n";

    return 0;
}