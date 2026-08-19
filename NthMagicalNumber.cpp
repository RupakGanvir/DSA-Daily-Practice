#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
private:
    long long gcd(long long a, long long b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

public:
    int nthMagicalNumber(int n, int a, int b)
    {
        long long MOD = 1e9 + 7;
        long long L = min(a, b);
        long long R = (long long)n * min(a, b);
        long long lcm_ab = ((long long)a * b) / gcd(a, b);

        while (L < R)
        {
            long long mid = L + (R - L) / 2;
            long long count = (mid / a) + (mid / b) - (mid / lcm_ab);

            if (count < n)
            {
                L = mid + 1;
            }
            else
            {
                R = mid;
            }
        }

        return L % MOD;
    }
};

int main()
{
    Solution solver;

    cout << solver.nthMagicalNumber(1, 2, 3) << "\n";
    cout << solver.nthMagicalNumber(4, 2, 3) << "\n";
    cout << solver.nthMagicalNumber(5, 2, 4) << "\n";

    return 0;
}