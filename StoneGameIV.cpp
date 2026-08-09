#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<bool> dp(n + 1, false);

        for (int i = 1; i <= n; ++i)
        {
            for (int k = 1; k * k <= i; ++k)
            {
                if (!dp[i - k * k])
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution solver;

    cout << (solver.winnerSquareGame(1) ? "true" : "false") << "\n";
    cout << (solver.winnerSquareGame(2) ? "true" : "false") << "\n";
    cout << (solver.winnerSquareGame(4) ? "true" : "false") << "\n";

    return 0;
}