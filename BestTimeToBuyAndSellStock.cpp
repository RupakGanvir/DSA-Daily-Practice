#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            // If we find a new lower price, update our "buy" day
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            // Otherwise, calculate potential profit and keep the maximum
            else
            {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }
        return maxProfit;
    }
};

int main()
{
    Solution sol;

    // Test Case: Buy at 1 (index 1), Sell at 6 (index 4), Profit = 5
    vector<int> stockPrices = {7, 1, 5, 3, 6, 4};

    int result = sol.maxProfit(stockPrices);

    cout << "Stock Prices: ";
    for (int p : stockPrices)
        cout << p << " ";
    cout << "\nMaximum Profit: " << result << endl;

    return 0;
}