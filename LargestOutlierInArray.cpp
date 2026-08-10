#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int getLargestOutlier(vector<int> &nums)
    {
        long long total_sum = 0;
        unordered_map<int, int> count;

        for (int num : nums)
        {
            total_sum += num;
            count[num]++;
        }

        int max_outlier = INT_MIN;

        for (int y : nums)
        {
            long long remaining = total_sum - y;

            if (remaining % 2 == 0)
            {
                long long x = remaining / 2;

                if (count.find(x) != count.end())
                {
                    if (x != y || count[x] > 1)
                    {
                        max_outlier = max(max_outlier, y);
                    }
                }
            }
        }

        return max_outlier;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {2, 3, 5, 10};
    cout << solver.getLargestOutlier(nums1) << "\n";

    vector<int> nums2 = {-2, -1, -3, -6, 4};
    cout << solver.getLargestOutlier(nums2) << "\n";

    vector<int> nums3 = {1, 1, 1, 1, 1, 5, 5};
    cout << solver.getLargestOutlier(nums3) << "\n";

    return 0;
}