#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution
{
public:
    int threeSumClosest(std::vector<int> &nums, int target)
    {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (currentSum == target)
                {
                    return currentSum;
                }

                if (std::abs(target - currentSum) < std::abs(target - closestSum))
                {
                    closestSum = currentSum;
                }

                if (currentSum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return closestSum;
    }
};

int main()
{
    Solution sol;

    std::vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    // -1 + 2 + 1 = 2 (Closest to 1)
    std::cout << "Result 1: " << sol.threeSumClosest(nums1, target1) << std::endl;

    std::vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    std::cout << "Result 2: " << sol.threeSumClosest(nums2, target2) << std::endl;

    return 0;
}