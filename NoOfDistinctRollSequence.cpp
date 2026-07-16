#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int getGcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    int distinctSequences(int n)
    {
        if (n == 1)
            return 6;

        int MOD = 1e9 + 7;
        vector<vector<long long>> dp(7, vector<long long>(7, 0));

        for (int i = 1; i <= 6; ++i)
        {
            for (int j = 1; j <= 6; ++j)
            {
                if (i != j && getGcd(i, j) == 1)
                {
                    dp[i][j] = 1;
                }
            }
        }

        for (int len = 3; len <= n; ++len)
        {
            vector<vector<long long>> next_dp(7, vector<long long>(7, 0));

            for (int curr = 1; curr <= 6; ++curr)
            {
                for (int prev = 1; prev <= 6; ++prev)
                {
                    if (curr == prev || getGcd(curr, prev) != 1)
                        continue;

                    for (int prevprev = 1; prevprev <= 6; ++prevprev)
                    {
                        if (curr == prevprev || prev == prevprev || getGcd(prev, prevprev) != 1)
                            continue;

                        next_dp[curr][prev] = (next_dp[curr][prev] + dp[prev][prevprev]) % MOD;
                    }
                }
            }
            dp = next_dp;
        }

        long long ans = 0;
        for (int i = 1; i <= 6; ++i)
        {
            for (int j = 1; j <= 6; ++j)
            {
                ans = (ans + dp[i][j]) % MOD;
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int n1 = 4;
    cout << "--- Test Case 1 ---\n";
    cout << "Distinct Sequences: " << solver.distinctSequences(n1) << "\n\n";

    int n2 = 2;
    cout << "--- Test Case 2 ---\n";
    cout << "Distinct Sequences: " << solver.distinctSequences(n2) << "\n\n";

    int n3 = 1;
    cout << "--- Test Case 3 ---\n";
    cout << "Distinct Sequences: " << solver.distinctSequences(n3) << "\n";

    return 0;
}