#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (const auto &relation : relations)
        {
            int u = relation[0] - 1;
            int v = relation[1] - 1;
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> dist(n, 0);

        for (int i = 0; i < n; ++i)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
            dist[i] = time[i];
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                dist[v] = max(dist[v], dist[u] + time[v]);
                if (--indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        return *max_element(dist.begin(), dist.end());
    }
};

int main()
{
    Solution solver;

    int n1 = 3;
    vector<vector<int>> relations1 = {{1, 3}, {2, 3}};
    vector<int> time1 = {3, 2, 5};
    cout << solver.minimumTime(n1, relations1, time1) << "\n";

    int n2 = 5;
    vector<vector<int>> relations2 = {{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};
    vector<int> time2 = {1, 2, 3, 4, 5};
    cout << solver.minimumTime(n2, relations2, time2) << "\n";

    return 0;
}