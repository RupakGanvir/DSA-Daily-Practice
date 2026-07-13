#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int n1 = 12;
    cout << "--- Test Case 1 ---\n";
    cout << "Minimum perfect squares for " << n1 << ": " << solver.numSquares(n1) << "\n\n";

    int n2 = 13;
    cout << "--- Test Case 2 ---\n";
    cout << "Minimum perfect squares for " << n2 << ": " << solver.numSquares(n2) << "\n\n";

    int n3 = 43;
    cout << "--- Test Case 3 ---\n";
    cout << "Minimum perfect squares for " << n3 << ": " << solver.numSquares(n3) << "\n";

    return 0;
}