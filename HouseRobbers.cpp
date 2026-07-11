#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int rob1 = 0;
        int rob2 = 0;

        for (int n : nums)
        {
            int temp = max(rob1 + n, rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        return rob2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> nums1 = {1, 2, 3, 1};
    cout << "--- Test Case 1 ---\n";
    cout << "Max money robbed: " << solver.rob(nums1) << "\n\n";

    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "--- Test Case 2 ---\n";
    cout << "Max money robbed: " << solver.rob(nums2) << "\n";

    return 0;
}