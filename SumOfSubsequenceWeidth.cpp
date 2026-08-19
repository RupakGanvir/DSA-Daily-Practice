#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int sumSubseqWidths(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long mod = 1e9 + 7;
        long long ans = 0;
        long long p = 1;

        for (int i = 0; i < n; ++i)
        {
            ans = (ans + nums[i] * p - nums[n - 1 - i] * p) % mod;
            p = (p * 2) % mod;
        }

        return (ans + mod) % mod;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {2, 1, 3};
    cout << solver.sumSubseqWidths(nums1) << "\n";

    vector<int> nums2 = {2};
    cout << solver.sumSubseqWidths(nums2) << "\n";

    return 0;
}