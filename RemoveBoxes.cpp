#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int solve(vector<int> &boxes, int l, int r, int k, vector<vector<vector<int>>> &memo)
    {
        if (l > r)
            return 0;

        if (memo[l][r][k] != 0)
            return memo[l][r][k];

        int orig_l = l, orig_k = k;

        while (l + 1 <= r && boxes[l] == boxes[l + 1])
        {
            l++;
            k++;
        }

        int res = (k + 1) * (k + 1) + solve(boxes, l + 1, r, 0, memo);

        for (int i = l + 1; i <= r; ++i)
        {
            if (boxes[i] == boxes[l])
            {
                res = max(res, solve(boxes, l + 1, i - 1, 0, memo) + solve(boxes, i, r, k + 1, memo));
            }
        }

        return memo[orig_l][r][orig_k] = res;
    }

public:
    int removeBoxes(vector<int> &boxes)
    {
        int n = boxes.size();
        if (n == 0)
            return 0;

        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n, 0)));
        return solve(boxes, 0, n - 1, 0, memo);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> boxes1 = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    cout << "--- Test Case 1 ---\n";
    cout << "Maximum Points: " << solver.removeBoxes(boxes1) << "\n\n";

    vector<int> boxes2 = {1, 1, 1};
    cout << "--- Test Case 2 ---\n";
    cout << "Maximum Points: " << solver.removeBoxes(boxes2) << "\n\n";

    vector<int> boxes3 = {1};
    cout << "--- Test Case 3 ---\n";
    cout << "Maximum Points: " << solver.removeBoxes(boxes3) << "\n";

    return 0;
}