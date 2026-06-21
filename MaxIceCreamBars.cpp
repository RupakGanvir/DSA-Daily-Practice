#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());

        int iceCreamCount = 0;

        for (int cost : costs)
        {
            if (coins >= cost)
            {
                coins -= cost;
                iceCreamCount++;
            }
            else
            {
                break;
            }
        }

        return iceCreamCount;
    }
};

int main()
{
    Solution solver;

    vector<int> costs1 = {1, 3, 2, 4, 1};
    int coins1 = 7;

    vector<int> costs2 = {10, 6, 8, 7, 7, 8};
    int coins2 = 5;

    vector<int> costs3 = {1, 6, 3, 1, 2, 5};
    int coins3 = 20;

    cout << "--- Maximum Ice Cream Bars Tests ---" << endl;
    cout << "Test 1: " << solver.maxIceCream(costs1, coins1) << endl;
    cout << "Test 2: " << solver.maxIceCream(costs2, coins2) << endl;
    cout << "Test 3: " << solver.maxIceCream(costs3, coins3) << endl;

    return 0;
}