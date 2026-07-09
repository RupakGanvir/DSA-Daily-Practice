#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto &t : times)
        {
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty())
        {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u])
                continue;

            for (const auto &edge : adj[u])
            {
                int v = edge.first;
                int w = edge.second;

                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<vector<int>> times1 = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n1 = 4, k1 = 2;

    cout << "--- Test Case 1 ---\n";
    cout << "Network Delay Time: " << solver.networkDelayTime(times1, n1, k1) << "\n\n";

    vector<vector<int>> times2 = {{1, 2, 1}};
    int n2 = 2, k2 = 1;

    cout << "--- Test Case 2 ---\n";
    cout << "Network Delay Time: " << solver.networkDelayTime(times2, n2, k2) << "\n\n";

    vector<vector<int>> times3 = {{1, 2, 1}};
    int n3 = 2, k3 = 2;

    cout << "--- Test Case 3 ---\n";
    cout << "Network Delay Time: " << solver.networkDelayTime(times3, n3, k3) << "\n";

    return 0;
}