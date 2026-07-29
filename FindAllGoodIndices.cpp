#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> goodIndices(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n <= 2 * k)
        {
            return {};
        }

        vector<int> left(n, 1);
        vector<int> right(n, 1);

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] <= nums[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i] <= nums[i + 1])
            {
                right[i] = right[i + 1] + 1;
            }
        }

        vector<int> ans;
        for (int i = k; i < n - k; ++i)
        {
            if (left[i - 1] >= k && right[i + 1] >= k)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

void printVector(const vector<int> &v)
{
    if (v.empty())
    {
        cout << "[]\n";
        return;
    }
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << "\n";
}

int main()
{
    Solution solver;

    vector<int> nums1 = {2, 1, 1, 1, 3, 4, 1};
    int k1 = 2;
    printVector(solver.goodIndices(nums1, k1));

    vector<int> nums2 = {2, 1, 1, 2};
    int k2 = 2;
    printVector(solver.goodIndices(nums2, k2));

    vector<int> nums3 = {878707, 243062, 783707, 260854, 276007, 335698, 937080, 529683, 508466, 423528, 483243, 856555};
    int k3 = 3;
    printVector(solver.goodIndices(nums3, k3));

    return 0;
}