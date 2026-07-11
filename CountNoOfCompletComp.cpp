#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeCount = 0;

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                int vCount = 0;
                int eCount = 0;

                auto dfs = [&](auto &self, int u) -> void
                {
                    visited[u] = true;
                    vCount++;
                    eCount += adj[u].size();

                    for (int v : adj[u])
                    {
                        if (!visited[v])
                        {
                            self(self, v);
                        }
                    }
                };

                dfs(dfs, i);

                if (eCount == vCount * (vCount - 1))
                {
                    completeCount++;
                }
            }
        }

        return completeCount;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int n1 = 6;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    cout << "--- Test Case 1 ---\n";
    cout << "Complete Components: " << solver.countCompleteComponents(n1, edges1) << "\n\n";

    int n2 = 6;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};
    cout << "--- Test Case 2 ---\n";
    cout << "Complete Components: " << solver.countCompleteComponents(n2, edges2) << "\n";

    return 0;
}