#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        bool seen_digit = false;
        bool seen_exponent = false;
        bool seen_dot = false;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            if (c >= '0' && c <= '9')
            {
                seen_digit = true;
            }
            else if (c == '+' || c == '-')
            {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                {
                    return false;
                }
            }
            else if (c == 'e' || c == 'E')
            {
                if (seen_exponent || !seen_digit)
                {
                    return false;
                }
                seen_exponent = true;

                seen_digit = false;
            }
            else if (c == '.')
            {
                if (seen_dot || seen_exponent)
                {
                    return false;
                }
                seen_dot = true;
            }
            else
            {
                return false;
            }
        }

        return seen_digit;
    }
};

int main()
{
    Solution solver;

    vector<string> valid_tests = {"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};
    vector<string> invalid_tests = {"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"};

    cout << "--- Valid Numbers (Should all be True) ---" << endl;
    for (string test : valid_tests)
    {
        cout << "Test '" << test << "': " << (solver.isNumber(test) ? "True" : "False") << endl;
    }

    cout << "\n--- Invalid Numbers (Should all be False) ---" << endl;
    for (string test : invalid_tests)
    {
        cout << "Test '" << test << "': " << (solver.isNumber(test) ? "True" : "False") << endl;
    }

    return 0;
}