#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {
        for (int i = num.length() - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 != 0)
            {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main()
{
    Solution solver;

    string num1 = "52";
    string num2 = "4206";
    string num3 = "35427";
    string num4 = "10133890";

    cout << "--- Largest Odd Number in String Tests ---" << endl;
    cout << "Test 1:       " << solver.largestOddNumber(num1) << endl;
    cout << "Test 2:        " << solver.largestOddNumber(num2) << endl;
    cout << "Test 3:   " << solver.largestOddNumber(num3) << endl;
    cout << "Test 4: " << solver.largestOddNumber(num4) << endl;

    return 0;
}