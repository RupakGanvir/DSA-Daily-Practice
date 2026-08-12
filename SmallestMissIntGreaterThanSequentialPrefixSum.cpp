#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        int prefix_sum = nums[0];

        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                prefix_sum += nums[i];
            }
            else
            {
                break;
            }
        }

        unordered_set<int> num_set(nums.begin(), nums.end());

        while (num_set.count(prefix_sum))
        {
            prefix_sum++;
        }

        return prefix_sum;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 2, 3, 2, 5};
    cout << solver.missingInteger(nums1) << "\n";

    vector<int> nums2 = {3, 4, 5, 1, 12, 14, 13};
    cout << solver.missingInteger(nums2) << "\n";

    vector<int> nums3 = {14, 9, 8, 1, 5, 8, 6, 11, 3, 1, 11};
    cout << solver.missingInteger(nums3) << "\n";

    return 0;
}