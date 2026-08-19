#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> pref(n, 0);

        for (int i = 1; i < n; ++i)
        {
            pref[i] = pref[i - 1];
            if (nums[i - 1] % 2 == nums[i] % 2)
            {
                pref[i]++;
            }
        }

        vector<bool> ans;
        ans.reserve(queries.size());

        for (const auto &q : queries)
        {
            int u = q[0];
            int v = q[1];

            if (pref[v] - pref[u] == 0)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }

        return ans;
    }
};

void printVector(const vector<bool> &vec)
{
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << (vec[i] ? "true" : "false") << (i + 1 == vec.size() ? "" : ", ");
    }
    cout << "]\n";
}

int main()
{
    Solution solver;

    vector<int> nums1 = {3, 4, 1, 2, 6};
    vector<vector<int>> queries1 = {{0, 4}};
    printVector(solver.isArraySpecial(nums1, queries1));

    vector<int> nums2 = {4, 3, 1, 6};
    vector<vector<int>> queries2 = {{0, 2}, {2, 3}};
    printVector(solver.isArraySpecial(nums2, queries2));

    return 0;
}