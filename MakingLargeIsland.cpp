#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> islandSizes = {0, 0};
        int islandId = 2;
        int maxIsland = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        auto dfs = [&](auto &self, int r, int c, int id) -> int
        {
            grid[r][c] = id;
            int size = 1;
            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1)
                {
                    size += self(self, nr, nc, id);
                }
            }
            return size;
        };

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    int size = dfs(dfs, i, j, islandId);
                    islandSizes.push_back(size);
                    maxIsland = max(maxIsland, size);
                    islandId++;
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                {
                    int possibleSize = 1;
                    unordered_set<int> neighborIds;
                    for (int k = 0; k < 4; ++k)
                    {
                        int ni = i + dr[k];
                        int nj = j + dc[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1)
                        {
                            neighborIds.insert(grid[ni][nj]);
                        }
                    }
                    for (int id : neighborIds)
                    {
                        possibleSize += islandSizes[id];
                    }
                    maxIsland = max(maxIsland, possibleSize);
                }
            }
        }

        return maxIsland;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<vector<int>> grid1 = {{1, 0}, {0, 1}};
    cout << "--- Test Case 1 ---\n";
    cout << "Largest Island Size: " << solver.largestIsland(grid1) << "\n\n";

    vector<vector<int>> grid2 = {{1, 1}, {1, 0}};
    cout << "--- Test Case 2 ---\n";
    cout << "Largest Island Size: " << solver.largestIsland(grid2) << "\n\n";

    vector<vector<int>> grid3 = {{1, 1}, {1, 1}};
    cout << "--- Test Case 3 ---\n";
    cout << "Largest Island Size: " << solver.largestIsland(grid3) << "\n";

    return 0;
}