#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
        {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        int eliminationCount = 0;
        int prevEnd = intervals[0][1];

        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < prevEnd)
            {
                eliminationCount++;
            }
            else
            {
                prevEnd = intervals[i][1];
            }
        }

        return eliminationCount;
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    vector<vector<int>> intervals2 = {{1, 2}, {1, 2}, {1, 2}};
    vector<vector<int>> intervals3 = {{1, 2}, {2, 3}};

    cout << "--- Non-overlapping Intervals Tests ---" << endl;
    cout << "Test 1: " << solver.eraseOverlapIntervals(intervals1) << endl;
    cout << "Test 2: " << solver.eraseOverlapIntervals(intervals2) << endl;
    cout << "Test 3: " << solver.eraseOverlapIntervals(intervals3) << endl;

    return 0;
}