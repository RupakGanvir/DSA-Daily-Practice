#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    long long get_gcd(long long a, long long b)
    {
        while (b != 0)
        {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    long long findKthSmallest(vector<int> &coins, int k)
    {
        int n = coins.size();
        vector<long long> subset_lcm(1 << n, 1);
        vector<int> set_bits(1 << n, 0);

        long long max_limit = 1e15;

        for (int mask = 1; mask < (1 << n); ++mask)
        {
            long long current_lcm = 1;
            int bits = 0;

            for (int i = 0; i < n; ++i)
            {
                if ((mask >> i) & 1)
                {
                    bits++;
                    long long g = get_gcd(current_lcm, coins[i]);
                    long long mult = coins[i] / g;

                    if (current_lcm > max_limit / mult)
                    {
                        current_lcm = max_limit + 1;
                    }
                    else
                    {
                        current_lcm *= mult;
                    }
                }
            }
            subset_lcm[mask] = current_lcm;
            set_bits[mask] = bits;
        }

        long long low = 1;
        long long high = 0;
        for (int coin : coins)
        {
            if (high == 0 || (long long)coin * k < high)
            {
                high = (long long)coin * k;
            }
        }

        long long ans = high;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long count = 0;

            for (int mask = 1; mask < (1 << n); ++mask)
            {
                if (set_bits[mask] % 2 == 1)
                {
                    count += mid / subset_lcm[mask];
                }
                else
                {
                    count -= mid / subset_lcm[mask];
                }
            }

            if (count >= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    vector<int> coins1 = {3, 6, 9};
    int k1 = 3;
    cout << solver.findKthSmallest(coins1, k1) << "\n";

    vector<int> coins2 = {5, 2};
    int k2 = 7;
    cout << solver.findKthSmallest(coins2, k2) << "\n";

    return 0;
}