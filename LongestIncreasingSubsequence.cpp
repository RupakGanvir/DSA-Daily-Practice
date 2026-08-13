#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> res;

        for (int num : nums)
        {
            auto it = lower_bound(res.begin(), res.end(), num);
            if (it == res.end())
            {
                res.push_back(num);
            }
            else
            {
                *it = num;
            }
        }

        return res.size();
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << solver.lengthOfLIS(nums1) << "\n";

    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << solver.lengthOfLIS(nums2) << "\n";

    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    cout << solver.lengthOfLIS(nums3) << "\n";

    return 0;
}