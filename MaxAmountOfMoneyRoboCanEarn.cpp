#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumAmount(vector<vector<int>> &coins)
    {
        int m = coins.size();
        int n = coins[0].size();

        long long INF = 1e15;
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, -INF)));

        if (coins[0][0] >= 0)
        {
            dp[0][0][2] = coins[0][0]; // No neutralization used
        }
        else
        {
            dp[0][0][2] = coins[0][0];
            dp[0][0][1] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k <= 2; k++)
                {
                    if (i == 0 && j == 0)
                        continue;

                    long long prevMax = -INF;
                    if (i > 0)
                        prevMax = max(prevMax, dp[i - 1][j][k]);
                    if (j > 0)
                        prevMax = max(prevMax, dp[i][j - 1][k]);

                    if (prevMax == -INF)
                        continue;

                    if (coins[i][j] >= 0)
                    {
                        dp[i][j][k] = max(dp[i][j][k], prevMax + coins[i][j]);
                    }
                    else
                    {
                        dp[i][j][k] = max(dp[i][j][k], prevMax + coins[i][j]);

                        if (k > 0)
                        {
                            long long prevMaxForNeut = -INF;
                            if (i > 0)
                                prevMaxForNeut = max(prevMaxForNeut, dp[i - 1][j][k]);
                            if (j > 0)
                                prevMaxForNeut = max(prevMaxForNeut, dp[i][j - 1][k]);

                            dp[i][j][k - 1] = max(dp[i][j][k - 1], prevMaxForNeut);
                        }
                    }
                }
            }
        }

        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, -1}, {-1, 1}};
    cout << "Max Profit: " << sol.maximumAmount(grid) << endl;
    return 0;
}