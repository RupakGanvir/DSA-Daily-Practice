#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        unordered_map<int, int> product_count;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int product = nums[i] * nums[j];
                product_count[product]++;
            }
        }

        int total_tuples = 0;
        for (const auto &pair : product_count)
        {
            int count = pair.second;
            if (count > 1)
            {
                total_tuples += 4 * count * (count - 1);
            }
        }

        return total_tuples;
    }
};

int main()
{
    Solution solver;

    vector<int> nums1 = {2, 3, 4, 6};
    cout << solver.tupleSameProduct(nums1) << "\n";

    vector<int> nums2 = {1, 2, 4, 5, 10};
    cout << solver.tupleSameProduct(nums2) << "\n";

    vector<int> nums3 = {2, 3, 4, 6, 8, 12};
    cout << solver.tupleSameProduct(nums3) << "\n";

    return 0;
}