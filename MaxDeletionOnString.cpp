#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int deleteString(string s)
    {
        int n = s.length();

        vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = n - 1; j > i; --j)
            {
                if (s[i] == s[j])
                {
                    lcp[i][j] = lcp[i + 1][j + 1] + 1;
                }
            }
        }

        vector<int> dp(n, 1);

        for (int i = n - 1; i >= 0; --i)
        {
            for (int len = 1; i + 2 * len <= n; ++len)
            {
                if (lcp[i][i + len] >= len)
                {
                    dp[i] = max(dp[i], dp[i + len] + 1);
                }
            }
        }

        return dp[0];
    }
};

int main()
{
    Solution solver;

    cout << "Test Case 1 (abcabcdabc): " << solver.deleteString("abcabcdabc") << "\n";
    cout << "Test Case 2 (aaabaab): " << solver.deleteString("aaabaab") << "\n";
    cout << "Test Case 3 (aaaaa): " << solver.deleteString("aaaaa") << "\n";
    cout << "Test Case 4 (a): " << solver.deleteString("a") << "\n";
    cout << "Test Case 5 (abacaba): " << solver.deleteString("abacaba") << "\n";

    return 0;
}