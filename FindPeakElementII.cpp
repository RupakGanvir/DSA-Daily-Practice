#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int startCol = 0;
        int endCol = mat[0].size() - 1;

        while (startCol <= endCol)
        {
            int midCol = startCol + (endCol - startCol) / 2;

            int maxRow = 0;
            for (int i = 0; i < mat.size(); i++)
            {
                if (mat[i][midCol] > mat[maxRow][midCol])
                {
                    maxRow = i;
                }
            }

            bool leftIsBigger = midCol - 1 >= 0 && mat[maxRow][midCol - 1] > mat[maxRow][midCol];
            bool rightIsBigger = midCol + 1 < mat[0].size() && mat[maxRow][midCol + 1] > mat[maxRow][midCol];

            if (!leftIsBigger && !rightIsBigger)
            {
                return {maxRow, midCol};
            }
            else if (rightIsBigger)
            {
                startCol = midCol + 1;
            }
            else
            {
                endCol = midCol - 1;
            }
        }

        return {-1, -1};
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> mat1 = {
        {1, 4},
        {3, 2}};

    vector<vector<int>> mat2 = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}};

    vector<int> res1 = solver.findPeakGrid(mat1);
    vector<int> res2 = solver.findPeakGrid(mat2);

    cout << "--- Find a Peak Element II Tests ---" << endl;
    cout << "Test 1: [" << res1[0] << ", " << res1[1] << "]" << endl;
    cout << "Test 2: [" << res2[0] << ", " << res2[1] << "]" << endl;

    return 0;
}