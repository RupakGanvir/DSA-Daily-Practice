#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long maxSubarraySum(vector<int> &nums)
    {
        long long ans = nums[0];
        for (int num : nums)
        {
            if (num > ans)
            {
                ans = num;
            }
        }

        long long prefix = 0;
        long long minPrefix = 0;
        long long modifiedMinPrefix = 0;
        unordered_map<int, long long> count;
        unordered_map<int, long long> minPrefixPlusRemoval;

        for (int num : nums)
        {
            prefix += num;
            ans = max(ans, prefix - modifiedMinPrefix);

            if (num < 0)
            {
                count[num]++;
                if (minPrefixPlusRemoval.find(num) == minPrefixPlusRemoval.end())
                {
                    minPrefixPlusRemoval[num] = minPrefix + num;
                }
                else
                {
                    minPrefixPlusRemoval[num] = min(minPrefixPlusRemoval[num], minPrefix) + num;
                }
                modifiedMinPrefix = min({modifiedMinPrefix, count[num] * num, minPrefixPlusRemoval[num]});
            }

            minPrefix = min(minPrefix, prefix);
            modifiedMinPrefix = min(modifiedMinPrefix, minPrefix);
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {-3, 2, -2, -1, 3, -2, 3};
    cout << solver.maxSubarraySum(nums1) << "\n";

    vector<int> nums2 = {1, 2, 3, 4};
    cout << solver.maxSubarraySum(nums2) << "\n";

    vector<int> nums3 = {-3, -2, -3};
    cout << solver.maxSubarraySum(nums3) << "\n";

    vector<int> nums4 = {-1, -1, -1, -1};
    cout << solver.maxSubarraySum(nums4) << "\n";

    return 0;
}