#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long countAlternatingSubarrays(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        long long total_subarrays = 1;
        long long current_length = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                current_length++;
            }
            else
            {
                current_length = 1;
            }
            total_subarrays += current_length;
        }

        return total_subarrays;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {0, 1, 1, 1};
    cout << solver.countAlternatingSubarrays(nums1) << "\n";

    vector<int> nums2 = {1, 0, 1, 0};
    cout << solver.countAlternatingSubarrays(nums2) << "\n";

    return 0;
}