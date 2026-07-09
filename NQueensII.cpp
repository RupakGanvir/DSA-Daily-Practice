#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int totalNQueens(int n)
    {
        int count = 0;
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        auto backtrack = [&](auto &self, int row) -> void
        {
            if (row == n)
            {
                count++;
                return;
            }
            for (int col = 0; col < n; ++col)
            {
                if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
                {
                    continue;
                }

                cols[col] = true;
                diag1[row + col] = true;
                diag2[row - col + n - 1] = true;

                self(self, row + 1);

                cols[col] = false;
                diag1[row + col] = false;
                diag2[row - col + n - 1] = false;
            }
        };

        backtrack(backtrack, 0);
        return count;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int n1 = 4;
    cout << "--- Test Case 1 ---\n";
    cout << "Distinct solutions for n = " << n1 << ": " << solver.totalNQueens(n1) << "\n\n";

    int n2 = 1;
    cout << "--- Test Case 2 ---\n";
    cout << "Distinct solutions for n = " << n2 << ": " << solver.totalNQueens(n2) << "\n\n";

    int n3 = 8;
    cout << "--- Test Case 3 ---\n";
    cout << "Distinct solutions for n = " << n3 << ": " << solver.totalNQueens(n3) << "\n";

    return 0;
}