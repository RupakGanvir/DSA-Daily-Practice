#include <iostream>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;

        int prev2 = 1;
        int prev1 = 2;

        for (int i = 3; i <= n; ++i)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    int n1 = 2;
    cout << "--- Test Case 1 ---\n";
    cout << "Ways to climb: " << solver.climbStairs(n1) << "\n\n";

    int n2 = 3;
    cout << "--- Test Case 2 ---\n";
    cout << "Ways to climb: " << solver.climbStairs(n2) << "\n\n";

    int n3 = 45;
    cout << "--- Test Case 3 ---\n";
    cout << "Ways to climb: " << solver.climbStairs(n3) << "\n";

    return 0;
}