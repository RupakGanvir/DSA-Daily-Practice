#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> lengths(n, 1);
        vector<int> counts(n, 1);

        int max_len = 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    if (lengths[j] + 1 > lengths[i])
                    {
                        lengths[i] = lengths[j] + 1;
                        counts[i] = counts[j];
                    }
                    else if (lengths[j] + 1 == lengths[i])
                    {
                        counts[i] += counts[j];
                    }
                }
            }
            max_len = max(max_len, lengths[i]);
        }

        int num_lis = 0;
        for (int i = 0; i < n; ++i)
        {
            if (lengths[i] == max_len)
            {
                num_lis += counts[i];
            }
        }

        return num_lis;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> nums1 = {1, 3, 5, 4, 7};
    cout << "--- Test Case 1 ---\n";
    cout << "Number of LIS: " << solver.findNumberOfLIS(nums1) << "\n\n";

    vector<int> nums2 = {2, 2, 2, 2, 2};
    cout << "--- Test Case 2 ---\n";
    cout << "Number of LIS: " << solver.findNumberOfLIS(nums2) << "\n\n";

    vector<int> nums3 = {1};
    cout << "--- Test Case 3 ---\n";
    cout << "Number of LIS: " << solver.findNumberOfLIS(nums3) << "\n";

    return 0;
}