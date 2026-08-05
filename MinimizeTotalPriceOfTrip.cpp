#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    bool findPath(int curr, int target, int parent, vector<vector<int>> &adj, vector<int> &count)
    {
        if (curr == target)
        {
            count[curr]++;
            return true;
        }
        for (int neighbor : adj[curr])
        {
            if (neighbor != parent)
            {
                if (findPath(neighbor, target, curr, adj, count))
                {
                    count[curr]++;
                    return true;
                }
            }
        }
        return false;
    }

    pair<int, int> dfs(int curr, int parent, vector<vector<int>> &adj, vector<int> &price, vector<int> &count)
    {
        int not_halved = price[curr] * count[curr];
        int halved = (price[curr] / 2) * count[curr];

        for (int neighbor : adj[curr])
        {
            if (neighbor != parent)
            {
                pair<int, int> child_costs = dfs(neighbor, curr, adj, price, count);
                not_halved += min(child_costs.first, child_costs.second);
                halved += child_costs.first;
            }
        }
        return {not_halved, halved};
    }

public:
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips)
    {
        vector<vector<int>> adj(n);
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> count(n, 0);
        for (const auto &trip : trips)
        {
            findPath(trip[0], trip[1], -1, adj, count);
        }

        pair<int, int> ans = dfs(0, -1, adj, price, count);
        return min(ans.first, ans.second);
    }
};

int main()
{
    Solution solver;

    int n1 = 4;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {1, 3}};
    vector<int> price1 = {2, 2, 10, 6};
    vector<vector<int>> trips1 = {{0, 3}, {2, 1}, {2, 3}};
    cout << solver.minimumTotalPrice(n1, edges1, price1, trips1) << "\n";

    int n2 = 2;
    vector<vector<int>> edges2 = {{0, 1}};
    vector<int> price2 = {2, 2};
    vector<vector<int>> trips2 = {{0, 0}};
    cout << solver.minimumTotalPrice(n2, edges2, price2, trips2) << "\n";

    return 0;
}