#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;

        dist[0][0] = grid[0][0];
        dq.push_back({0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!dq.empty())
        {
            pair<int, int> curr = dq.front();
            int r = curr.first;
            int c = curr.second;
            dq.pop_front();

            if (r == m - 1 && c == n - 1)
            {
                return dist[r][c] < health;
            }

            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n)
                {
                    int cost = grid[nr][nc];
                    if (dist[r][c] + cost < dist[nr][nc])
                    {
                        dist[nr][nc] = dist[r][c] + cost;
                        if (cost == 0)
                        {
                            dq.push_front({nr, nc});
                        }
                        else
                        {
                            dq.push_back({nr, nc});
                        }
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

    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0}};
    int health = 1;

    bool result = sol.findSafeWalk(grid, health);

    if (result)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}