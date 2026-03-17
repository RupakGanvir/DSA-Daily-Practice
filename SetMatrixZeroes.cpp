#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        if (m == 0)
            return;
        int n = matrix[0].size();

        set<int> row, col;

        // Step 1: Identify which rows and columns need to be zeroed
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        // Step 2: Iterate again and update the matrix
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row.count(i) || col.count(j))
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Helper function to print the matrix
void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    sol.setZeroes(matrix);

    cout << "\nModified Matrix:" << endl;
    printMatrix(matrix);

    return 0;
}