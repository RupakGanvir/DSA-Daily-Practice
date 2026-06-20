#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxBuilding(int n, vector<vector<int>> &restrictions)
    {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        for (int i = 1; i < m; i++)
        {
            int id1 = restrictions[i - 1][0];
            int h1 = restrictions[i - 1][1];
            int id2 = restrictions[i][0];
            int h2 = restrictions[i][1];
            restrictions[i][1] = min(h2, h1 + (id2 - id1));
        }

        for (int i = m - 2; i >= 0; i--)
        {
            int id1 = restrictions[i][0];
            int h1 = restrictions[i][1];
            int id2 = restrictions[i + 1][0];
            int h2 = restrictions[i + 1][1];
            restrictions[i][1] = min(h1, h2 + (id2 - id1));
        }

        int max_h = 0;
        for (int i = 1; i < m; i++)
        {
            int id1 = restrictions[i - 1][0];
            int h1 = restrictions[i - 1][1];
            int id2 = restrictions[i][0];
            int h2 = restrictions[i][1];
            int current_max = (h1 + h2 + (id2 - id1)) / 2;
            max_h = max(max_h, current_max);
        }

        max_h = max(max_h, restrictions.back()[1] + (n - restrictions.back()[0]));

        return max_h;
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> r1 = {{2, 1}, {4, 1}};
    vector<vector<int>> r2 = {};
    vector<vector<int>> r3 = {{4, 3}, {2, 0}};

    cout << "--- Maximum Building Height Tests ---" << endl;
    cout << "Test 1: " << solver.maxBuilding(5, r1) << endl;
    cout << "Test 2: " << solver.maxBuilding(6, r2) << endl;
    cout << "Test 3: " << solver.maxBuilding(10, r3) << endl;

    return 0;
}