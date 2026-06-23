#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int low = 0;
        int high = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                low++;
                high++;
            }
            else if (c == ')')
            {
                low = max(0, low - 1);
                high--;
            }
            else if (c == '*')
            {
                low = max(0, low - 1);
                high++;
            }

            if (high < 0)
            {
                return false;
            }
        }

        return low == 0;
    }
};

int main()
{
    Solution solver;

    string s1 = "()";
    string s2 = "(*)";
    string s3 = "(*))";

    cout << "--- Valid Parenthesis String Tests ---" << endl;
    cout << "Test 1: " << (solver.checkValidString(s1) ? "true" : "false") << endl;
    cout << "Test 2: " << (solver.checkValidString(s2) ? "true" : "false") << endl;
    cout << "Test 3: " << (solver.checkValidString(s3) ? "true" : "false") << endl;

    return 0;
}