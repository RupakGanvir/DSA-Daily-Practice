#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> dp = triangle.back();

        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = 0; j <= i; ++j)
            {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }

        return dp[0];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<vector<int>> triangle1 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << "--- Test Case 1 ---\n";
    cout << "Minimum Path Sum: " << solver.minimumTotal(triangle1) << "\n\n";

    vector<vector<int>> triangle2 = {{-10}};
    cout << "--- Test Case 2 ---\n";
    cout << "Minimum Path Sum: " << solver.minimumTotal(triangle2) << "\n";

    return 0;
}