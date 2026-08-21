#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findKthNumber(int m, int n, int k)
    {
        int low = 1;
        int high = m * n;

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int count = 0;

            for (int i = 1; i <= m; ++i)
            {
                count += min(mid / i, n);
            }

            if (count >= k)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main()
{
    Solution solver;

    int m1 = 3, n1 = 3, k1 = 5;
    cout << solver.findKthNumber(m1, n1, k1) << "\n";

    int m2 = 2, n2 = 3, k2 = 6;
    cout << solver.findKthNumber(m2, n2, k2) << "\n";

    return 0;
}