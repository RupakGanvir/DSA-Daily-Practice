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
    vector<bool> pathQueries(int n, vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);

        for (const auto &edge : edges)
        {
            union_sets(edge[0], edge[1]);
        }

        vector<bool> ans;
        for (const auto &query : queries)
        {
            ans.push_back(find_set(query[0]) == find_set(query[1]));
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;
    cout << boolalpha;

    // Test Case 1
    int n1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}};
    vector<vector<int>> queries1 = {{0, 2}, {2, 0}};

    cout << "--- Test Case 1 ---\n";
    vector<bool> res1 = solver.pathQueries(n1, edges1, queries1);
    for (size_t i = 0; i < queries1.size(); i++)
    {
        cout << "Path between " << queries1[i][0] << " and " << queries1[i][1]
             << "? -> " << res1[i] << "\n";
    }
    cout << "\n";

    // Test Case 2
    int n2 = 6;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    vector<vector<int>> queries2 = {{0, 5}, {3, 4}};

    cout << "--- Test Case 2 ---\n";
    vector<bool> res2 = solver.pathQueries(n2, edges2, queries2);
    for (size_t i = 0; i < queries2.size(); i++)
    {
        cout << "Path between " << queries2[i][0] << " and " << queries2[i][1]
             << "? -> " << res2[i] << "\n";
    }

    return 0;
}