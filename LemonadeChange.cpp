#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0;
        int ten = 0;

        for (int bill : bills)
        {
            if (bill == 5)
            {
                five++;
            }
            else if (bill == 10)
            {
                if (five == 0)
                {
                    return false;
                }
                five--;
                ten++;
            }
            else
            {
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution solver;

    vector<int> b1 = {5, 5, 5, 10, 20};
    vector<int> b2 = {5, 5, 10, 10, 20};

    cout << "--- Lemonade Change Tests ---" << endl;
    cout << "Test 1: " << (solver.lemonadeChange(b1) ? "true" : "false") << endl;
    cout << "Test 2: " << (solver.lemonadeChange(b2) ? "true" : "false") << endl;

    return 0;
}