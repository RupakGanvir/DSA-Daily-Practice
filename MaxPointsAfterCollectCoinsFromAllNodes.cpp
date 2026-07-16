#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    vector<vector<int>> adj;
    vector<vector<int>> memo;
    int k_val;

    int dfs(int u, int p, int shifts, const vector<int> &coins)
    {
        if (shifts >= 14)
            shifts = 14;

        if (memo[u][shifts] != -1)
        {
            return memo[u][shifts];
        }

        int current_coins = coins[u] >> shifts;
        int opt1 = current_coins - k_val;
        int opt2 = current_coins / 2;

        for (int v : adj[u])
        {
            if (v != p)
            {
                opt1 += dfs(v, u, shifts, coins);
                opt2 += dfs(v, u, shifts + 1, coins);
            }
        }

        return memo[u][shifts] = max(opt1, opt2);
    }

public:
    int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int k)
    {
        int n = coins.size();
        adj.assign(n, vector<int>());
        memo.assign(n, vector<int>(15, -1));
        k_val = k;

        for (const auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return dfs(0, -1, 0, coins);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 3}};
    vector<int> coins1 = {10, 10, 3, 3};
    int k1 = 5;
    cout << "--- Test Case 1 ---\n";
    cout << "Maximum Points: " << solver.maximumPoints(edges1, coins1, k1) << "\n\n";

    vector<vector<int>> edges2 = {{0, 1}, {0, 2}};
    vector<int> coins2 = {8, 4, 4};
    int k2 = 0;
    cout << "--- Test Case 2 ---\n";
    cout << "Maximum Points: " << solver.maximumPoints(edges2, coins2, k2) << "\n\n";

    vector<vector<int>> edges3 = {{0, 1}};
    vector<int> coins3 = {10, 10};
    int k3 = 1;
    cout << "--- Test Case 3 ---\n";
    cout << "Maximum Points: " << solver.maximumPoints(edges3, coins3, k3) << "\n";

    return 0;
}