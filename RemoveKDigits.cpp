#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num.length() == k)
        {
            return "0";
        }

        string result = "";

        for (char digit : num)
        {
            while (!result.empty() && result.back() > digit && k > 0)
            {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }

        while (k > 0 && !result.empty())
        {
            result.pop_back();
            k--;
        }

        size_t nonZeroIndex = result.find_first_not_of('0');
        if (nonZeroIndex == string::npos)
        {
            return "0";
        }

        return result.substr(nonZeroIndex);
    }
};

int main()
{
    Solution solver;

    string num1 = "1432219";
    int k1 = 3;

    string num2 = "10200";
    int k2 = 1;

    string num3 = "10";
    int k3 = 2;

    cout << "--- Remove K Digits Tests ---" << endl;
    cout << "Test 1: " << solver.removeKdigits(num1, k1) << endl;
    cout << "Test 2: " << solver.removeKdigits(num2, k2) << endl;
    cout << "Test 3: " << solver.removeKdigits(num3, k3) << endl;

    return 0;
}