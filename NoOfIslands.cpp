#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void dfs(vector<vector<char>> &grid, int r, int c, int rows, int cols)
    {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0')
        {
            return;
        }

        grid[r][c] = '0';

        dfs(grid, r - 1, c, rows, cols);
        dfs(grid, r + 1, c, rows, cols);
        dfs(grid, r, c - 1, rows, cols);
        dfs(grid, r, c + 1, rows, cols);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c] == '1')
                {
                    islands++;
                    dfs(grid, r, c, rows, cols);
                }
            }
        }

        return islands;
    }
};

int main()
{
    Solution solver;

    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    cout << "Number of islands: " << solver.numIslands(grid1) << "\n";

    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    cout << "Number of islands: " << solver.numIslands(grid2) << "\n";

    return 0;
}