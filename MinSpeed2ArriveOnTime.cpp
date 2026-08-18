#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int n = dist.size();

        if (hour <= (double)(n - 1))
        {
            return -1;
        }

        int left = 1;
        int right = 1e7;
        int min_speed = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            double time_taken = 0.0;

            for (int i = 0; i < n - 1; ++i)
            {
                time_taken += ceil((double)dist[i] / mid);
            }
            time_taken += (double)dist.back() / mid;

            if (time_taken <= hour)
            {
                min_speed = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return min_speed;
    }
};

int main()
{
    Solution solver;

    vector<int> dist1 = {1, 3, 2};
    double hour1 = 6.0;
    cout << solver.minSpeedOnTime(dist1, hour1) << "\n";

    vector<int> dist2 = {1, 3, 2};
    double hour2 = 2.7;
    cout << solver.minSpeedOnTime(dist2, hour2) << "\n";

    vector<int> dist3 = {1, 3, 2};
    double hour3 = 1.9;
    cout << solver.minSpeedOnTime(dist3, hour3) << "\n";

    return 0;
}