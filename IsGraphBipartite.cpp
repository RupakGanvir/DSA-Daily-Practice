#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, 0);

        for (int i = 0; i < n; ++i)
        {
            if (color[i] != 0)
                continue;

            queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();

                for (int neighbor : graph[curr])
                {
                    if (color[neighbor] == 0)
                    {
                        color[neighbor] = -color[curr];
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[curr])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> graph1 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << "Graph 1 is bipartite: " << (solver.isBipartite(graph1) ? "true" : "false") << "\n";

    vector<vector<int>> graph2 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << "Graph 2 is bipartite: " << (solver.isBipartite(graph2) ? "true" : "false") << "\n";

    return 0;
}