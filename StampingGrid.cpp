#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool possibleToStamp(vector<vector<int>> &grid, int stampHeight, int stampWidth)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                pref[i][j] = grid[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }

        vector<vector<int>> diff(m + 2, vector<int>(n + 2, 0));

        for (int i = stampHeight; i <= m; ++i)
        {
            for (int j = stampWidth; j <= n; ++j)
            {
                int r1 = i - stampHeight + 1;
                int c1 = j - stampWidth + 1;
                int r2 = i;
                int c2 = j;

                int sum = pref[r2][c2] - pref[r1 - 1][c2] - pref[r2][c1 - 1] + pref[r1 - 1][c1 - 1];

                if (sum == 0)
                {
                    diff[r1][c1] += 1;
                    diff[r2 + 1][c1] -= 1;
                    diff[r1][c2 + 1] -= 1;
                    diff[r2 + 1][c2 + 1] += 1;
                }
            }
        }

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];

                if (grid[i - 1][j - 1] == 0 && diff[i][j] == 0)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> grid1 = {
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0}};
    int stampHeight1 = 4;
    int stampWidth1 = 3;
    cout << (solver.possibleToStamp(grid1, stampHeight1, stampWidth1) ? "true" : "false") << "\n";

    vector<vector<int>> grid2 = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}};
    int stampHeight2 = 2;
    int stampWidth2 = 2;
    cout << (solver.possibleToStamp(grid2, stampHeight2, stampWidth2) ? "true" : "false") << "\n";

    return 0;
}