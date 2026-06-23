#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        if (n <= 1)
            return n;

        vector<int> candies(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int totalCandies = 0;
        for (int c : candies)
        {
            totalCandies += c;
        }

        return totalCandies;
    }
};

int main()
{
    Solution solver;

    vector<int> r1 = {1, 0, 2};
    vector<int> r2 = {1, 2, 2};

    cout << "--- Candy Tests ---" << endl;
    cout << "Test 1: " << solver.candy(r1) << endl;
    cout << "Test 2: " << solver.candy(r2) << endl;

    return 0;
}