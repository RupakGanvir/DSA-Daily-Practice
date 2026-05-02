#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        std::vector<std::vector<std::string>> results;
        std::vector<std::string> board(n, std::string(n, '.'));
        backtrack(0, board, results, n);
        return results;
    }

private:
    void backtrack(int row, std::vector<std::string> &board,
                   std::vector<std::vector<std::string>> &results, int n)
    {
        if (row == n)
        {
            results.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                backtrack(row + 1, board, results, n);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, std::vector<std::string> &board, int n)
    {
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    int n = 4;
    std::vector<std::vector<std::string>> solutions = sol.solveNQueens(n);

    std::cout << "Found " << solutions.size() << " solutions for N=" << n << ":\n\n";
    for (const auto &board : solutions)
    {
        for (const std::string &row : board)
        {
            std::cout << row << "\n";
        }
        std::cout << "----------------\n";
    }

    return 0;
}