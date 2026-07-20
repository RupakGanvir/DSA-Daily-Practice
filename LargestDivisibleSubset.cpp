#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return {};

        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        int max_len = 1;
        int max_idx = 0;

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > max_len)
            {
                max_len = dp[i];
                max_idx = i;
            }
        }

        vector<int> result;
        int curr = max_idx;
        while (curr != -1)
        {
            result.push_back(nums[curr]);
            curr = parent[curr];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

void printVector(const vector<int> &vec)
{
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<int> nums1 = {1, 2, 3};
    cout << "--- Test Case 1 ---\n";
    cout << "Largest Divisible Subset: ";
    printVector(solver.largestDivisibleSubset(nums1));
    cout << "\n\n";

    vector<int> nums2 = {1, 2, 4, 8};
    cout << "--- Test Case 2 ---\n";
    cout << "Largest Divisible Subset: ";
    printVector(solver.largestDivisibleSubset(nums2));
    cout << "\n\n";

    vector<int> nums3 = {2, 3, 4, 9, 8};
    cout << "--- Test Case 3 ---\n";
    cout << "Largest Divisible Subset: ";
    printVector(solver.largestDivisibleSubset(nums3));
    cout << "\n";

    return 0;
}