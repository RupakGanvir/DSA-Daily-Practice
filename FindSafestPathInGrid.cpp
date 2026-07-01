#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return 0;
        }

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (grid[r][c] == 1)
                {
                    q.push(make_pair(r, c));
                    dist[r][c] = 0;
                }
            }
        }

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1)
                {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push(make_pair(nr, nc));
                }
            }
        }

        // Priority Queue stores {safeness, row, col}
        priority_queue<vector<int>> max_heap;
        max_heap.push({dist[0][0], 0, 0});

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        while (!max_heap.empty())
        {
            vector<int> curr = max_heap.top();
            max_heap.pop();

            int current_safe = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (r == n - 1 && c == n - 1)
            {
                return current_safe;
            }

            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc])
                {
                    visited[nr][nc] = true;
                    int new_safe = min(current_safe, dist[nr][nc]);
                    max_heap.push({new_safe, nr, nc});
                }
            }
        }

        return 0;
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> grid1 = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    cout << "Test Case 1 Output: " << solver.maximumSafenessFactor(grid1) << endl;
    return 0;
}