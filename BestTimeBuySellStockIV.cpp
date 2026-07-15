#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.empty() || k == 0)
            return 0;

        if (k >= prices.size() / 2)
        {
            int profit = 0;
            for (size_t i = 1; i < prices.size(); ++i)
            {
                if (prices[i] > prices[i - 1])
                {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }

        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);

        for (int price : prices)
        {
            for (int i = 1; i <= k; ++i)
            {
                buy[i] = max(buy[i], sell[i - 1] - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }

        return sell[k];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int k1 = 2;
    vector<int> prices1 = {2, 4, 1};
    cout << "--- Test Case 1 ---\n";
    cout << "Max Profit: " << solver.maxProfit(k1, prices1) << "\n\n";

    int k2 = 2;
    vector<int> prices2 = {3, 2, 6, 5, 0, 3};
    cout << "--- Test Case 2 ---\n";
    cout << "Max Profit: " << solver.maxProfit(k2, prices2) << "\n\n";

    int k3 = 0;
    vector<int> prices3 = {1, 3};
    cout << "--- Test Case 3 ---\n";
    cout << "Max Profit: " << solver.maxProfit(k3, prices3) << "\n";

    return 0;
}