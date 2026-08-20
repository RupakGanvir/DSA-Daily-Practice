#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mod_seen;
        mod_seen[0] = -1;

        int prefix_sum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            prefix_sum = (prefix_sum + nums[i]) % k;

            if (mod_seen.find(prefix_sum) != mod_seen.end())
            {
                if (i - mod_seen[prefix_sum] >= 2)
                {
                    return true;
                }
            }
            else
            {
                mod_seen[prefix_sum] = i;
            }
        }

        return false;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {23, 2, 4, 6, 7};
    int k1 = 6;
    cout << (solver.checkSubarraySum(nums1, k1) ? "true" : "false") << "\n";

    vector<int> nums2 = {23, 2, 6, 4, 7};
    int k2 = 6;
    cout << (solver.checkSubarraySum(nums2, k2) ? "true" : "false") << "\n";

    vector<int> nums3 = {23, 2, 6, 4, 7};
    int k3 = 13;
    cout << (solver.checkSubarraySum(nums3, k3) ? "true" : "false") << "\n";

    return 0;
}