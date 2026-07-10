#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

class Solution
{
public:
    vector<int> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i)
        {
            sorted_nums[i] = {nums[i], i};
        }
        sort(sorted_nums.begin(), sorted_nums.end());

        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
        {
            pos[sorted_nums[i].second] = i;
        }

        vector<array<int, 18>> st(n);
        int right = 0;
        for (int left = 0; left < n; ++left)
        {
            while (right + 1 < n && sorted_nums[right + 1].first - sorted_nums[left].first <= maxDiff)
            {
                right++;
            }
            st[left][0] = right;
        }

        for (int j = 1; j < 18; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                st[i][j] = st[st[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto &q : queries)
        {
            int a = pos[q[0]];
            int b = pos[q[1]];
            if (a == b)
            {
                ans.push_back(0);
                continue;
            }
            if (a > b)
                swap(a, b);

            int curr = a;
            int steps = 0;
            for (int j = 17; j >= 0; --j)
            {
                if (st[curr][j] < b)
                {
                    curr = st[curr][j];
                    steps += (1 << j);
                }
            }
            if (st[curr][0] >= b)
            {
                ans.push_back(steps + 1);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int n1 = 5;
    vector<int> nums1 = {1, 8, 3, 4, 2};
    int maxDiff1 = 3;
    vector<vector<int>> queries1 = {{0, 3}, {2, 4}};

    vector<int> res1 = solver.pathExistenceQueries(n1, nums1, maxDiff1, queries1);
    for (int val : res1)
        cout << val << " ";
    cout << "\n";

    int n2 = 5;
    vector<int> nums2 = {5, 3, 1, 9, 10};
    int maxDiff2 = 2;
    vector<vector<int>> queries2 = {{0, 1}, {0, 2}, {2, 3}, {4, 3}};

    vector<int> res2 = solver.pathExistenceQueries(n2, nums2, maxDiff2, queries2);
    for (int val : res2)
        cout << val << " ";
    cout << "\n";

    return 0;
}