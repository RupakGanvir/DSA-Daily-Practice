#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0]; });

        int count = 0;
        int max_end = 0;

        for (const auto &interval : intervals)
        {
            if (interval[1] <= max_end)
            {
                count++;
            }
            else
            {
                max_end = interval[1];
            }
        }

        return intervals.size() - count;
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> intervals1 = {{1, 4}, {3, 6}, {2, 8}};
    cout << "Remaining intervals: " << solver.removeCoveredIntervals(intervals1) << "\n";

    vector<vector<int>> intervals2 = {{1, 4}, {2, 3}};
    cout << "Remaining intervals: " << solver.removeCoveredIntervals(intervals2) << "\n";

    return 0;
}