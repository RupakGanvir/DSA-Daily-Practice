#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right)
        {
            freq[nums[right]]++;

            while (freq[nums[right]] > k)
            {
                freq[nums[left]]--;
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 2, 3, 1, 2, 3, 1, 2};
    int k1 = 2;
    cout << solver.maxSubarrayLength(nums1, k1) << "\n";

    vector<int> nums2 = {1, 2, 1, 2, 1, 2, 1, 2};
    int k2 = 1;
    cout << solver.maxSubarrayLength(nums2, k2) << "\n";

    vector<int> nums3 = {5, 5, 5, 5, 5, 5, 5};
    int k3 = 4;
    cout << solver.maxSubarrayLength(nums3, k3) << "\n";

    return 0;
}