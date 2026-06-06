#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return false;
        }

        int row = 0;
        int col = matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] > target)
            {
                col--;
            }
            else
            {
                row++;
            }
        }

        return false;
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> matrix1 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    int target1 = 5;

    vector<vector<int>> matrix2 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    int target2 = 20;

    vector<vector<int>> matrix3 = {{-1, 3}};
    int target3 = 3;

    cout << "--- Search a 2D Matrix II Tests ---" << endl;
    cout << "Test 1:  " << (solver.searchMatrix(matrix1, target1) ? "True" : "False") << endl;
    cout << "Test 2: " << (solver.searchMatrix(matrix2, target2) ? "True" : "False") << endl;
    cout << "Test 3:  " << (solver.searchMatrix(matrix3, target3) ? "True" : "False") << endl;

    return 0;
}