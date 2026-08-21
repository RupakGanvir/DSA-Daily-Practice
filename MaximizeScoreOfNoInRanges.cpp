#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    bool check(const vector<int> &start, int d, long long mid)
    {
        long long prev = start[0];
        for (int i = 1; i < start.size(); ++i)
        {
            long long next_val = max((long long)start[i], prev + mid);
            if (next_val > (long long)start[i] + d)
            {
                return false;
            }
            prev = next_val;
        }
        return true;
    }

public:
    int maxPossibleScore(vector<int> &start, int d)
    {
        sort(start.begin(), start.end());

        long long low = 0;
        long long high = (long long)start.back() + d - start.front();
        long long ans = 0;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (check(start, d, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    vector<int> start1 = {6, 0, 3};
    int d1 = 2;
    cout << solver.maxPossibleScore(start1, d1) << "\n";

    vector<int> start2 = {2, 6, 13, 13};
    int d2 = 5;
    cout << solver.maxPossibleScore(start2, d2) << "\n";

    return 0;
}