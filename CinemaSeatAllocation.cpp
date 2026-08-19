#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        unordered_map<int, int> row_masks;

        for (const auto &seat : reservedSeats)
        {
            row_masks[seat[0]] |= (1 << seat[1]);
        }

        int max_families = (n - row_masks.size()) * 2;

        for (const auto &pair : row_masks)
        {
            int mask = pair.second;

            bool left = (mask & 60) == 0;
            bool right = (mask & 960) == 0;
            bool middle = (mask & 240) == 0;

            if (left && right)
            {
                max_families += 2;
            }
            else if (left || right || middle)
            {
                max_families += 1;
            }
        }

        return max_families;
    }
};

int main()
{
    Solution solver;

    int n1 = 3;
    vector<vector<int>> reserved1 = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
    cout << solver.maxNumberOfFamilies(n1, reserved1) << "\n";

    int n2 = 2;
    vector<vector<int>> reserved2 = {{2, 1}, {1, 8}, {2, 6}};
    cout << solver.maxNumberOfFamilies(n2, reserved2) << "\n";

    int n3 = 4;
    vector<vector<int>> reserved3 = {{4, 3}, {1, 4}, {4, 6}, {1, 7}};
    cout << solver.maxNumberOfFamilies(n3, reserved3) << "\n";

    return 0;
}