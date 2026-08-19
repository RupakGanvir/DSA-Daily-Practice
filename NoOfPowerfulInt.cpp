#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long numberOfPowerfulInt(string start, string finish, int limit, string s)
    {
        auto check = [&](const string &x) -> long long
        {
            if (x.length() < s.length())
                return 0;
            if (x.substr(x.length() - s.length()) != s)
                return 0;
            for (char c : x)
            {
                if (c - '0' > limit)
                    return 0;
            }
            return 1;
        };

        auto count = [&](const string &upper) -> long long
        {
            for (char c : s)
            {
                if (c - '0' > limit)
                    return 0;
            }

            int n = upper.length();
            int m = s.length();
            if (n < m)
                return 0;

            long long ans = 0;
            if (n > m)
            {
                ans += 1;
                long long p = 1;
                for (int len = m + 1; len < n; ++len)
                {
                    ans += limit * p;
                    p *= (limit + 1);
                }
            }

            if (n == m)
            {
                if (s <= upper)
                    ans += 1;
            }
            else
            {
                vector<vector<long long>> dp(n - m + 1, vector<long long>(2, -1));

                auto dfs = [&](auto &self, int idx, bool tight) -> long long
                {
                    if (idx == n - m)
                    {
                        if (tight)
                        {
                            return s <= upper.substr(n - m) ? 1 : 0;
                        }
                        return 1;
                    }
                    if (dp[idx][tight] != -1)
                        return dp[idx][tight];

                    long long sum = 0;
                    int upper_max = tight ? (upper[idx] - '0') : limit;
                    int limit_d = min(limit, upper_max);
                    int start_d = (idx == 0) ? 1 : 0;

                    for (int d = start_d; d <= limit_d; ++d)
                    {
                        sum += self(self, idx + 1, tight && (d == upper[idx] - '0'));
                    }

                    return dp[idx][tight] = sum;
                };

                ans += dfs(dfs, 0, true);
            }
            return ans;
        };

        return count(finish) - count(start) + check(start);
    }
};

int main()
{
    Solution solver;

    string start1 = "1", finish1 = "6000", s1 = "124";
    int limit1 = 4;
    cout << solver.numberOfPowerfulInt(start1, finish1, limit1, s1) << "\n";

    string start2 = "15", finish2 = "215", s2 = "10";
    int limit2 = 6;
    cout << solver.numberOfPowerfulInt(start2, finish2, limit2, s2) << "\n";

    string start3 = "1000", finish3 = "2000", s3 = "3000";
    int limit3 = 4;
    cout << solver.numberOfPowerfulInt(start3, finish3, limit3, s3) << "\n";

    return 0;
}