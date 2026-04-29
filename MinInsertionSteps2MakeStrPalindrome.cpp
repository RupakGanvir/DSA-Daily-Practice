#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    int minInsertions(std::string s)
    {
        int n = s.length();
        std::string r = s;
        std::reverse(r.begin(), r.end());

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == r[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return n - dp[n][n];
    }
};

int main()
{
    Solution sol;
    std::string test = "leetcode";

    std::cout << "Input: " << test << "\n";
    std::cout << "Minimum Insertions: " << sol.minInsertions(test) << std::endl;

    return 0;
}