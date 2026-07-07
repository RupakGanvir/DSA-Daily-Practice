#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int rows = heights.size();
        int cols = heights[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<vector<int>> efforts(rows, vector<int>(cols, 1e9));

        efforts[0][0] = 0;
        pq.push({0, {0, 0}});

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int currentEffort = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            if (r == rows - 1 && c == cols - 1)
            {
                return currentEffort;
            }

            if (currentEffort > efforts[r][c])
            {
                continue;
            }

            for (int i = 0; i < 4; i++)
            {
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
                {
                    int nextEffort = max(currentEffort, abs(heights[r][c] - heights[nr][nc]));

                    if (nextEffort < efforts[nr][nc])
                    {
                        efforts[nr][nc] = nextEffort;
                        pq.push({nextEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> heights1 = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}};
    cout << "Minimum Effort: " << solver.minimumEffortPath(heights1) << "\n";

    vector<vector<int>> heights2 = {
        {1, 2, 3},
        {3, 8, 4},
        {5, 3, 5}};
    cout << "Minimum Effort: " << solver.minimumEffortPath(heights2) << "\n";

    return 0;
}