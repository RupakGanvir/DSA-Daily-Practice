#include <iostream>

using namespace std;

class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        int count2 = __builtin_popcount(num2);
        int x = 0;

        for (int i = 31; i >= 0 && count2 > 0; i--)
        {
            if ((num1 >> i) & 1)
            {
                x |= (1 << i);
                count2--;
            }
        }

        for (int i = 0; i <= 31 && count2 > 0; i++)
        {
            if (((x >> i) & 1) == 0)
            {
                x |= (1 << i);
                count2--;
            }
        }

        return x;
    }
};

int main()
{
    Solution solver;

    cout << solver.minimizeXor(3, 5) << "\n";
    cout << solver.minimizeXor(1, 12) << "\n";
    cout << solver.minimizeXor(25, 72) << "\n";

    return 0;
}