#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void dfs(int curr, int n, const vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        visited[curr] = true;
        for (int next = 0; next < n; ++next)
        {
            if (isConnected[curr][next] == 1 && !visited[next])
            {
                dfs(next, n, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int provinces = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                provinces++;
                dfs(i, n, isConnected, visited);
            }
        }
        return provinces;
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};

    cout << "Number of Provinces: " << solver.findCircleNum(isConnected) << endl;

    return 0;
}