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
        int buy1 = INT_MIN;
        int sell1 = 0;
        int buy2 = INT_MIN;
        int sell2 = 0;

        for (int price : prices)
        {
            buy1 = max(buy1, -price);
            sell1 = max(sell1, buy1 + price);
            buy2 = max(buy2, sell1 - price);
            sell2 = max(sell2, buy2 + price);
        }

        return sell2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> prices1 = {3, 3, 5, 0, 0, 3, 1, 4};
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