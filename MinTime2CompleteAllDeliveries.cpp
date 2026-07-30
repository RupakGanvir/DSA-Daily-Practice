#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    long long gcd(long long a, long long b)
    {
        while (b != 0)
        {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b)
    {
        if (a == 0 || b == 0)
            return 0;
        return (a / gcd(a, b)) * b;
    }

public:
    long long minimumTime(vector<int> &d, vector<int> &r)
    {
        long long lcm_val = lcm((long long)r[0], (long long)r[1]);
        long long left = 1;
        long long right = 1e15;
        long long ans = right;

        while (left <= right)
        {
            long long mid = left + (right - left) / 2;

            long long slots1 = mid - mid / r[0];
            long long slots2 = mid - mid / r[1];
            long long total_slots = mid - mid / lcm_val;

            if (slots1 >= d[0] && slots2 >= d[1] && total_slots >= (long long)d[0] + d[1])
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    vector<int> d1 = {3, 1};
    vector<int> r1 = {2, 3};
    cout << solver.minimumTime(d1, r1) << "\n";

    vector<int> d2 = {1, 3};
    vector<int> r2 = {2, 2};
    cout << solver.minimumTime(d2, r2) << "\n";

    vector<int> d3 = {2, 1};
    vector<int> r3 = {3, 4};
    cout << solver.minimumTime(d3, r3) << "\n";

    return 0;
}