#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        priority_queue<int, vector<int>, greater<int>> pq_left, pq_right;
        long long ans = 0;
        int left = 0;
        int right = costs.size() - 1;

        while (k > 0)
        {
            while (pq_left.size() < candidates && left <= right)
            {
                pq_left.push(costs[left++]);
            }
            while (pq_right.size() < candidates && left <= right)
            {
                pq_right.push(costs[right--]);
            }

            int cost_left = !pq_left.empty() ? pq_left.top() : INT_MAX;
            int cost_right = !pq_right.empty() ? pq_right.top() : INT_MAX;

            if (cost_left <= cost_right)
            {
                ans += cost_left;
                pq_left.pop();
            }
            else
            {
                ans += cost_right;
                pq_right.pop();
            }
            k--;
        }
        return ans;
    }
};

int main()
{
    Solution solver;

    vector<int> costs1 = {17, 12, 10, 2, 7, 2, 11, 20, 8};
    int k1 = 3;
    int candidates1 = 4;
    cout << solver.totalCost(costs1, k1, candidates1) << "\n";

    vector<int> costs2 = {1, 2, 4, 1};
    int k2 = 3;
    int candidates2 = 3;
    cout << solver.totalCost(costs2, k2, candidates2) << "\n";

    return 0;
}