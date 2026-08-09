#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int stoneGameVIII(vector<int> &stones)
    {
        int n = stones.size();
        vector<int> prefix(n, 0);
        prefix[0] = stones[0];
        for (int i = 1; i < n; ++i)
        {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        int dp = prefix.back();
        for (int i = n - 2; i >= 1; --i)
        {
            dp = max(dp, prefix[i] - dp);
        }

        return dp;
    }
};

int main()
{
    Solution solver;

    vector<int> stones1 = {-1, 2, -3, 4, -5};
    cout << solver.stoneGameVIII(stones1) << "\n";

    vector<int> stones2 = {7, -6, 5, 10, 5, -2, -6};
    cout << solver.stoneGameVIII(stones2) << "\n";

    vector<int> stones3 = {-10, -12};
    cout << solver.stoneGameVIII(stones3) << "\n";

    return 0;
}