#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int strangePrinter(string s)
    {
        int n = s.length();
        if (n == 0)
            return 0;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; --i)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = INT_MAX;
                    for (int k = i; k < j; ++k)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    string s1 = "aaabbb";
    cout << "--- Test Case 1 ---\n";
    cout << "Minimum Turns: " << solver.strangePrinter(s1) << "\n\n";

    string s2 = "aba";
    cout << "--- Test Case 2 ---\n";
    cout << "Minimum Turns: " << solver.strangePrinter(s2) << "\n\n";

    string s3 = "abcabc";
    cout << "--- Test Case 3 ---\n";
    cout << "Minimum Turns: " << solver.strangePrinter(s3) << "\n";

    return 0;
}