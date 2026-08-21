#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minMaxGame(vector<int> &nums)
    {
        int n = nums.size();

        while (n > 1)
        {
            for (int i = 0; i < n / 2; ++i)
            {
                if (i % 2 == 0)
                {
                    nums[i] = min(nums[2 * i], nums[2 * i + 1]);
                }
                else
                {
                    nums[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
            }
            n /= 2;
        }

        return nums[0];
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 3, 5, 2, 4, 8, 2, 2};
    cout << solver.minMaxGame(nums1) << "\n";

    vector<int> nums2 = {3};
    cout << solver.minMaxGame(nums2) << "\n";

    return 0;
}