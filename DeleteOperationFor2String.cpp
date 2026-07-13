#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = i + j;
                }
                else if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    string word1_1 = "sea";
    string word2_1 = "eat";
    cout << "--- Test Case 1 ---\n";
    cout << "Minimum operations: " << solver.minDistance(word1_1, word2_1) << "\n\n";

    string word1_2 = "leetcode";
    string word2_2 = "etco";
    cout << "--- Test Case 2 ---\n";
    cout << "Minimum operations: " << solver.minDistance(word1_2, word2_2) << "\n\n";

    string word1_3 = "a";
    string word2_3 = "b";
    cout << "--- Test Case 3 ---\n";
    cout << "Minimum operations: " << solver.minDistance(word1_3, word2_3) << "\n";

    return 0;
}