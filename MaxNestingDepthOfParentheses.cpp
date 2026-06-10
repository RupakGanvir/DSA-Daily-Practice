#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int currentDepth = 0;
        int maxDepth = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                currentDepth++;
                maxDepth = max(maxDepth, currentDepth);
            }
            else if (c == ')')
            {
                currentDepth--;
            }
        }

        return maxDepth;
    }
};

int main()
{
    Solution solver;

    string s1 = "(1+(2*3)+((8)/4))+1";
    string s2 = "(1)+((2))+(((3)))";
    string s3 = "()(())((()()))";

    cout << "--- Maximum Nesting Depth Tests ---" << endl;
    cout << "Test 1: " << solver.maxDepth(s1) << endl;
    cout << "Test 2: " << solver.maxDepth(s2) << endl;
    cout << "Test 3: " << solver.maxDepth(s3) << endl;

    return 0;
}