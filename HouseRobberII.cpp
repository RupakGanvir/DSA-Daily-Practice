#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int robRange(const vector<int> &nums, int start, int end)
    {
        int rob1 = 0;
        int rob2 = 0;

        for (int i = start; i <= end; ++i)
        {
            int temp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        return rob2;
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> nums1 = {2, 3, 2};
    cout << "--- Test Case 1 ---\n";
    cout << "Max money robbed: " << solver.rob(nums1) << "\n\n";

    vector<int> nums2 = {1, 2, 3, 1};
    cout << "--- Test Case 2 ---\n";
    cout << "Max money robbed: " << solver.rob(nums2) << "\n\n";

    vector<int> nums3 = {1, 2, 3};
    cout << "--- Test Case 3 ---\n";
    cout << "Max money robbed: " << solver.rob(nums3) << "\n";

    return 0;
}