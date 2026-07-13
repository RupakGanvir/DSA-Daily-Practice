#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; --i)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
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

    string s1 = "bbbab";
    cout << "--- Test Case 1 ---\n";
    cout << "Longest Palindromic Subsequence length: " << solver.longestPalindromeSubseq(s1) << "\n\n";

    string s2 = "cbbd";
    cout << "--- Test Case 2 ---\n";
    cout << "Longest Palindromic Subsequence length: " << solver.longestPalindromeSubseq(s2) << "\n\n";

    string s3 = "a";
    cout << "--- Test Case 3 ---\n";
    cout << "Longest Palindromic Subsequence length: " << solver.longestPalindromeSubseq(s3) << "\n";

    return 0;
}