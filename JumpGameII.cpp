#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();

        if (n <= 1)
        {
            return 0;
        }

        int jumps = 0;
        int current_jump_end = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++)
        {

            farthest = max(farthest, i + nums[i]);

            if (i == current_jump_end)
            {
                jumps++;

                current_jump_end = farthest;

                if (current_jump_end >= n - 1)
                {
                    break;
                }
            }
        }

        return jumps;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {2, 3, 1, 1, 4};

    vector<int> nums2 = {2, 3, 0, 1, 4};

    vector<int> nums3 = {0};

    cout << "--- Jump Game II Tests ---" << endl;
    cout << "Test 1 (Expected 2): " << solver.jump(nums1) << endl;
    cout << "Test 2 (Expected 2): " << solver.jump(nums2) << endl;
    cout << "Test 3 (Expected 0): " << solver.jump(nums3) << endl;

    return 0;
}