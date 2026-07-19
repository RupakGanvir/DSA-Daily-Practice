#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string smallestSubsequence(string s)
    {
        vector<int> last_occurrence(26, 0);
        vector<bool> in_stack(26, false);

        for (int i = 0; i < s.length(); ++i)
        {
            last_occurrence[s[i] - 'a'] = i;
        }

        string result = "";

        for (int i = 0; i < s.length(); ++i)
        {
            char c = s[i];
            if (in_stack[c - 'a'])
            {
                continue;
            }

            while (!result.empty() && result.back() > c && last_occurrence[result.back() - 'a'] > i)
            {
                in_stack[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            in_stack[c - 'a'] = true;
        }

        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solver;

    string s1 = "bcabc";
    cout << "--- Test Case 1 ---\n";
    cout << "Output: " << solver.smallestSubsequence(s1) << "\n\n";

    string s2 = "cbacdcbc";
    cout << "--- Test Case 2 ---\n";
    cout << "Output: " << solver.smallestSubsequence(s2) << "\n\n";

    string s3 = "cdadabcc";
    cout << "--- Test Case 3 ---\n";
    cout << "Output: " << solver.smallestSubsequence(s3) << "\n";

    return 0;
}