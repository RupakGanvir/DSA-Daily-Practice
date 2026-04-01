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

        for (int i = 1; i < n; i++)
        {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string res = "";
        k = k - 1;

        while (true)
        {
            res += to_string(numbers[k / fact]);

            numbers.erase(numbers.begin() + k / fact);

            if (numbers.empty())
                break;

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

    cout << "The " << k << "th permutation of " << n << " is: " << sol.getPermutation(n, k) << endl;

    return 0;
}