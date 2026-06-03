#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    bool canFinish(const vector<int> &piles, int h, int k)
    {
        long long hours_needed = 0;

        for (int i = 0; i < piles.size(); i++)
        {
            hours_needed += piles[i] / k;

            if (piles[i] % k != 0)
            {
                hours_needed++;
            }
        }

        return hours_needed <= h;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1;

        int right = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            right = max(right, piles[i]);
        }

        int best_speed = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (canFinish(piles, h, mid))
            {
                best_speed = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return best_speed;
    }
};

int main()
{
    Solution solver;

    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;

    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;

    vector<int> piles3 = {30, 11, 23, 4, 20};
    int h3 = 6;

    cout << "--- Koko Eating Bananas Tests ---" << endl;
    cout << "Test 1 (Expected 4):  " << solver.minEatingSpeed(piles1, h1) << endl;
    cout << "Test 2 (Expected 30): " << solver.minEatingSpeed(piles2, h2) << endl;
    cout << "Test 3 (Expected 23): " << solver.minEatingSpeed(piles3, h3) << endl;

    return 0;
}