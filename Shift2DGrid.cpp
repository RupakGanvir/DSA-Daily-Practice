#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;

        k = k % total;
        if (k == 0)
            return grid;

        vector<vector<int>> res(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int curr = i * n + j;
                int next = (curr + k) % total;
                int next_r = next / n;
                int next_c = next % n;
                res[next_r][next_c] = grid[i][j];
            }
        }

        return res;
    }
};

void printGrid(const vector<vector<int>> &grid)
{
    cout << "[\n";
    for (size_t i = 0; i < grid.size(); ++i)
    {
        cout << "  [";
        for (size_t j = 0; j < grid[i].size(); ++j)
        {
            cout << grid[i][j] << (j == grid[i].size() - 1 ? "" : ", ");
        }
        cout << "]" << (i == grid.size() - 1 ? "" : ",") << "\n";
    }
    cout << "]";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<vector<int>> grid1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k1 = 1;
    cout << "--- Test Case 1 ---\n";
    cout << "Output: \n";
    printGrid(solver.shiftGrid(grid1, k1));
    cout << "\n\n";

    vector<vector<int>> grid2 = {{3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13}};
    int k2 = 4;
    cout << "--- Test Case 2 ---\n";
    cout << "Output: \n";
    printGrid(solver.shiftGrid(grid2, k2));
    cout << "\n\n";

    vector<vector<int>> grid3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k3 = 9;
    cout << "--- Test Case 3 ---\n";
    cout << "Output: \n";
    printGrid(solver.shiftGrid(grid3, k3));
    cout << "\n";

    return 0;
}