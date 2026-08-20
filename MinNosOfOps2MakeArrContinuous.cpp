#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int m = nums.size();
        int min_ops = n;
        int j = 0;

        for (int i = 0; i < m; ++i)
        {
            while (j < m && nums[j] < nums[i] + n)
            {
                j++;
            }
            min_ops = min(min_ops, n - (j - i));
        }

        return min_ops;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {4, 2, 5, 3};
    cout << solver.minOperations(nums1) << "\n";

    vector<int> nums2 = {1, 2, 3, 5, 6};
    cout << solver.minOperations(nums2) << "\n";

    vector<int> nums3 = {1, 10, 100, 1000};
    cout << solver.minOperations(nums3) << "\n";

    return 0;
}