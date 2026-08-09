#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; ++i)
        {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        vector<int> dp(n, 0);

        for (int len = 2; len <= n; ++len)
        {
            for (int i = 0; i <= n - len; ++i)
            {
                int j = i + len - 1;
                dp[i] = max(prefix[j + 1] - prefix[i + 1] - dp[i + 1],
                            prefix[j] - prefix[i] - dp[i]);
            }
        }

        return dp[0];
    }
};

int main()
{
    Solution solver;

    vector<int> stones1 = {5, 3, 1, 4, 2};
    cout << solver.stoneGameVII(stones1) << "\n";

    vector<int> stones2 = {7, 90, 5, 1, 100, 10, 10, 2};
    cout << solver.stoneGameVII(stones2) << "\n";

    return 0;
}