#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int countPairs(const vector<int> &nums, int mid)
    {
        int count = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right)
        {
            while (nums[right] - nums[left] > mid)
            {
                left++;
            }
            count += right - left;
        }
        return count;
    }

public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back() - nums.front();

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (countPairs(nums, mid) >= k)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 3, 1};
    int k1 = 1;
    cout << solver.smallestDistancePair(nums1, k1) << "\n";

    vector<int> nums2 = {1, 1, 1};
    int k2 = 2;
    cout << solver.smallestDistancePair(nums2, k2) << "\n";

    vector<int> nums3 = {1, 6, 1};
    int k3 = 3;
    cout << solver.smallestDistancePair(nums3, k3) << "\n";

    return 0;
}