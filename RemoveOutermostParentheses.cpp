#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string result = "";

        int open_count = 0;

        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == '(')
            {
                if (open_count > 0)
                {
                    result += s[i];
                }
                open_count++;
            }
            else if (s[i] == ')')
            {
                open_count--;

                if (open_count > 0)
                {
                    result += s[i];
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution solver;

    string s1 = "(()())(())";

    string s2 = "(()())(())(()(()))";

    string s3 = "()()";

    cout << "--- Remove Outermost Parentheses Tests ---" << endl;
    cout << "Test 1:      " << solver.removeOuterParentheses(s1) << endl;
    cout << "Test 2: " << solver.removeOuterParentheses(s2) << endl;
    cout << "Test 3:             " << solver.removeOuterParentheses(s3) << endl;

    return 0;
}