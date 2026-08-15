#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        int total_xor = 0;
        bool has_nonzero = false;

        for (int num : nums)
        {
            total_xor ^= num;
            if (num != 0)
            {
                has_nonzero = true;
            }
        }

        if (total_xor != 0)
        {
            return nums.size();
        }

        if (has_nonzero)
        {
            return nums.size() - 1;
        }

        return 0;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 2, 3};
    cout << solver.longestSubsequence(nums1) << "\n";

    vector<int> nums2 = {0, 0, 0};
    cout << solver.longestSubsequence(nums2) << "\n";

    vector<int> nums3 = {3, 2, 1, 0};
    cout << solver.longestSubsequence(nums3) << "\n";

    return 0;
}