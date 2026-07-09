#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
private:
    vector<int> parent;
    vector<int> rank;

    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);

        int components = n;
        for (const auto &conn : connections)
        {
            int u = find_set(conn[0]);
            int v = find_set(conn[1]);

            if (u != v)
            {
                union_sets(u, v);
                components--;
            }
        }

        return components - 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int n1 = 4;
    vector<vector<int>> connections1 = {{0, 1}, {0, 2}, {1, 2}};
    cout << "--- Test Case 1 ---\n";
    cout << "Operations needed: " << solver.makeConnected(n1, connections1) << "\n\n";

    int n2 = 6;
    vector<vector<int>> connections2 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    cout << "--- Test Case 2 ---\n";
    cout << "Operations needed: " << solver.makeConnected(n2, connections2) << "\n\n";

    int n3 = 6;
    vector<vector<int>> connections3 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
    cout << "--- Test Case 3 ---\n";
    cout << "Operations needed: " << solver.makeConnected(n3, connections3) << "\n";

    return 0;
}