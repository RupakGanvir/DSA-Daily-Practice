#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
private:
    bool canSplit(const vector<int> &nums, int k, int maxSum)
    {
        int subarrays = 1;
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (currentSum + nums[i] > maxSum)
            {
                subarrays++;
                currentSum = nums[i];

                if (subarrays > k)
                {
                    return false;
                }
            }
            else
            {
                currentSum += nums[i];
            }
        }

        return true;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        int left = 0;
        int right = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            left = max(left, nums[i]);
            right += nums[i];
        }

        int bestSum = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid))
            {
                bestSum = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return bestSum;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {7, 2, 5, 10, 8};
    int k1 = 2;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 2;

    vector<int> nums3 = {1, 4, 4};
    int k3 = 3;

    cout << "--- Split Array Largest Sum Tests ---" << endl;
    cout << "Test 1: " << solver.splitArray(nums1, k1) << endl;
    cout << "Test 2:  " << solver.splitArray(nums2, k2) << endl;
    cout << "Test 3:  " << solver.splitArray(nums3, k3) << endl;

    return 0;
}