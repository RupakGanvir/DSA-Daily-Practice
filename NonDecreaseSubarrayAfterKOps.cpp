#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    long long countNonDecreasingSubarrays(vector<int> &nums, long long k)
    {
        long long validSubarrays = 0;
        long long currentCost = 0;
        deque<pair<int, int>> stateQueue;

        int right = nums.size() - 1;
        for (int left = nums.size() - 1; left >= 0; --left)
        {
            int currentNum = nums[left];
            int count = 1;

            while (!stateQueue.empty() && stateQueue.back().first < currentNum)
            {
                int nextNum = stateQueue.back().first;
                int nextCount = stateQueue.back().second;
                stateQueue.pop_back();
                count += nextCount;
                currentCost += static_cast<long long>(currentNum - nextNum) * nextCount;
            }
            stateQueue.push_back({currentNum, count});

            while (currentCost > k)
            {
                int rightmostNum = stateQueue.front().first;
                int rightmostCount = stateQueue.front().second;
                stateQueue.pop_front();
                currentCost -= static_cast<long long>(rightmostNum - nums[right]);
                right--;

                if (rightmostCount > 1)
                {
                    stateQueue.push_front({rightmostNum, rightmostCount - 1});
                }
            }

            validSubarrays += (right - left + 1);
        }

        return validSubarrays;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {6, 3, 1, 2, 4, 4};
    long long k1 = 7;
    cout << solver.countNonDecreasingSubarrays(nums1, k1) << "\n";

    vector<int> nums2 = {6, 3, 1, 3, 6};
    long long k2 = 4;
    cout << solver.countNonDecreasingSubarrays(nums2, k2) << "\n";

    vector<int> nums3 = {1, 2, 3, 4};
    long long k3 = 0;
    cout << solver.countNonDecreasingSubarrays(nums3, k3) << "\n";

    vector<int> nums4 = {4, 3, 2, 1};
    long long k4 = 6;
    cout << solver.countNonDecreasingSubarrays(nums4, k4) << "\n";

    vector<int> nums5 = {1, 1, 1, 1};
    long long k5 = 0;
    cout << solver.countNonDecreasingSubarrays(nums5, k5) << "\n";

    return 0;
}