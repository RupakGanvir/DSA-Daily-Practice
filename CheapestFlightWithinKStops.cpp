#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto &f : flights)
        {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;

        while (!q.empty() && stops <= k)
        {
            int sz = q.size();
            while (sz--)
            {
                int u = q.front().first;
                int cost = q.front().second;
                q.pop();

                for (const auto &edge : adj[u])
                {
                    int v = edge.first;
                    int w = edge.second;

                    if (cost + w < dist[v])
                    {
                        dist[v] = cost + w;
                        q.push({v, dist[v]});
                    }
                }
            }
            stops++;
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int n1 = 4;
    vector<vector<int>> flights1 = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int src1 = 0, dst1 = 3, k1 = 1;

    cout << "--- Test Case 1 ---\n";
    cout << "Cheapest Price: " << solver.findCheapestPrice(n1, flights1, src1, dst1, k1) << "\n\n";

    int n2 = 3;
    vector<vector<int>> flights2 = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src2 = 0, dst2 = 2, k2 = 1;

    cout << "--- Test Case 2 ---\n";
    cout << "Cheapest Price: " << solver.findCheapestPrice(n2, flights2, src2, dst2, k2) << "\n\n";

    int n3 = 3;
    vector<vector<int>> flights3 = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src3 = 0, dst3 = 2, k3 = 0;

    cout << "--- Test Case 3 ---\n";
    cout << "Cheapest Price: " << solver.findCheapestPrice(n3, flights3, src3, dst3, k3) << "\n";

    return 0;
}