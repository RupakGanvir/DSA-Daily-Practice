#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    bool dfs(int r, int c, int pr, int pc, char color, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        visited[r][c] = true;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == color)
            {
                if (visited[nr][nc] && (nr != pr || nc != pc))
                {
                    return true;
                }
                if (!visited[nr][nc])
                {
                    if (dfs(nr, nc, r, c, color, grid, visited))
                        return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!visited[i][j])
                {
                    if (dfs(i, j, -1, -1, grid[i][j], grid, visited))
                        return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> grid = {
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}};

    if (sol.containsCycle(grid))
    {
        cout << "Cycle detected in the grid!" << endl;
    }
    else
    {
        cout << "No cycle found." << endl;
    }

    return 0;
}