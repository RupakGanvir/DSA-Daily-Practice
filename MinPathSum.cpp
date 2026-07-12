#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);
        dp[0] = grid[0][0];

        for (int j = 1; j < n; ++j)
        {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; ++i)
        {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j)
            {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }

        return dp[n - 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<vector<int>> grid1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << "--- Test Case 1 ---\n";
    cout << "Minimum Path Sum: " << solver.minPathSum(grid1) << "\n\n";

    vector<vector<int>> grid2 = {{1, 2, 3}, {4, 5, 6}};
    cout << "--- Test Case 2 ---\n";
    cout << "Minimum Path Sum: " << solver.minPathSum(grid2) << "\n";

    return 0;
}