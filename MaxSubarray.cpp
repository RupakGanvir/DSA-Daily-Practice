#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = nums[0];

        int current_sum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {

            current_sum = max(nums[i], current_sum + nums[i]);

            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    vector<int> nums2 = {-5, -2, -9, -1, -3};

    vector<int> nums3 = {5};

    cout << "--- Maximum Subarray Tests ---" << endl;
    cout << "Test 1 (Expected 6):  " << solver.maxSubArray(nums1) << endl;
    cout << "Test 2 (Expected -1): " << solver.maxSubArray(nums2) << endl;
    cout << "Test 3 (Expected 5):  " << solver.maxSubArray(nums3) << endl;

    return 0;
}