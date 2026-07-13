#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int m = str1.length();
        int n = str2.length();

        // dp[i][j] will store the length of the Longest Common Subsequence (LCS)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string result = "";
        int i = m, j = n;

        // Backtrack to find the shortest common supersequence
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                result += str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                result += str1[i - 1];
                i--;
            }
            else
            {
                result += str2[j - 1];
                j--;
            }
        }

        // Add remaining characters from str1
        while (i > 0)
        {
            result += str1[i - 1];
            i--;
        }

        // Add remaining characters from str2
        while (j > 0)
        {
            result += str2[j - 1];
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    string str1_1 = "abac";
    string str2_1 = "cab";
    cout << "--- Test Case 1 ---\n";
    cout << "Shortest Common Supersequence: " << solver.shortestCommonSupersequence(str1_1, str2_1) << "\n\n";

    string str1_2 = "aaaaaaaa";
    string str2_2 = "aaaaaaaa";
    cout << "--- Test Case 2 ---\n";
    cout << "Shortest Common Supersequence: " << solver.shortestCommonSupersequence(str1_2, str2_2) << "\n\n";

    string str1_3 = "bbbaaaba";
    string str2_3 = "bbababbb";
    cout << "--- Test Case 3 ---\n";
    cout << "Shortest Common Supersequence: " << solver.shortestCommonSupersequence(str1_3, str2_3) << "\n";

    return 0;
}