#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    int atMost(vector<int> &nums, int k)
    {
        unordered_map<int, int> counts;
        int left = 0;
        int totalSubarrays = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            if (counts[nums[right]] == 0)
            {
                k--;
            }
            counts[nums[right]]++;

            while (k < 0)
            {
                counts[nums[left]]--;
                if (counts[nums[left]] == 0)
                {
                    k++;
                }
                left++;
            }

            totalSubarrays += (right - left + 1);
        }

        return totalSubarrays;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 2, 1, 2, 3};
    int k1 = 2;

    vector<int> nums2 = {1, 2, 1, 3, 4};
    int k2 = 3;

    cout << "--- Subarrays with K Different Integers Tests ---" << endl;
    cout << "Test 1: " << solver.subarraysWithKDistinct(nums1, k1) << endl;
    cout << "Test 2: " << solver.subarraysWithKDistinct(nums2, k2) << endl;

    return 0;
}