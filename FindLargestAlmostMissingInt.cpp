#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestAlmostMissingInteger(vector<int> &nums, int k)
    {
        unordered_map<int, int> subarray_count;
        int n = nums.size();

        for (int i = 0; i <= n - k; ++i)
        {
            unordered_set<int> unique_in_subarray;
            for (int j = i; j < i + k; ++j)
            {
                unique_in_subarray.insert(nums[j]);
            }

            for (int num : unique_in_subarray)
            {
                subarray_count[num]++;
            }
        }

        int max_val = -1;
        for (const auto &pair : subarray_count)
        {
            if (pair.second == 1)
            {
                max_val = max(max_val, pair.first);
            }
        }

        return max_val;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {3, 9, 2, 1, 7};
    int k1 = 3;
    cout << solver.largestAlmostMissingInteger(nums1, k1) << "\n";

    vector<int> nums2 = {3, 9, 2, 1, 7};
    int k2 = 1;
    cout << solver.largestAlmostMissingInteger(nums2, k2) << "\n";

    vector<int> nums3 = {0, 0};
    int k3 = 2;
    cout << solver.largestAlmostMissingInteger(nums3, k3) << "\n";

    return 0;
}