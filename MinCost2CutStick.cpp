#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; ++len)
        {
            for (int i = 0; i < m - len; ++i)
            {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }

        return dp[0][m - 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int n1 = 7;
    vector<int> cuts1 = {1, 3, 4, 5};
    cout << "--- Test Case 1 ---\n";
    cout << "Minimum Cost: " << solver.minCost(n1, cuts1) << "\n\n";

    int n2 = 9;
    vector<int> cuts2 = {5, 6, 1, 4, 2};
    cout << "--- Test Case 2 ---\n";
    cout << "Minimum Cost: " << solver.minCost(n2, cuts2) << "\n\n";

    int n3 = 10;
    vector<int> cuts3 = {1, 9};
    cout << "--- Test Case 3 ---\n";
    cout << "Minimum Cost: " << solver.minCost(n3, cuts3) << "\n";

    return 0;
}