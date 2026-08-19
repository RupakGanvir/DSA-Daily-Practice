#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
private:
    int A(int m, int k)
    {
        if (k == 0)
            return 1;
        int res = 1;
        for (int i = 0; i < k; ++i)
        {
            res *= (m - i);
        }
        return res;
    }

public:
    int numDupDigitsAtMostN(int n)
    {
        vector<int> digits;
        int temp = n;
        while (temp > 0)
        {
            digits.push_back(temp % 10);
            temp /= 10;
        }

        int length = digits.size();
        for (int i = 0; i < length / 2; ++i)
        {
            swap(digits[i], digits[length - 1 - i]);
        }

        int unique_count = 0;
        for (int i = 1; i < length; ++i)
        {
            unique_count += 9 * A(9, i - 1);
        }

        unordered_set<int> seen;
        for (int i = 0; i < length; ++i)
        {
            int start = (i == 0) ? 1 : 0;
            for (int d = start; d < digits[i]; ++d)
            {
                if (seen.find(d) == seen.end())
                {
                    unique_count += A(9 - i, length - 1 - i);
                }
            }
            if (seen.find(digits[i]) != seen.end())
            {
                break;
            }
            seen.insert(digits[i]);
        }

        if (seen.size() == length)
        {
            unique_count++;
        }

        return n - unique_count;
    }
};

int main()
{
    Solution solver;

    int n1 = 20;
    cout << solver.numDupDigitsAtMostN(n1) << "\n";

    int n2 = 100;
    cout << solver.numDupDigitsAtMostN(n2) << "\n";

    int n3 = 1000;
    cout << solver.numDupDigitsAtMostN(n3) << "\n";

    return 0;
}