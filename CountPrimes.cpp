#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
        {
            return 0;
        }

        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i < n; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution solver;

    int n1 = 10;
    int n2 = 0;
    int n3 = 1;

    cout << "--- Count Primes Tests ---" << endl;
    cout << "Test 1: " << solver.countPrimes(n1) << endl;
    cout << "Test 2: " << solver.countPrimes(n2) << endl;
    cout << "Test 3: " << solver.countPrimes(n3) << endl;

    return 0;
}