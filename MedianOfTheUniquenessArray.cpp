#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    long long countSubarraysWithAtMostKDistinct(const vector<int> &nums, int k)
    {
        long long count = 0;
        int left = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < nums.size(); ++right)
        {
            freq[nums[right]]++;

            while (freq.size() > k)
            {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                {
                    freq.erase(nums[left]);
                }
                left++;
            }
            count += (right - left + 1);
        }

        return count;
    }

public:
    int medianOfUniquenessArray(vector<int> &nums)
    {
        long long n = nums.size();
        long long total_subarrays = n * (n + 1) / 2;
        long long median_pos = (total_subarrays + 1) / 2;

        int low = 1;
        int high = n;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (countSubarraysWithAtMostKDistinct(nums, mid) >= median_pos)
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

    vector<int> nums1 = {1, 2, 3};
    cout << solver.medianOfUniquenessArray(nums1) << "\n";

    vector<int> nums2 = {3, 4, 3, 4, 5};
    cout << solver.medianOfUniquenessArray(nums2) << "\n";

    vector<int> nums3 = {4, 3, 5, 4};
    cout << solver.medianOfUniquenessArray(nums3) << "\n";

    return 0;
}