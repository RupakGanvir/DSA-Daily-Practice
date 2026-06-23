#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    int zigZagArrays(int n, int l, int r)
    {
        long long MOD = 1000000007;
        int m = r - l + 1;
        vector<long long> dp(m, 1);

        for (int i = 1; i < n; i++)
        {
            long long pre = 0;
            if (i % 2 == 1)
            {
                for (int v = 0; v < m; v++)
                {
                    long long next_pre = (pre + dp[v]) % MOD;
                    dp[v] = pre;
                    pre = next_pre;
                }
            }
            else
            {
                for (int v = m - 1; v >= 0; v--)
                {
                    long long next_pre = (pre + dp[v]) % MOD;
                    dp[v] = pre;
                    pre = next_pre;
                }
            }
        }

        long long total_sum = 0;
        for (long long val : dp)
        {
            total_sum = (total_sum + val) % MOD;
        }

        return (total_sum * 2) % MOD;
    }
};

int main()
{
    Solution solver;

    cout << "--- Number of ZigZag Arrays Tests ---" << endl;
    cout << "Test 1: " << solver.zigZagArrays(3, 4, 5) << endl;
    cout << "Test 2: " << solver.zigZagArrays(3, 1, 3) << endl;

    return 0;
}