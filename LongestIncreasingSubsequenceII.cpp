#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<int> tree;
    int size;

    void update(int p, int value)
    {
        p += size;
        tree[p] = max(tree[p], value);
        for (; p > 1; p >>= 1)
        {
            tree[p >> 1] = max(tree[p], tree[p ^ 1]);
        }
    }

    int query(int l, int r)
    {
        int res = 0;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = max(res, tree[l++]);
            if (r & 1)
                res = max(res, tree[--r]);
        }
        return res;
    }

public:
    int lengthOfLIS(vector<int> &nums, int k)
    {
        int max_val = 0;
        for (int num : nums)
        {
            max_val = max(max_val, num);
        }

        size = max_val + 1;
        tree.assign(2 * size, 0);

        int ans = 0;
        for (int x : nums)
        {
            int left = max(1, x - k);
            int right = x - 1;

            int curr_max = 0;
            if (left <= right)
            {
                curr_max = query(left, right + 1);
            }

            update(x, curr_max + 1);
            ans = max(ans, curr_max + 1);
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {4, 2, 1, 4, 3, 4, 5, 8, 15};
    int k1 = 3;
    cout << solver.lengthOfLIS(nums1, k1) << "\n";

    vector<int> nums2 = {7, 4, 5, 1, 8, 12, 4, 7};
    int k2 = 5;
    cout << solver.lengthOfLIS(nums2, k2) << "\n";

    vector<int> nums3 = {1, 5};
    int k3 = 1;
    cout << solver.lengthOfLIS(nums3, k3) << "\n";

    return 0;
}