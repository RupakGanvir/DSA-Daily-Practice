#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {

                if (board[r][c] == '.')
                {
                    continue;
                }

                int num = board[r][c] - '1';

                int box_index = (r / 3) * 3 + (c / 3);

                if (rows[r][num] || cols[c][num] || boxes[box_index][num])
                {
                    return false;
                }

                rows[r][num] = true;
                cols[c][num] = true;
                boxes[box_index][num] = true;
            }
        }

        return true;
    }
};

int main()
{
    Solution solver;

    vector<vector<char>> validBoard = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char>> invalidBoard = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '5', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << "--- Valid Sudoku Tests ---" << endl;
    cout << "Test 1 (Expected Valid/True):   " << (solver.isValidSudoku(validBoard) ? "True" : "False") << endl;
    cout << "Test 2 (Expected Invalid/False): " << (solver.isValidSudoku(invalidBoard) ? "True" : "False") << endl;

    return 0;
}