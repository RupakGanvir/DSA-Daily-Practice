#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost)
    {
        long long low = 0;
        long long high = 2e8;
        long long max_alloys = 0;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            bool possible = false;

            for (int i = 0; i < k; ++i)
            {
                long long current_cost = 0;
                for (int j = 0; j < n; ++j)
                {
                    long long required = mid * composition[i][j];
                    if (required > stock[j])
                    {
                        current_cost += (required - stock[j]) * cost[j];
                    }
                    if (current_cost > budget)
                    {
                        break;
                    }
                }

                if (current_cost <= budget)
                {
                    possible = true;
                    break;
                }
            }

            if (possible)
            {
                max_alloys = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return max_alloys;
    }
};

int main()
{
    Solution solver;

    int n1 = 3, k1 = 2, budget1 = 15;
    vector<vector<int>> comp1 = {{1, 1, 1}, {1, 1, 10}};
    vector<int> stock1 = {0, 0, 0};
    vector<int> cost1 = {1, 2, 3};
    cout << solver.maxNumberOfAlloys(n1, k1, budget1, comp1, stock1, cost1) << "\n";

    int n2 = 3, k2 = 2, budget2 = 15;
    vector<vector<int>> comp2 = {{1, 1, 1}, {1, 1, 10}};
    vector<int> stock2 = {0, 0, 100};
    vector<int> cost2 = {1, 2, 3};
    cout << solver.maxNumberOfAlloys(n2, k2, budget2, comp2, stock2, cost2) << "\n";

    int n3 = 2, k3 = 3, budget3 = 10;
    vector<vector<int>> comp3 = {{2, 1}, {1, 2}, {1, 1}};
    vector<int> stock3 = {1, 1};
    vector<int> cost3 = {5, 5};
    cout << solver.maxNumberOfAlloys(n3, k3, budget3, comp3, stock3, cost3) << "\n";

    return 0;
}