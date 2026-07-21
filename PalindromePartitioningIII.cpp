#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int palindromePartition(string s, int k)
    {
        int n = s.length();
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int len = 2; len <= n; ++len)
        {
            for (int i = 0; i <= n - len; ++i)
            {
                int j = i + len - 1;
                cost[i][j] = cost[i + 1][j - 1] + (s[i] == s[j] ? 0 : 1);
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(n, 1e5));

        for (int i = 0; i < n; ++i)
        {
            dp[1][i] = cost[0][i];
        }

        for (int p = 2; p <= k; ++p)
        {
            for (int i = p - 1; i < n; ++i)
            {
                for (int j = p - 2; j < i; ++j)
                {
                    dp[p][i] = min(dp[p][i], dp[p - 1][j] + cost[j + 1][i]);
                }
            }
        }

        return dp[k][n - 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    string s1 = "abc";
    int k1 = 2;
    cout << "--- Test Case 1 ---\n";
    cout << "Output: " << solver.palindromePartition(s1, k1) << "\n\n";

    string s2 = "aabbc";
    int k2 = 3;
    cout << "--- Test Case 2 ---\n";
    cout << "Output: " << solver.palindromePartition(s2, k2) << "\n\n";

    string s3 = "leetcode";
    int k3 = 8;
    cout << "--- Test Case 3 ---\n";
    cout << "Output: " << solver.palindromePartition(s3, k3) << "\n";

    return 0;
}