#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findCrossingTime(int n, int k, vector<vector<int>> &time)
    {
        // Comparator to give priority to less efficient workers
        auto cmpWait = [&](int i, int j)
        {
            int eff_i = time[i][0] + time[i][2];
            int eff_j = time[j][0] + time[j][2];
            if (eff_i != eff_j)
                return eff_i < eff_j;
            return i < j;
        };

        priority_queue<int, vector<int>, decltype(cmpWait)> leftWait(cmpWait);
        priority_queue<int, vector<int>, decltype(cmpWait)> rightWait(cmpWait);

        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> leftWork;
        priority_queue<pii, vector<pii>, greater<pii>> rightWork;

        for (int i = 0; i < k; ++i)
        {
            leftWait.push(i);
        }

        int currTime = 0;
        int boxesRemaining = n;
        int boxesDelivered = 0;

        while (boxesDelivered < n)
        {
            // Move workers from work queues to wait queues if they have finished their task
            while (!leftWork.empty() && leftWork.top().first <= currTime)
            {
                leftWait.push(leftWork.top().second);
                leftWork.pop();
            }
            while (!rightWork.empty() && rightWork.top().first <= currTime)
            {
                rightWait.push(rightWork.top().second);
                rightWork.pop();
            }

            // Check bridge access based on rules
            if (!rightWait.empty())
            {
                int id = rightWait.top();
                rightWait.pop();
                currTime += time[id][2]; // Cross right to left
                boxesDelivered++;

                if (boxesDelivered == n)
                {
                    return currTime; // Reached the left side with the last box
                }

                leftWork.push({currTime + time[id][3], id}); // Put box in left warehouse
            }
            else if (!leftWait.empty() && boxesRemaining > 0)
            {
                int id = leftWait.top();
                leftWait.pop();
                currTime += time[id][0]; // Cross left to right
                boxesRemaining--;

                rightWork.push({currTime + time[id][1], id}); // Pick box from right warehouse
            }
            else
            {
                // If the bridge is idle, fast forward time to the next earliest completion event
                int nextTime = 2e9;
                if (!leftWork.empty())
                    nextTime = min(nextTime, leftWork.top().first);
                if (!rightWork.empty())
                    nextTime = min(nextTime, rightWork.top().first);
                currTime = max(currTime, nextTime);
            }
        }

        return currTime;
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> time1 = {{1, 1, 2, 1}, {1, 1, 3, 1}, {1, 1, 4, 1}};
    int n1 = 1, k1 = 3;
    cout << solver.findCrossingTime(n1, k1, time1) << "\n";

    vector<vector<int>> time2 = {{1, 9, 1, 8}, {10, 10, 10, 10}};
    int n2 = 3, k2 = 2;
    cout << solver.findCrossingTime(n2, k2, time2) << "\n";

    return 0;
}