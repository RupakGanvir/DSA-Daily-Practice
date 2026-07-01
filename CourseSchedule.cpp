#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto &pre : prerequisites)
        {
            adj[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        int completed = 0;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            completed++;

            for (int next : adj[curr])
            {
                inDegree[next]--;
                if (inDegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }

        return completed == numCourses;
    }
};

int main()
{
    Solution solver;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};

    if (solver.canFinish(numCourses, prerequisites))
    {
        cout << "Course schedule is possible." << endl;
    }
    else
    {
        cout << "Course schedule is not possible." << endl;
    }

    return 0;
}