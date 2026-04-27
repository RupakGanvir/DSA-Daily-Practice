#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution
{
public:
    // Define outlets for each pipe type: {row_offset, col_offset}
    // 1: left, right | 2: up, down | 3: left, down | 4: right, down | 5: left, up | 6: right, up
    map<int, vector<pair<int, int>>> pipes = {
        {1, {{0, -1}, {0, 1}}},
        {2, {{-1, 0}, {1, 0}}},
        {3, {{0, -1}, {1, 0}}},
        {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}},
        {6, {{0, 1}, {-1, 0}}}};

    bool hasValidPath(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            int r = curr.first;
            int c = curr.second;
            q.pop();

            if (r == m - 1 && c == n - 1)
                return true;

            int currentType = grid[r][c];
            for (auto &dir : pipes[currentType])
            {
                int nr = r + dir.first;
                int nc = c + dir.second;

                // 1. Bounds check
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc])
                {
                    // 2. Connectivity check: Does the next pipe have an outlet back to us?
                    int nextType = grid[nr][nc];
                    bool backConnect = false;
                    for (auto &backDir : pipes[nextType])
                    {
                        if (nr + backDir.first == r && nc + backDir.second == c)
                        {
                            backConnect = true;
                            break;
                        }
                    }

                    if (backConnect)
                    {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{2, 4, 3}, {6, 5, 2}};
    cout << (sol.hasValidPath(grid) ? "Valid Path Exists" : "No Valid Path") << endl;
    return 0;
}