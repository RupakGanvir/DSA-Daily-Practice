#include <iostream>

using namespace std;

class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            ans ^= n;
            n >>= 1;
        }
        return ans;
    }
};

int main()
{
    Solution solver;

    int n1 = 3;
    cout << solver.minimumOneBitOperations(n1) << "\n";

    int n2 = 6;
    cout << solver.minimumOneBitOperations(n2) << "\n";

    int n3 = 9;
    cout << solver.minimumOneBitOperations(n3) << "\n";

    return 0;
}