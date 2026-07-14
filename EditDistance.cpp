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
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
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

    string word1_1 = "horse";
    string word2_1 = "ros";
    cout << "--- Test Case 1 ---\n";
    cout << "Minimum operations: " << solver.minDistance(word1_1, word2_1) << "\n\n";

    string word1_2 = "intention";
    string word2_2 = "execution";
    cout << "--- Test Case 2 ---\n";
    cout << "Minimum operations: " << solver.minDistance(word1_2, word2_2) << "\n\n";

    string word1_3 = "";
    string word2_3 = "a";
    cout << "--- Test Case 3 ---\n";
    cout << "Minimum operations: " << solver.minDistance(word1_3, word2_3) << "\n";

    return 0;
}