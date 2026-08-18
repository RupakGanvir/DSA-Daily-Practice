#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity)
    {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        int p = 0;
        int current_capacity = 0;

        for (int bus_time : buses)
        {
            current_capacity = capacity;
            while (p < passengers.size() && passengers[p] <= bus_time && current_capacity > 0)
            {
                p++;
                current_capacity--;
            }
        }

        int ans;
        if (current_capacity > 0)
        {
            ans = buses.back();
        }
        else
        {
            ans = passengers[p - 1];
        }

        int j = p - 1;
        while (j >= 0 && passengers[j] == ans)
        {
            ans--;
            j--;
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    vector<int> buses1 = {10, 20};
    vector<int> passengers1 = {2, 17, 18, 19};
    int capacity1 = 2;
    cout << solver.latestTimeCatchTheBus(buses1, passengers1, capacity1) << "\n";

    vector<int> buses2 = {20, 30, 10};
    vector<int> passengers2 = {19, 13, 26, 4, 25, 11, 21};
    int capacity2 = 2;
    cout << solver.latestTimeCatchTheBus(buses2, passengers2, capacity2) << "\n";

    return 0;
}