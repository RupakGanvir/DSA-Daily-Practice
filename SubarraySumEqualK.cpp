#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1;

        int current_sum = 0;
        int count = 0;

        for (int num : nums)
        {
            current_sum += num;

            if (prefix_counts.find(current_sum - k) != prefix_counts.end())
            {
                count += prefix_counts[current_sum - k];
            }

            prefix_counts[current_sum]++;
        }

        return count;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    cout << solver.subarraySum(nums1, k1) << "\n";

    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    cout << solver.subarraySum(nums2, k2) << "\n";

    return 0;
}