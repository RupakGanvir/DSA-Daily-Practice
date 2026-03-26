#include <iostream>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        long long N = n;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        double current_product = x;

        while (N > 0)
        {
            if (N % 2 == 1)
            {
                result *= current_product;
            }
            current_product *= current_product;
            N /= 2;
        }

        return result;
    }
};

int main()
{
    Solution sol;

    cout << "2.0^10 = " << sol.myPow(2.0, 10) << endl;
    cout << "2.1^3  = " << sol.myPow(2.1, 3) << endl;
    cout << "2.0^-2 = " << sol.myPow(2.0, -2) << endl;

    return 0;
}