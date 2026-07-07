#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
private:
    int bfs(vector<vector<int>> &grid, int n)
    {
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return -1;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int steps = 1;
        int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                pair<int, int> curr = q.front();
                q.pop();

                int r = curr.first;
                int c = curr.second;

                if (r == n - 1 && c == n - 1)
                {
                    return steps;
                }

                for (int i = 0; i < 8; i++)
                {
                    int nr = r + directions[i][0];
                    int nc = c + directions[i][1];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0)
                    {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            steps++;
        }

        return -1;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return -1;

        int n = grid.size();
        return bfs(grid, n);
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> grid1 = {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}};
    cout << "Shortest Path Length: " << solver.shortestPathBinaryMatrix(grid1) << "\n";

    vector<vector<int>> grid2 = {
        {0, 1},
        {1, 0}};
    cout << "Shortest Path Length: " << solver.shortestPathBinaryMatrix(grid2) << "\n";

    return 0;
}