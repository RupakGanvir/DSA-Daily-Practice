#include <iostream>

using namespace std;

class Solution
{
public:
    long long processInteger(int n)
    {
        long long concatenatedNum = 0;
        long long sumOfDigits = 0;
        long long placeValueMultiplier = 1;

        while (n > 0)
        {
            int digit = n % 10;
            n /= 10;

            if (digit != 0)
            {
                concatenatedNum = digit * placeValueMultiplier + concatenatedNum;
                sumOfDigits += digit;
                placeValueMultiplier *= 10;
            }
        }

        return concatenatedNum * sumOfDigits;
    }
};

int main()
{
    Solution solver;

    int n1 = 10230;
    cout << "Result: " << solver.processInteger(n1) << "\n";

    int n2 = 506;
    cout << "Result: " << solver.processInteger(n2) << "\n";

    return 0;
}