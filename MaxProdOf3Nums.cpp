#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int max1 = -1001, max2 = -1001, max3 = -1001;
        int min1 = 1001, min2 = 1001;

        for (int num : nums)
        {
            if (num > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num > max2)
            {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3)
            {
                max3 = num;
            }

            if (num < min1)
            {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2)
            {
                min2 = num;
            }
        }

        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {1, 2, 3};
    cout << solver.maximumProduct(nums1) << "\n";

    vector<int> nums2 = {1, 2, 3, 4};
    cout << solver.maximumProduct(nums2) << "\n";

    vector<int> nums3 = {-1, -2, -3};
    cout << solver.maximumProduct(nums3) << "\n";

    vector<int> nums4 = {-100, -98, 1, 2, 3, 4};
    cout << solver.maximumProduct(nums4) << "\n";

    vector<int> nums5 = {-10, -10, 5, 2};
    cout << solver.maximumProduct(nums5) << "\n";

    return 0;
}