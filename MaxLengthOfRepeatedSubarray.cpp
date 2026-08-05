#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> dp(n + 1, 0);
        int max_len = 0;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = n; j >= 1; --j)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[j] = dp[j - 1] + 1;
                    max_len = max(max_len, dp[j]);
                }
                else
                {
                    dp[j] = 0;
                }
            }
        }

        return max_len;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1_1 = {1, 2, 3, 2, 1};
    vector<int> nums2_1 = {3, 2, 1, 4, 7};
    cout << solver.findLength(nums1_1, nums2_1) << "\n";

    vector<int> nums1_2 = {0, 0, 0, 0, 0};
    vector<int> nums2_2 = {0, 0, 0, 0, 0};
    cout << solver.findLength(nums1_2, nums2_2) << "\n";

    return 0;
}