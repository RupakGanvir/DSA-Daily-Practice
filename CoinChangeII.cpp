#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins)
        {
            for (int i = coin; i <= amount; ++i)
            {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int amount1 = 5;
    vector<int> coins1 = {1, 2, 5};
    cout << "--- Test Case 1 ---\n";
    cout << "Number of combinations: " << solver.change(amount1, coins1) << "\n\n";

    int amount2 = 3;
    vector<int> coins2 = {2};
    cout << "--- Test Case 2 ---\n";
    cout << "Number of combinations: " << solver.change(amount2, coins2) << "\n\n";

    int amount3 = 10;
    vector<int> coins3 = {10};
    cout << "--- Test Case 3 ---\n";
    cout << "Number of combinations: " << solver.change(amount3, coins3) << "\n";

    return 0;
}