#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {

                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution solver;

    int m1 = 3, n1 = 7;

    int m2 = 3, n2 = 2;

    int m3 = 1, n3 = 1;

    cout << "--- Unique Paths Tests ---" << endl;
    cout << "Test 1 (m=3, n=7) Expected 28: -> Actual: " << solver.uniquePaths(m1, n1) << endl;
    cout << "Test 2 (m=3, n=2) Expected 3:  -> Actual: " << solver.uniquePaths(m2, n2) << endl;
    cout << "Test 3 (m=1, n=1) Expected 1:  -> Actual: " << solver.uniquePaths(m3, n3) << endl;

    return 0;
}