#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
    {
        int n = aliceValues.size();
        vector<pair<int, int>> stones(n);

        for (int i = 0; i < n; ++i)
        {
            stones[i] = {aliceValues[i] + bobValues[i], i};
        }

        sort(stones.rbegin(), stones.rend());

        int alice_score = 0;
        int bob_score = 0;

        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                alice_score += aliceValues[stones[i].second];
            }
            else
            {
                bob_score += bobValues[stones[i].second];
            }
        }

        if (alice_score > bob_score)
            return 1;
        if (alice_score < bob_score)
            return -1;
        return 0;
    }
};

int main()
{
    Solution solver;

    vector<int> alice1 = {1, 3};
    vector<int> bob1 = {2, 1};
    cout << solver.stoneGameVI(alice1, bob1) << "\n";

    vector<int> alice2 = {1, 2};
    vector<int> bob2 = {3, 1};
    cout << solver.stoneGameVI(alice2, bob2) << "\n";

    vector<int> alice3 = {2, 4, 3};
    vector<int> bob3 = {1, 6, 7};
    cout << solver.stoneGameVI(alice3, bob3) << "\n";

    return 0;
}