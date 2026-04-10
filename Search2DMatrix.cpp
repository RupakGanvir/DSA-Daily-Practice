#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0;
        int high = (rows * cols) - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int r = mid / cols;
            int c = mid % cols;

            if (matrix[r][c] == target)
            {
                return true;
            }
            else if (matrix[r][c] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    int target = 3;

    if (sol.searchMatrix(matrix, target))
    {
        cout << "Target " << target << " found!" << endl;
    }
    else
    {
        cout << "Target " << target << " not found." << endl;
    }

    return 0;
}