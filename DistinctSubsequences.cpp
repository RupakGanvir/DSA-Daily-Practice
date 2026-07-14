#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();

        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = n; j >= 1; --j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    string s1 = "rabbbit";
    string t1 = "rabbit";
    cout << "--- Test Case 1 ---\n";
    cout << "Distinct Subsequences: " << solver.numDistinct(s1, t1) << "\n\n";

    string s2 = "babgbag";
    string t2 = "bag";
    cout << "--- Test Case 2 ---\n";
    cout << "Distinct Subsequences: " << solver.numDistinct(s2, t2) << "\n\n";

    string s3 = "abc";
    string t3 = "def";
    cout << "--- Test Case 3 ---\n";
    cout << "Distinct Subsequences: " << solver.numDistinct(s3, t3) << "\n";

    return 0;
}