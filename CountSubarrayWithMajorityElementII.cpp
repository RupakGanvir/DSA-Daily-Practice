#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    class FenwickTree
    {
    private:
        int size;
        vector<int> tree;

    public:
        FenwickTree(int n)
        {
            size = n;
            tree.assign(n + 1, 0);
        }
        void update(int i, int delta)
        {
            while (i <= size)
            {
                tree[i] += delta;
                i += i & -i;
            }
        }
        int query(int i)
        {
            int sum = 0;
            while (i > 0)
            {
                sum += tree[i];
                i -= i & -i;
            }
            return sum;
        }
    };

public:
    long long countMajoritySubarrays(vector<int> &nums, int target)
    {
        int n = nums.size();
        FenwickTree bit(2 * n + 5);
        int offset = n + 2;
        int current_sum = 0;
        long long count = 0;

        bit.update(current_sum + offset, 1);

        for (int num : nums)
        {
            if (num == target)
            {
                current_sum += 1;
            }
            else
            {
                current_sum -= 1;
            }
            count += bit.query(current_sum + offset - 1);
            bit.update(current_sum + offset, 1);
        }

        return count;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {2, 1, 2};
    int target1 = 2;

    vector<int> nums2 = {1, 2, 2, 3};
    int target2 = 2;

    cout << "--- Count Subarrays with Majority Element II Tests ---" << endl;
    cout << "Test 1: " << solver.countMajoritySubarrays(nums1, target1) << endl;
    cout << "Test 2: " << solver.countMajoritySubarrays(nums2, target2) << endl;

    return 0;
}