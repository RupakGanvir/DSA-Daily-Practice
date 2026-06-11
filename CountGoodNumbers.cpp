#include <iostream>

using namespace std;

class Solution
{
private:
    long long MOD = 1000000007;

    long long power(long long base, long long exp)
    {
        long long res = 1;
        base %= MOD;
        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int countGoodNumbers(long long n)
    {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long choiceEven = power(5, even);
        long long choiceOdd = power(4, odd);

        return (choiceEven * choiceOdd) % MOD;
    }
};

int main()
{
    Solution solver;

    long long n1 = 1;
    long long n2 = 4;
    long long n3 = 50;

    cout << "--- Count Good Numbers Tests ---" << endl;
    cout << "Test 1: " << solver.countGoodNumbers(n1) << endl;
    cout << "Test 2: " << solver.countGoodNumbers(n2) << endl;
    cout << "Test 3: " << solver.countGoodNumbers(n3) << endl;

    return 0;
}