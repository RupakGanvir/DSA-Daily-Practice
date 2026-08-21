#include <iostream>

using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        while (right > left)
        {
            right &= (right - 1);
        }
        return right;
    }
};

int main()
{
    Solution solver;

    int left1 = 5, right1 = 7;
    cout << solver.rangeBitwiseAnd(left1, right1) << "\n";

    int left2 = 0, right2 = 0;
    cout << solver.rangeBitwiseAnd(left2, right2) << "\n";

    int left3 = 1, right3 = 2147483647;
    cout << solver.rangeBitwiseAnd(left3, right3) << "\n";

    return 0;
}