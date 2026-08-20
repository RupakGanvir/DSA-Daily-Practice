#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int max_side = 0;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    max_side = max(max_side, dp[i][j]);
                }
            }
        }

        return max_side * max_side;
    }
};

int main()
{
    Solution solver;

    vector<vector<char>> matrix1 = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    cout << solver.maximalSquare(matrix1) << "\n";

    vector<vector<char>> matrix2 = {
        {'0', '1'},
        {'1', '0'}};
    cout << solver.maximalSquare(matrix2) << "\n";

    vector<vector<char>> matrix3 = {
        {'0'}};
    cout << solver.maximalSquare(matrix3) << "\n";

    return 0;
}