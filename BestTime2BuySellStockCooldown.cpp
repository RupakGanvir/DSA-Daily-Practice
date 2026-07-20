#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;

        int hold = -prices[0];
        int sold = 0;
        int rest = 0;

        for (size_t i = 1; i < prices.size(); ++i)
        {
            int next_hold = max(hold, rest - prices[i]);
            int next_sold = hold + prices[i];
            int next_rest = max(rest, sold);

            hold = next_hold;
            sold = next_sold;
            rest = next_rest;
        }

        return max(sold, rest);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> prices1 = {1, 2, 3, 0, 2};
    cout << "--- Test Case 1 ---\n";
    cout << "Max Profit: " << solver.maxProfit(prices1) << "\n\n";

    vector<int> prices2 = {1};
    cout << "--- Test Case 2 ---\n";
    cout << "Max Profit: " << solver.maxProfit(prices2) << "\n\n";

    vector<int> prices3 = {1, 2, 4};
    cout << "--- Test Case 3 ---\n";
    cout << "Max Profit: " << solver.maxProfit(prices3) << "\n";

    return 0;
}