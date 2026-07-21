#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minCut(string s)
    {
        int n = s.length();
        if (n <= 1)
            return 0;

        vector<int> dp(n);
        for (int i = 0; i < n; ++i)
        {
            dp[i] = i;
        }

        for (int mid = 0; mid < n; ++mid)
        {
            for (int start = mid, end = mid; start >= 0 && end < n && s[start] == s[end]; --start, ++end)
            {
                int newCut = (start == 0) ? 0 : dp[start - 1] + 1;
                dp[end] = min(dp[end], newCut);
            }

            for (int start = mid, end = mid + 1; start >= 0 && end < n && s[start] == s[end]; --start, ++end)
            {
                int newCut = (start == 0) ? 0 : dp[start - 1] + 1;
                dp[end] = min(dp[end], newCut);
            }
        }

        return dp[n - 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    string s1 = "aab";
    cout << "--- Test Case 1 ---\n";
    cout << "Minimum Cuts: " << solver.minCut(s1) << "\n\n";

    string s2 = "a";
    cout << "--- Test Case 2 ---\n";
    cout << "Minimum Cuts: " << solver.minCut(s2) << "\n\n";

    string s3 = "ab";
    cout << "--- Test Case 3 ---\n";
    cout << "Minimum Cuts: " << solver.minCut(s3) << "\n";

    return 0;
}