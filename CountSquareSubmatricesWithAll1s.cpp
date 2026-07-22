#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int rowCount = matrix.size();
        if (rowCount == 0)
        {
            return 0;
        }

        int colCount = matrix[0].size();
        int totalSquares = 0;

        vector<vector<int>> squareSizes(rowCount, vector<int>(colCount, 0));

        for (int row = 0; row < rowCount; ++row)
        {
            for (int col = 0; col < colCount; ++col)
            {
                if (matrix[row][col] == 1)
                {
                    if (row == 0 || col == 0)
                    {
                        squareSizes[row][col] = 1;
                    }
                    else
                    {
                        squareSizes[row][col] = min({squareSizes[row - 1][col],
                                                     squareSizes[row][col - 1],
                                                     squareSizes[row - 1][col - 1]}) +
                                                1;
                    }
                    totalSquares += squareSizes[row][col];
                }
            }
        }

        return totalSquares;
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> matrix1 = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}};
    cout << solver.countSquares(matrix1) << "\n";

    vector<vector<int>> matrix2 = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 0}};
    cout << solver.countSquares(matrix2) << "\n";

    vector<vector<int>> matrix3 = {
        {0, 0, 0},
        {0, 0, 0}};
    cout << solver.countSquares(matrix3) << "\n";

    vector<vector<int>> matrix4 = {
        {1, 1},
        {1, 1}};
    cout << solver.countSquares(matrix4) << "\n";

    vector<vector<int>> matrix5 = {
        {1}};
    cout << solver.countSquares(matrix5) << "\n";

    return 0;
}