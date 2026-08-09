#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int solve(int left, int right, const vector<int> &stoneValue, const vector<int> &prefix, vector<vector<int>> &memo)
    {
        if (left == right)
            return 0;
        if (memo[left][right] != -1)
            return memo[left][right];

        int max_score = 0;
        for (int i = left; i < right; ++i)
        {
            int left_sum = prefix[i + 1] - prefix[left];
            int right_sum = prefix[right + 1] - prefix[i + 1];

            if (left_sum < right_sum)
            {
                max_score = max(max_score, left_sum + solve(left, i, stoneValue, prefix, memo));
            }
            else if (left_sum > right_sum)
            {
                max_score = max(max_score, right_sum + solve(i + 1, right, stoneValue, prefix, memo));
            }
            else
            {
                max_score = max(max_score, left_sum + max(solve(left, i, stoneValue, prefix, memo), solve(i + 1, right, stoneValue, prefix, memo)));
            }
        }

        return memo[left][right] = max_score;
    }

public:
    int stoneGameV(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; ++i)
        {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        return solve(0, n - 1, stoneValue, prefix, memo);
    }
};

int main()
{
    Solution solver;

    vector<int> stoneValue1 = {6, 2, 3, 4, 5, 5};
    cout << solver.stoneGameV(stoneValue1) << "\n";

    vector<int> stoneValue2 = {7, 7, 7, 7, 7, 7, 7};
    cout << solver.stoneGameV(stoneValue2) << "\n";

    vector<int> stoneValue3 = {4};
    cout << solver.stoneGameV(stoneValue3) << "\n";

    return 0;
}