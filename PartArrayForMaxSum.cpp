#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i)
        {
            int max_val = 0;
            for (int j = 1; j <= k && i - j >= 0; ++j)
            {
                max_val = max(max_val, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j] + max_val * j);
            }
        }

        return dp[n];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> arr1 = {1, 15, 7, 9, 2, 5, 10};
    int k1 = 3;
    cout << "--- Test Case 1 ---\n";
    cout << "Output: " << solver.maxSumAfterPartitioning(arr1, k1) << "\n\n";

    vector<int> arr2 = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    int k2 = 4;
    cout << "--- Test Case 2 ---\n";
    cout << "Output: " << solver.maxSumAfterPartitioning(arr2, k2) << "\n\n";

    vector<int> arr3 = {1};
    int k3 = 1;
    cout << "--- Test Case 3 ---\n";
    cout << "Output: " << solver.maxSumAfterPartitioning(arr3, k3) << "\n";

    return 0;
}