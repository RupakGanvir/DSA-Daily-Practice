#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int max_len = 0;
        int mask = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right)
        {
            while ((mask & nums[right]) != 0)
            {
                mask ^= nums[left];
                left++;
            }
            mask |= nums[right];
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 3, 8, 48, 10};
    cout << solver.longestNiceSubarray(nums1) << "\n";

    vector<int> nums2 = {3, 1, 5, 11, 13};
    cout << solver.longestNiceSubarray(nums2) << "\n";

    return 0;
}