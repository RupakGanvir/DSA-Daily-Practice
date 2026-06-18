#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int atMost(vector<int> &nums, int goal)
    {
        if (goal < 0)
        {
            return 0;
        }

        int left = 0;
        int currentSum = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            currentSum += nums[right];

            while (currentSum > goal)
            {
                currentSum -= nums[left];
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 0, 1, 0, 1};
    int goal1 = 2;

    vector<int> nums2 = {0, 0, 0, 0, 0};
    int goal2 = 0;

    cout << "--- Binary Subarrays With Sum Tests ---" << endl;
    cout << "Test 1: " << solver.numSubarraysWithSum(nums1, goal1) << endl;
    cout << "Test 2: " << solver.numSubarraysWithSum(nums2, goal2) << endl;

    return 0;
}