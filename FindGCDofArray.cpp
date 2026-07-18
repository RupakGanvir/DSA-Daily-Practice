#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int getGcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    int findGCD(vector<int> &nums)
    {
        int min_val = nums[0];
        int max_val = nums[0];

        for (int num : nums)
        {
            if (num < min_val)
            {
                min_val = num;
            }
            if (num > max_val)
            {
                max_val = num;
            }
        }

        return getGcd(min_val, max_val);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> nums1 = {2, 5, 6, 9, 10};
    cout << "--- Test Case 1 ---\n";
    cout << "Output: " << solver.findGCD(nums1) << "\n\n";

    vector<int> nums2 = {7, 5, 6, 8, 3};
    cout << "--- Test Case 2 ---\n";
    cout << "Output: " << solver.findGCD(nums2) << "\n\n";

    vector<int> nums3 = {3, 3};
    cout << "--- Test Case 3 ---\n";
    cout << "Output: " << solver.findGCD(nums3) << "\n";

    return 0;
}