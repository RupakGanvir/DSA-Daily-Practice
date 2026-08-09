#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int solve(int i, int m, const vector<int> &suf, vector<vector<int>> &memo)
    {
        int n = suf.size();
        if (i + 2 * m >= n)
        {
            return suf[i];
        }
        if (memo[i][m] != 0)
        {
            return memo[i][m];
        }

        int max_stones = 0;
        for (int x = 1; x <= 2 * m; ++x)
        {
            max_stones = max(max_stones, suf[i] - solve(i + x, max(m, x), suf, memo));
        }

        return memo[i][m] = max_stones;
    }

public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        if (n == 0)
            return 0;

        vector<int> suf(n, 0);
        suf[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            suf[i] = suf[i + 1] + piles[i];
        }

        vector<vector<int>> memo(n, vector<int>(n + 1, 0));
        return solve(0, 1, suf, memo);
    }
};

int main()
{
    Solution solver;

    vector<int> piles1 = {2, 7, 9, 4, 4};
    cout << solver.stoneGameII(piles1) << "\n";

    vector<int> piles2 = {1, 2, 3, 4, 5, 100};
    cout << solver.stoneGameII(piles2) << "\n";

    return 0;
}