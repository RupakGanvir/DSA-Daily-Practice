#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        long long operations = 0;
        int n = nums.size();
        long long prev = nums[n - 1];

        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i] > prev)
            {
                long long pieces = (nums[i] + prev - 1) / prev;
                operations += (pieces - 1);
                prev = nums[i] / pieces;
            }
            else
            {
                prev = nums[i];
            }
        }

        return operations;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> nums1 = {3, 9, 3};
    cout << "--- Test Case 1 ---\n";
    cout << "Minimum Operations: " << solver.minimumReplacement(nums1) << "\n\n";

    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << "--- Test Case 2 ---\n";
    cout << "Minimum Operations: " << solver.minimumReplacement(nums2) << "\n\n";

    vector<int> nums3 = {1, 2, 10, 4};
    cout << "--- Test Case 3 ---\n";
    cout << "Minimum Operations: " << solver.minimumReplacement(nums3) << "\n";

    return 0;
}