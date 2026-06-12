#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    void backtrack(string num, int target, int index, string path, long long currentVal, long long prevVal, vector<string> &result)
    {
        if (index == num.length())
        {
            if (currentVal == target)
            {
                result.push_back(path);
            }
            return;
        }

        for (int i = index; i < num.length(); i++)
        {
            if (i > index && num[index] == '0')
            {
                break;
            }

            string partStr = num.substr(index, i - index + 1);
            long long partNum = stoll(partStr);

            if (index == 0)
            {
                backtrack(num, target, i + 1, partStr, partNum, partNum, result);
            }
            else
            {
                backtrack(num, target, i + 1, path + "+" + partStr, currentVal + partNum, partNum, result);
                backtrack(num, target, i + 1, path + "-" + partStr, currentVal - partNum, -partNum, result);
                backtrack(num, target, i + 1, path + "*" + partStr, currentVal - prevVal + (prevVal * partNum), prevVal * partNum, result);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target)
    {
        vector<string> result;
        if (num.empty())
        {
            return result;
        }
        backtrack(num, target, 0, "", 0, 0, result);
        return result;
    }
};

int main()
{
    Solution solver;

    string num1 = "123";
    int target1 = 6;

    string num2 = "232";
    int target2 = 8;

    string num3 = "105";
    int target3 = 5;

    vector<string> res1 = solver.addOperators(num1, target1);
    vector<string> res2 = solver.addOperators(num2, target2);
    vector<string> res3 = solver.addOperators(num3, target3);

    cout << "--- Expression Add Operators Tests ---" << endl;

    cout << "Test 1:" << endl;
    for (const string &expr : res1)
    {
        cout << "  " << expr << endl;
    }

    cout << "Test 2:" << endl;
    for (const string &expr : res2)
    {
        cout << "  " << expr << endl;
    }

    cout << "Test 3:" << endl;
    for (const string &expr : res3)
    {
        cout << "  " << expr << endl;
    }

    return 0;
}