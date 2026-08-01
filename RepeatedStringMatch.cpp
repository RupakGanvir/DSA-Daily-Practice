#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        string repeated_a = a;
        int count = 1;

        while (repeated_a.length() < b.length())
        {
            repeated_a += a;
            count++;
        }

        if (repeated_a.find(b) != string::npos)
        {
            return count;
        }

        repeated_a += a;
        count++;

        if (repeated_a.find(b) != string::npos)
        {
            return count;
        }

        return -1;
    }
};

int main()
{
    Solution solver;

    cout << solver.repeatedStringMatch("abcd", "cdabcdab") << "\n";
    cout << solver.repeatedStringMatch("a", "aa") << "\n";
    cout << solver.repeatedStringMatch("a", "a") << "\n";
    cout << solver.repeatedStringMatch("abc", "wxyz") << "\n";

    return 0;
}