#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
private:
    int getGcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    int gcdOfOddAndEvenSum(int n)
    {
        int even_sum = 0;
        int odd_sum = 0;

        n = abs(n);

        while (n > 0)
        {
            int digit = n % 10;

            if (digit % 2 == 0)
            {
                even_sum += digit;
            }
            else
            {
                odd_sum += digit;
            }

            n /= 10;
        }

        return getGcd(even_sum, odd_sum);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int n1 = 1234;
    cout << "--- Test Case 1 ---\n";
    cout << "GCD of Odd and Even Sum of digits: " << solver.gcdOfOddAndEvenSum(n1) << "\n\n";

    int n2 = 2468;
    cout << "--- Test Case 2 ---\n";
    cout << "GCD of Odd and Even Sum of digits: " << solver.gcdOfOddAndEvenSum(n2) << "\n\n";

    int n3 = 135;
    cout << "--- Test Case 3 ---\n";
    cout << "GCD of Odd and Even Sum of digits: " << solver.gcdOfOddAndEvenSum(n3) << "\n";

    return 0;
}