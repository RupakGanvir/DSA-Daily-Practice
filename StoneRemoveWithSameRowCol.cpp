#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    unordered_map<int, int> parent;
    int components;

    int find_set(int v)
    {
        if (parent.find(v) == parent.end())
        {
            parent[v] = v;
            components++;
        }
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b)
    {
        int rootA = find_set(a);
        int rootB = find_set(b);
        if (rootA != rootB)
        {
            parent[rootA] = rootB;
            components--;
        }
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        parent.clear();
        components = 0;

        for (const auto &stone : stones)
        {
            union_sets(stone[0], ~stone[1]);
        }

        return stones.size() - components;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    vector<vector<int>> stones1 = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    cout << "--- Test Case 1 ---\n";
    cout << "Max stones removed: " << solver.removeStones(stones1) << "\n\n";

    vector<vector<int>> stones2 = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
    cout << "--- Test Case 2 ---\n";
    cout << "Max stones removed: " << solver.removeStones(stones2) << "\n\n";

    vector<vector<int>> stones3 = {{0, 0}};
    cout << "--- Test Case 3 ---\n";
    cout << "Max stones removed: " << solver.removeStones(stones3) << "\n";

    return 0;
}