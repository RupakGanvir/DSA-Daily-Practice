#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    bool stoneGameIX(vector<int> &stones)
    {
        vector<int> cnt(3, 0);
        for (int stone : stones)
        {
            cnt[stone % 3]++;
        }

        if (cnt[0] % 2 == 0)
        {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        return abs(cnt[1] - cnt[2]) > 2;
    }
};

int main()
{
    Solution solver;

    vector<int> stones1 = {2, 1};
    cout << (solver.stoneGameIX(stones1) ? "true" : "false") << "\n";

    vector<int> stones2 = {2, 1, 3};
    cout << (solver.stoneGameIX(stones2) ? "true" : "false") << "\n";

    vector<int> stones3 = {5, 1, 2, 4, 3};
    cout << (solver.stoneGameIX(stones3) ? "true" : "false") << "\n";

    return 0;
}