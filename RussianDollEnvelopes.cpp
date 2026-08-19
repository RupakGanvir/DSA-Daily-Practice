#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        if (envelopes.empty())
            return 0;

        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b)
             {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0]; });

        vector<int> dp;
        for (const auto &env : envelopes)
        {
            int height = env[1];
            auto it = lower_bound(dp.begin(), dp.end(), height);
            if (it == dp.end())
            {
                dp.push_back(height);
            }
            else
            {
                *it = height;
            }
        }

        return dp.size();
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> envelopes1 = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    cout << solver.maxEnvelopes(envelopes1) << "\n";

    vector<vector<int>> envelopes2 = {{1, 1}, {1, 1}, {1, 1}};
    cout << solver.maxEnvelopes(envelopes2) << "\n";

    return 0;
}