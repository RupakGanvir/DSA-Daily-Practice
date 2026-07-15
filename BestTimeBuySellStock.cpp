#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "--- Test Case 1 ---\n";
    cout << "Max Profit: " << solver.maxProfit(prices1) << "\n\n";

    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "--- Test Case 2 ---\n";
    cout << "Max Profit: " << solver.maxProfit(prices2) << "\n\n";

    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "--- Test Case 3 ---\n";
    cout << "Max Profit: " << solver.maxProfit(prices3) << "\n";

    return 0;
}