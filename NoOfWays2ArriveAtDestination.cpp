#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, long long>>> adj(n);
        for (const auto &r : roads)
        {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<long long> dist(n, 1e18);
        vector<long long> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        int mod = 1e9 + 7;

        while (!pq.empty())
        {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u])
                continue;

            for (const auto &edge : adj[u])
            {
                int v = edge.first;
                long long w = edge.second;

                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if (dist[u] + w == dist[v])
                {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int n1 = 7;
    vector<vector<int>> roads1 = {
        {0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    cout << "--- Test Case 1 ---\n";
    cout << "Number of ways to arrive at destination: " << solver.countPaths(n1, roads1) << "\n\n";

    int n2 = 2;
    vector<vector<int>> roads2 = {{1, 0, 10}};

    cout << "--- Test Case 2 ---\n";
    cout << "Number of ways to arrive at destination: " << solver.countPaths(n2, roads2) << "\n";

    return 0;
}