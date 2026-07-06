#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> order;

        for (const auto &pre : prerequisites)
        {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            for (int neighbor : adj[curr])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        if (order.size() == numCourses)
        {
            return order;
        }

        return {};
    }
};

int main()
{
    Solution solver;

    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    vector<int> result1 = solver.findOrder(numCourses1, prerequisites1);

    cout << "Order 1: ";
    for (int course : result1)
        cout << course << " ";
    cout << "\n";

    int numCourses2 = 4;
    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> result2 = solver.findOrder(numCourses2, prerequisites2);

    cout << "Order 2: ";
    for (int course : result2)
        cout << course << " ";
    cout << "\n";

    return 0;
}