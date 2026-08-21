#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int numberOfWays(int n, int x, int y)
    {
        long long mod = 1e9 + 7;

        int max_stages = min(n, x);

        vector<vector<long long>> dp(n + 1, vector<long long>(max_stages + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= min(i, max_stages); ++j)
            {
                long long add_to_existing = (dp[i - 1][j] * j) % mod;
                long long start_new = (dp[i - 1][j - 1] * (x - (j - 1))) % mod;

                dp[i][j] = (add_to_existing + start_new) % mod;
            }
        }

        long long ans = 0;
        long long current_y_pow = 1;

        for (int j = 1; j <= max_stages; ++j)
        {
            current_y_pow = (current_y_pow * y) % mod;
            long long ways = (dp[n][j] * current_y_pow) % mod;
            ans = (ans + ways) % mod;
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    int n1 = 1, x1 = 2, y1 = 3;
    cout << solver.numberOfWays(n1, x1, y1) << "\n";

    int n2 = 5, x2 = 2, y2 = 1;
    cout << solver.numberOfWays(n2, x2, y2) << "\n";

    int n3 = 3, x3 = 3, y3 = 4;
    cout << solver.numberOfWays(n3, x3, y3) << "\n";

    return 0;
}