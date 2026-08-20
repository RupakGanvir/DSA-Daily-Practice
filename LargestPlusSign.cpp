#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
    {
        vector<vector<int>> grid(n, vector<int>(n, n));

        for (const auto &mine : mines)
        {
            grid[mine[0]][mine[1]] = 0;
        }

        for (int i = 0; i < n; ++i)
        {
            int left = 0, right = 0, up = 0, down = 0;

            for (int j = 0, k = n - 1; j < n; ++j, --k)
            {

                left = (grid[i][j] == 0 ? 0 : left + 1);
                grid[i][j] = min(grid[i][j], left);

                right = (grid[i][k] == 0 ? 0 : right + 1);
                grid[i][k] = min(grid[i][k], right);

                up = (grid[j][i] == 0 ? 0 : up + 1);
                grid[j][i] = min(grid[j][i], up);

                down = (grid[k][i] == 0 ? 0 : down + 1);
                grid[k][i] = min(grid[k][i], down);
            }
        }

        int max_order = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                max_order = max(max_order, grid[i][j]);
            }
        }

        return max_order;
    }
};

int main()
{
    Solution solver;

    int n1 = 5;
    vector<vector<int>> mines1 = {{4, 2}};
    cout << solver.orderOfLargestPlusSign(n1, mines1) << "\n";

    int n2 = 1;
    vector<vector<int>> mines2 = {{0, 0}};
    cout << solver.orderOfLargestPlusSign(n2, mines2) << "\n";

    return 0;
}