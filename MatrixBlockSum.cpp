#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();

        // 2D Prefix Sum Array
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                pref[i][j] = mat[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int r1 = max(0, i - k);
                int c1 = max(0, j - k);
                int r2 = min(m - 1, i + k);
                int c2 = min(n - 1, j + k);

                // Using inclusion-exclusion principle to get the sum of the subgrid
                ans[i][j] = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
            }
        }

        return ans;
    }
};

void printMatrix(const vector<vector<int>> &mat)
{
    cout << "[\n";
    for (size_t i = 0; i < mat.size(); ++i)
    {
        cout << "  [";
        for (size_t j = 0; j < mat[i].size(); ++j)
        {
            cout << mat[i][j] << (j + 1 == mat[i].size() ? "" : ", ");
        }
        cout << "]" << (i + 1 == mat.size() ? "" : ",") << "\n";
    }
    cout << "]\n";
}

int main()
{
    Solution solver;

    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int k1 = 1;
    printMatrix(solver.matrixBlockSum(mat1, k1));

    vector<vector<int>> mat2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int k2 = 2;
    printMatrix(solver.matrixBlockSum(mat2, k2));

    return 0;
}