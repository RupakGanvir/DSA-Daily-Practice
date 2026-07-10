#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for (const auto &conn : connections)
        {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        vector<vector<int>> bridges;
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        int time = 0;

        auto dfs = [&](auto &self, int u, int p) -> void
        {
            disc[u] = low[u] = ++time;
            for (int v : adj[u])
            {
                if (v == p)
                    continue;
                if (disc[v] != -1)
                {
                    low[u] = min(low[u], disc[v]);
                }
                else
                {
                    self(self, v, u);
                    low[u] = min(low[u], low[v]);
                    if (low[v] > disc[u])
                    {
                        bridges.push_back({u, v});
                    }
                }
            }
        };

        dfs(dfs, 0, -1);
        return bridges;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int n1 = 4;
    vector<vector<int>> connections1 = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};

    cout << "--- Test Case 1 ---\n";
    vector<vector<int>> res1 = solver.criticalConnections(n1, connections1);
    cout << "Critical Connections: \n";
    for (const auto &edge : res1)
    {
        cout << "[" << edge[0] << ", " << edge[1] << "]\n";
    }
    cout << "\n";

    int n2 = 2;
    vector<vector<int>> connections2 = {{0, 1}};

    cout << "--- Test Case 2 ---\n";
    vector<vector<int>> res2 = solver.criticalConnections(n2, connections2);
    cout << "Critical Connections: \n";
    for (const auto &edge : res2)
    {
        cout << "[" << edge[0] << ", " << edge[1] << "]\n";
    }

    return 0;
}