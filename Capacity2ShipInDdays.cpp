#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
private:
    bool canShip(const vector<int> &weights, int days, int capacity)
    {
        int days_needed = 1;
        int current_load = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            if (current_load + weights[i] > capacity)
            {
                days_needed++;

                current_load = weights[i];
            }
            else
            {
                current_load += weights[i];
            }
        }

        return days_needed <= days;
    }

public:
    int minShipCapacity(vector<int> &weights, int days)
    {
        int left = 0;
        for (int w : weights)
        {
            left = max(left, w);
        }

        int right = 0;
        for (int w : weights)
        {
            right += w;
        }

        int best_capacity = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (canShip(weights, days, mid))
            {
                best_capacity = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return best_capacity;
    }
};

int main()
{
    Solution solver;

    vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days1 = 5;

    vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    int days2 = 3;

    vector<int> weights3 = {1, 2, 3, 1, 1};
    int days3 = 4;

    cout << "--- Capacity To Ship Packages Tests ---" << endl;
    cout << "Test 1 : " << solver.minShipCapacity(weights1, days1) << endl;
    cout << "Test 2 :  " << solver.minShipCapacity(weights2, days2) << endl;
    cout << "Test 3 :  " << solver.minShipCapacity(weights3, days3) << endl;

    return 0;
}