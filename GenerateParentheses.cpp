#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string> &result, string current, int openCount, int closeCount, int n)
    {
        if (current.length() == 2 * n)
        {
            result.push_back(current);
            return;
        }

        if (openCount < n)
        {
            backtrack(result, current + "(", openCount + 1, closeCount, n);
        }

        if (closeCount < openCount)
        {
            backtrack(result, current + ")", openCount, closeCount + 1, n);
        }
    }
};

int main()
{
    Solution sol;
    int n = 3;
    vector<string> combinations = sol.generateParenthesis(n);

    cout << "Generated Parentheses for n=" << n << ":" << endl;
    for (const string &s : combinations)
    {
        cout << s << endl;
    }

    return 0;
}