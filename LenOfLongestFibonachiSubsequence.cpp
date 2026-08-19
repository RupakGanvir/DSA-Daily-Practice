#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> index_map;
        for (int i = 0; i < n; ++i)
        {
            index_map[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, 2));
        int max_len = 0;

        for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i < j; ++i)
            {
                int prev = arr[j] - arr[i];
                if (prev < arr[i] && index_map.count(prev))
                {
                    int k = index_map[prev];
                    dp[i][j] = dp[k][i] + 1;
                    max_len = max(max_len, dp[i][j]);
                }
            }
        }

        return max_len >= 3 ? max_len : 0;
    }
};

int main()
{
    Solution solver;

    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << solver.lenLongestFibSubseq(arr1) << "\n";

    vector<int> arr2 = {1, 3, 7, 11, 12, 14, 18};
    cout << solver.lenLongestFibSubseq(arr2) << "\n";

    return 0;
}