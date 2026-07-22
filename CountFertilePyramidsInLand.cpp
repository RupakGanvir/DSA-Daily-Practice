#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int countPyramids(vector<vector<int>> &grid)
    {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();

        auto count = [&](vector<vector<int>> g)
        {
            int total = 0;
            for (int i = m - 2; i >= 0; --i)
            {
                for (int j = 1; j < n - 1; ++j)
                {
                    if (g[i][j] > 0 && g[i + 1][j - 1] > 0 && g[i + 1][j] > 0 && g[i + 1][j + 1] > 0)
                    {
                        g[i][j] = 1 + min({g[i + 1][j - 1], g[i + 1][j], g[i + 1][j + 1]});
                        total += g[i][j] - 1;
                    }
                }
            }
            return total;
        };

        int ans = count(grid);

        vector<vector<int>> reversedGrid = grid;
        reverse(reversedGrid.begin(), reversedGrid.end());
        ans += count(reversedGrid);

        return ans;
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> grid1 = {
        {0, 1, 1, 0},
        {1, 1, 1, 1}};
    cout << solver.countPyramids(grid1) << "\n";

    vector<vector<int>> grid2 = {
        {1, 1, 1},
        {1, 1, 1}};
    cout << solver.countPyramids(grid2) << "\n";

    vector<vector<int>> grid3 = {
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 0, 1}};
    cout << solver.countPyramids(grid3) << "\n";

    vector<vector<int>> grid4 = {
        {1, 0, 1},
        {0, 0, 0},
        {1, 0, 1}};
    cout << solver.countPyramids(grid4) << "\n";

    vector<vector<int>> grid5 = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}};
    cout << solver.countPyramids(grid5) << "\n";

    return 0;
}