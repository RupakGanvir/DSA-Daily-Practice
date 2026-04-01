#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> numbers;

        // 1. Precompute (n-1)! and fill numbers list {1, 2, ..., n}
        for (int i = 1; i < n; i++)
        {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string res = "";
        k = k - 1; // Use 0-based indexing for easier math

        while (true)
        {
            // 2. Find the index of the current digit
            res += to_string(numbers[k / fact]);

            // 3. Remove that digit from the available pool
            numbers.erase(numbers.begin() + k / fact);

            if (numbers.empty())
                break;

            // 4. Update k and the factorial for the next position
            k %= fact;
            fact /= numbers.size();
        }

        return res;
    }
};

int main()
{
    Solution sol;
    int n = 4, k = 9;

    // For n=4, k=9, the permutations are:
    // 1234, 1243, 1324, 1342, 1423, 1432 (1-6)
    // 2134, 2143, 2314... (7-9) -> 9th is 2314
    cout << "The " << k << "th permutation of " << n << " is: " << sol.getPermutation(n, k) << endl;

    return 0;
}