#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int countPalindromes(string s)
    {
        int n = s.length();
        if (n < 5)
            return 0;

        long long MOD = 1e9 + 7;

        vector<vector<vector<long long>>> suf(n, vector<vector<long long>>(10, vector<long long>(10, 0)));
        vector<long long> suf_cnt(10, 0);

        for (int i = n - 1; i >= 0; --i)
        {
            int c = s[i] - '0';
            if (i < n - 1)
            {
                for (int j = 0; j < 10; ++j)
                {
                    for (int k = 0; k < 10; ++k)
                    {
                        suf[i][j][k] = suf[i + 1][j][k];
                    }
                }
                for (int d = 0; d < 10; ++d)
                {
                    suf[i][c][d] = (suf[i][c][d] + suf_cnt[d]) % MOD;
                }
            }
            suf_cnt[c]++;
        }

        vector<vector<long long>> pre(10, vector<long long>(10, 0));
        vector<long long> pre_cnt(10, 0);
        long long ans = 0;

        for (int i = 0; i < n; ++i)
        {
            int c = s[i] - '0';

            if (i >= 2 && i <= n - 3)
            {
                for (int j = 0; j < 10; ++j)
                {
                    for (int k = 0; k < 10; ++k)
                    {
                        ans = (ans + pre[j][k] * suf[i + 1][k][j]) % MOD;
                    }
                }
            }

            for (int d = 0; d < 10; ++d)
            {
                pre[d][c] = (pre[d][c] + pre_cnt[d]) % MOD;
            }
            pre_cnt[c]++;
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    cout << solver.countPalindromes("103301") << "\n";
    cout << solver.countPalindromes("0000000") << "\n";
    cout << solver.countPalindromes("9999900000") << "\n";

    return 0;
}