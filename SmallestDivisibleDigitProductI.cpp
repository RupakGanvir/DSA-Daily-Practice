#include <iostream>

using namespace std;

class Solution
{
private:
    int getDigitProduct(int num)
    {
        int product = 1;
        while (num > 0)
        {
            product *= (num % 10);
            num /= 10;
        }
        return product;
    }

public:
    int smallestNumber(int n, int t)
    {
        int curr = n;
        while (true)
        {
            if (getDigitProduct(curr) % t == 0)
            {
                return curr;
            }
            curr++;
        }
    }
};

int main()
{
    Solution solver;

    cout << solver.smallestNumber(10, 2) << "\n";
    cout << solver.smallestNumber(15, 3) << "\n";
    cout << solver.smallestNumber(11, 4) << "\n";

    return 0;
}