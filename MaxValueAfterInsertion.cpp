#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string maxValue(string n, int x)
    {
        char x_char = x + '0';

        if (n[0] == '-')
        {
            for (int i = 1; i < n.length(); i++)
            {
                if (n[i] > x_char)
                {
                    n.insert(i, 1, x_char);
                    return n;
                }
            }
        }
        else
        {
            for (int i = 0; i < n.length(); i++)
            {
                if (n[i] < x_char)
                {
                    n.insert(i, 1, x_char);
                    return n;
                }
            }
        }

        n += x_char;
        return n;
    }
};

int main()
{
    Solution solver;

    cout << solver.maxValue("99", 9) << "\n";
    cout << solver.maxValue("-13", 2) << "\n";
    cout << solver.maxValue("73", 6) << "\n";
    cout << solver.maxValue("-55", 2) << "\n";
    cout << solver.maxValue("28824579515", 8) << "\n";

    return 0;
}