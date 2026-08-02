#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<int> dp = piles;

        for (int len = 2; len <= n; ++len)
        {
            for (int i = 0; i <= n - len; ++i)
            {
                int j = i + len - 1;
                dp[i] = max(piles[i] - dp[i + 1], piles[j] - dp[i]);
            }
        }

        return dp[0] > 0;
    }
};

int main()
{
    Solution solver;

    vector<int> piles1 = {5, 3, 4, 5};
    cout << (solver.stoneGame(piles1) ? "true" : "false") << "\n";

    vector<int> piles2 = {3, 7, 2, 3};
    cout << (solver.stoneGame(piles2) ? "true" : "false") << "\n";

    vector<int> piles3 = {1, 10, 100, 1};
    cout << (solver.stoneGame(piles3) ? "true" : "false") << "\n";

    return 0;
}