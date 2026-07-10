#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty())
        {
            int t = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (r == n - 1 && c == n - 1)
                return t;

            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc])
                {
                    visited[nr][nc] = true;
                    pq.push({max(t, grid[nr][nc]), {nr, nc}});
                }
            }
        }

        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<vector<int>> grid1 = {{0, 2}, {1, 3}};
    cout << "--- Test Case 1 ---\n";
    cout << "Minimum time: " << solver.swimInWater(grid1) << "\n\n";

    vector<vector<int>> grid2 = {
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}};
    cout << "--- Test Case 2 ---\n";
    cout << "Minimum time: " << solver.swimInWater(grid2) << "\n";

    return 0;
}