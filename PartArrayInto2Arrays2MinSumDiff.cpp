#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size() / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> left(n + 1), right(n + 1);

        for (int i = 0; i < (1 << n); ++i)
        {
            int sum = 0, sz = 0;
            for (int j = 0; j < n; ++j)
            {
                if (i & (1 << j))
                {
                    sum += nums[j];
                    sz++;
                }
            }
            left[sz].push_back(sum);
        }

        for (int i = 0; i < (1 << n); ++i)
        {
            int sum = 0, sz = 0;
            for (int j = 0; j < n; ++j)
            {
                if (i & (1 << j))
                {
                    sum += nums[n + j];
                    sz++;
                }
            }
            right[sz].push_back(sum);
        }

        for (int i = 0; i <= n; ++i)
        {
            sort(right[i].begin(), right[i].end());
        }

        int ans = min(abs(totalSum - 2 * left[n][0]), abs(totalSum - 2 * right[n][0]));

        for (int sz = 1; sz < n; ++sz)
        {
            for (int a : left[sz])
            {
                int b = (totalSum - 2 * a) / 2;
                int rightSz = n - sz;
                auto &v = right[rightSz];
                auto it = lower_bound(v.begin(), v.end(), b);

                if (it != v.end())
                {
                    ans = min(ans, abs(totalSum - 2 * (a + *it)));
                }
                if (it != v.begin())
                {
                    ans = min(ans, abs(totalSum - 2 * (a + *prev(it))));
                }
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> nums1 = {3, 9, 7, 3};
    cout << "--- Test Case 1 ---\n";
    cout << "Minimum Difference: " << solver.minimumDifference(nums1) << "\n\n";

    vector<int> nums2 = {-36, 36};
    cout << "--- Test Case 2 ---\n";
    cout << "Minimum Difference: " << solver.minimumDifference(nums2) << "\n\n";

    vector<int> nums3 = {2, -1, 0, 4, -2, -9};
    cout << "--- Test Case 3 ---\n";
    cout << "Minimum Difference: " << solver.minimumDifference(nums3) << "\n";

    return 0;
}