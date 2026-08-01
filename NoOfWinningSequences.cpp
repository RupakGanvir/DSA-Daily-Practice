#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int countWinningSequences(string s)
    {
        int n = s.length();
        int MOD = 1e9 + 7;

        auto get_score = [](char b, char a)
        {
            if (b == a)
                return 0;
            if ((b == 'F' && a == 'E') ||
                (b == 'W' && a == 'F') ||
                (b == 'E' && a == 'W'))
            {
                return 1;
            }
            return -1;
        };

        char moves[] = {'F', 'W', 'E'};

        vector<vector<int>> dp(3, vector<int>(2 * n + 1, 0));

        for (int i = 0; i < 3; ++i)
        {
            int score = get_score(moves[i], s[0]);
            dp[i][n + score] = 1;
        }

        for (int i = 1; i < n; ++i)
        {
            vector<vector<int>> next_dp(3, vector<int>(2 * n + 1, 0));
            for (int last = 0; last < 3; ++last)
            {
                for (int diff = 0; diff <= 2 * n; ++diff)
                {
                    if (dp[last][diff] == 0)
                        continue;

                    for (int curr = 0; curr < 3; ++curr)
                    {
                        if (curr == last)
                            continue;

                        int score = get_score(moves[curr], s[i]);
                        next_dp[curr][diff + score] = (next_dp[curr][diff + score] + dp[last][diff]) % MOD;
                    }
                }
            }
            dp = next_dp;
        }

        long long ans = 0;
        for (int i = 0; i < 3; ++i)
        {
            for (int diff = n + 1; diff <= 2 * n; ++diff)
            {
                ans = (ans + dp[i][diff]) % MOD;
            }
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    cout << solver.countWinningSequences("FFF") << "\n";
    cout << solver.countWinningSequences("FWEW") << "\n";
    cout << solver.countWinningSequences("E") << "\n";

    return 0;
}