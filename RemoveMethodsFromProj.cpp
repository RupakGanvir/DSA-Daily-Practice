#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {
        vector<vector<int>> adj(n);
        for (const auto &inv : invocations)
        {
            adj[inv[0]].push_back(inv[1]);
        }

        vector<bool> suspicious(n, false);
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int next_node : adj[curr])
            {
                if (!suspicious[next_node])
                {
                    suspicious[next_node] = true;
                    q.push(next_node);
                }
            }
        }

        bool can_remove = true;
        for (const auto &inv : invocations)
        {
            if (!suspicious[inv[0]] && suspicious[inv[1]])
            {
                can_remove = false;
                break;
            }
        }

        vector<int> result;
        if (!can_remove)
        {
            for (int i = 0; i < n; ++i)
            {
                result.push_back(i);
            }
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                if (!suspicious[i])
                {
                    result.push_back(i);
                }
            }
        }

        return result;
    }
};

void printVector(const vector<int> &vec)
{
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    cout << "]\n";
}

int main()
{
    Solution solver;

    int n1 = 4, k1 = 1;
    vector<vector<int>> inv1 = {{1, 2}, {0, 1}, {3, 2}};
    printVector(solver.remainingMethods(n1, k1, inv1));

    int n2 = 5, k2 = 0;
    vector<vector<int>> inv2 = {{1, 2}, {0, 2}, {0, 1}, {3, 4}};
    printVector(solver.remainingMethods(n2, k2, inv2));

    int n3 = 3, k3 = 2;
    vector<vector<int>> inv3 = {{1, 2}, {0, 1}, {2, 0}};
    printVector(solver.remainingMethods(n3, k3, inv3));

    return 0;
}