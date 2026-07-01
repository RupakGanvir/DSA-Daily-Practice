#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == 2)
                {
                    q.push(make_pair(i, j));
                }
                else if (grid[i][j] == 1)
                {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0)
            return 0;

        int minutes = 0;
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while (!q.empty())
        {
            int size = q.size();
            bool rottedThisMinute = false;

            for (int i = 0; i < size; ++i)
            {
                pair<int, int> curr = q.front();
                q.pop();

                for (int j = 0; j < 4; ++j)
                {
                    int nr = curr.first + dr[j];
                    int nc = curr.second + dc[j];

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        q.push(make_pair(nr, nc));
                        freshCount--;
                        rottedThisMinute = true;
                    }
                }
            }
            if (rottedThisMinute)
                minutes++;
        }

        return (freshCount == 0) ? minutes : -1;
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};

    cout << "Minutes to rot all: " << solver.orangesRotting(grid) << endl;
    return 0;
}