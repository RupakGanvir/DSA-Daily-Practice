#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minimumEffort(vector<vector<int>> &tasks)
    {
        sort(tasks.begin(), tasks.end(), [](const vector<int> &a, const vector<int> &b)
             { return (a[1] - a[0]) > (b[1] - b[0]); });

        int initial_energy = 0;
        int current_energy = 0;

        for (const auto &task : tasks)
        {
            if (current_energy < task[1])
            {
                initial_energy += (task[1] - current_energy);
                current_energy = task[1];
            }
            current_energy -= task[0];
        }

        return initial_energy;
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> tasks1 = {{1, 2}, {2, 4}, {4, 8}};
    cout << solver.minimumEffort(tasks1) << "\n";

    vector<vector<int>> tasks2 = {{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}};
    cout << solver.minimumEffort(tasks2) << "\n";

    vector<vector<int>> tasks3 = {{1, 7}, {2, 8}, {3, 9}, {4, 10}, {5, 11}, {6, 12}};
    cout << solver.minimumEffort(tasks3) << "\n";

    return 0;
}