#include <iostream>
#include <string>
#include <climits>

class Solution
{
public:
    int myAtoi(std::string s)
    {
        int i = 0;
        int n = s.length();
        int sign = 1;
        int result = 0;

        while (i < n && s[i] == ' ')
        {
            i++;
        }

        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && std::isdigit(s[i]))
        {
            int digit = s[i] - '0';

            if (result > (INT_MAX - digit) / 10)
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};

int main()
{
    Solution sol;

    std::string testCases[] = {
        "42",
        "   -42",
        "4193 with words",
        "words and 987",
        "-91283472332",
        "2147483648"};

    std::cout << "Input\t\t\t| Output" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    for (const std::string &test : testCases)
    {
        std::cout << "\"" << test << "\"\t\t| " << sol.myAtoi(test) << std::endl;
    }

    return 0;
}