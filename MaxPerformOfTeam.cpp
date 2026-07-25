#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<pair<int, int>> engineers(n);
        for (int i = 0; i < n; ++i)
        {
            engineers[i] = {efficiency[i], speed[i]};
        }

        sort(engineers.rbegin(), engineers.rend());

        priority_queue<int, vector<int>, greater<int>> speedHeap;
        long long speedSum = 0;
        long long maxPerf = 0;

        for (int i = 0; i < n; ++i)
        {
            int currEfficiency = engineers[i].first;
            int currSpeed = engineers[i].second;

            speedHeap.push(currSpeed);
            speedSum += currSpeed;

            if (speedHeap.size() > k)
            {
                speedSum -= speedHeap.top();
                speedHeap.pop();
            }

            maxPerf = max(maxPerf, speedSum * currEfficiency);
        }

        return maxPerf % 1000000007;
    }
};

int main()
{
    Solution solver;

    int n1 = 6;
    vector<int> speed1 = {2, 10, 3, 1, 5, 8};
    vector<int> efficiency1 = {5, 4, 3, 9, 7, 2};
    int k1 = 2;
    cout << solver.maxPerformance(n1, speed1, efficiency1, k1) << "\n";

    int n2 = 6;
    vector<int> speed2 = {2, 10, 3, 1, 5, 8};
    vector<int> efficiency2 = {5, 4, 3, 9, 7, 2};
    int k2 = 3;
    cout << solver.maxPerformance(n2, speed2, efficiency2, k2) << "\n";

    int n3 = 6;
    vector<int> speed3 = {2, 10, 3, 1, 5, 8};
    vector<int> efficiency3 = {5, 4, 3, 9, 7, 2};
    int k3 = 4;
    cout << solver.maxPerformance(n3, speed3, efficiency3, k3) << "\n";

    int n4 = 3;
    vector<int> speed4 = {2, 8, 2};
    vector<int> efficiency4 = {2, 7, 1};
    int k4 = 2;
    cout << solver.maxPerformance(n4, speed4, efficiency4, k4) << "\n";

    return 0;
}