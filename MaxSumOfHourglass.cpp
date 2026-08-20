#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int max_sum = 0;

        for (int i = 0; i < m - 2; ++i)
        {
            for (int j = 0; j < n - 2; ++j)
            {
                int current_sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
                max_sum = max(max_sum, current_sum);
            }
        }

        return max_sum;
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> grid1 = {
        {6, 2, 1, 3},
        {4, 2, 1, 5},
        {9, 2, 8, 7},
        {4, 1, 2, 9}};
    cout << solver.maxSum(grid1) << "\n";

    vector<vector<int>> grid2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    cout << solver.maxSum(grid2) << "\n";

    return 0;
}