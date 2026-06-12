#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    bool dfs(vector<vector<char>> &board, string &word, int r, int c, int index)
    {
        if (index == word.length())
        {
            return true;
        }

        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index])
        {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);

        board[r][c] = temp;
        return found;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || board[0].empty())
        {
            return false;
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution solver;

    vector<vector<char>> board1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word1 = "ABCCED";

    vector<vector<char>> board2 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word2 = "SEE";

    vector<vector<char>> board3 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word3 = "ABCB";

    cout << "--- Word Search Tests ---" << endl;
    cout << "Test 1: " << (solver.exist(board1, word1) ? "True" : "False") << endl;
    cout << "Test 2: " << (solver.exist(board2, word2) ? "True" : "False") << endl;
    cout << "Test 3: " << (solver.exist(board3, word3) ? "True" : "False") << endl;

    return 0;
}