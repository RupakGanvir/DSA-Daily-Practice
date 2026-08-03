#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        vector<int> dp(n + 1, -1e9);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; --i)
        {
            int take = 0;
            for (int k = 1; k <= 3 && i + k - 1 < n; ++k)
            {
                take += stoneValue[i + k - 1];
                dp[i] = max(dp[i], take - dp[i + k]);
            }
        }

        if (dp[0] > 0)
            return "Alice";
        if (dp[0] < 0)
            return "Bob";
        return "Tie";
    }
};

int main()
{
    Solution solver;

    vector<int> stoneValue1 = {1, 2, 3, 7};
    cout << "\"" << solver.stoneGameIII(stoneValue1) << "\"\n";

    vector<int> stoneValue2 = {1, 2, 3, -9};
    cout << "\"" << solver.stoneGameIII(stoneValue2) << "\"\n";

    vector<int> stoneValue3 = {1, 2, 3, 6};
    cout << "\"" << solver.stoneGameIII(stoneValue3) << "\"\n";

    return 0;
}