#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        int n = nums.size();
        while (n > 1)
        {
            for (int i = 0; i < n - 1; ++i)
            {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            n--;
        }
        return nums[0];
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << solver.triangularSum(nums1) << "\n";

    vector<int> nums2 = {5};
    cout << solver.triangularSum(nums2) << "\n";

    return 0;
}