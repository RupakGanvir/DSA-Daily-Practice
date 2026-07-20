#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        if (prices.empty())
            return 0;

        int hold = -prices[0];
        int not_hold = 0;

        for (size_t i = 1; i < prices.size(); ++i)
        {
            int next_hold = max(hold, not_hold - prices[i]);
            int next_not_hold = max(not_hold, hold + prices[i] - fee);

            hold = next_hold;
            not_hold = next_not_hold;
        }

        return not_hold;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> prices1 = {1, 3, 2, 8, 4, 9};
    int fee1 = 2;
    cout << "--- Test Case 1 ---\n";
    cout << "Max Profit: " << solver.maxProfit(prices1, fee1) << "\n\n";

    vector<int> prices2 = {1, 3, 7, 5, 10, 3};
    int fee2 = 3;
    cout << "--- Test Case 2 ---\n";
    cout << "Max Profit: " << solver.maxProfit(prices2, fee2) << "\n\n";

    vector<int> prices3 = {9, 8, 7, 1, 2};
    int fee3 = 3;
    cout << "--- Test Case 3 ---\n";
    cout << "Max Profit: " << solver.maxProfit(prices3, fee3) << "\n";

    return 0;
}