#include <iostream>

using namespace std;

class Solution
{
public:
    int maxProduct(int number)
    {
        int largestDigit = 0;
        int secondLargestDigit = 0;

        while (number > 0)
        {
            int currentDigit = number % 10;

            if (currentDigit > largestDigit)
            {
                secondLargestDigit = largestDigit;
                largestDigit = currentDigit;
            }
            else if (currentDigit > secondLargestDigit)
            {
                secondLargestDigit = currentDigit;
            }

            number /= 10;
        }

        return largestDigit * secondLargestDigit;
    }
};

int main()
{
    Solution solver;

    cout << solver.maxProduct(31) << "\n";
    cout << solver.maxProduct(22) << "\n";
    cout << solver.maxProduct(124) << "\n";
    cout << solver.maxProduct(7389) << "\n";
    cout << solver.maxProduct(99) << "\n";
    cout << solver.maxProduct(10) << "\n";

    return 0;
}