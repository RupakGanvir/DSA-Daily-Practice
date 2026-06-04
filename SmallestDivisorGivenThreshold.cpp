#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    bool isValid(const vector<int> &nums, int divisor, int threshold)
    {
        int current_sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            current_sum += (nums[i] + divisor - 1) / divisor;
        }

        return current_sum <= threshold;
    }

public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int left = 1;

        int right = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            right = max(right, nums[i]);
        }

        int best_divisor = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (isValid(nums, mid, threshold))
            {
                best_divisor = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return best_divisor;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 2, 5, 9};
    int threshold1 = 6;

    vector<int> nums2 = {44, 22, 33, 11, 1};
    int threshold2 = 5;

    vector<int> nums3 = {21212, 10101, 12121};
    int threshold3 = 1000000;

    cout << "--- Smallest Divisor Tests ---" << endl;
    cout << "Test 1: " << solver.smallestDivisor(nums1, threshold1) << endl;
    cout << "Test 2: " << solver.smallestDivisor(nums2, threshold2) << endl;
    cout << "Test 3: " << solver.smallestDivisor(nums3, threshold3) << endl;

    return 0;
}