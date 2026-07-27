#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int max1 = 0;
        int max2 = 0;

        for (int num : nums)
        {
            if (num > max1)
            {
                max2 = max1;
                max1 = num;
            }
            else if (num > max2)
            {
                max2 = num;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {3, 4, 5, 2};
    cout << solver.maxProduct(nums1) << "\n";

    vector<int> nums2 = {1, 5, 4, 5};
    cout << solver.maxProduct(nums2) << "\n";

    vector<int> nums3 = {3, 7};
    cout << solver.maxProduct(nums3) << "\n";

    vector<int> nums4 = {10, 2, 5, 2};
    cout << solver.maxProduct(nums4) << "\n";

    vector<int> nums5 = {1, 2};
    cout << solver.maxProduct(nums5) << "\n";

    return 0;
}