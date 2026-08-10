#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string smallestSubsequence(string s, int k, char letter, int repetition)
    {
        int n = s.length();
        int rem_letters = 0;
        for (char c : s)
        {
            if (c == letter)
                rem_letters++;
        }

        string ans = "";
        int letters_in_stack = 0;

        for (int i = 0; i < n; ++i)
        {
            char c = s[i];

            while (!ans.empty() && ans.back() > c &&
                   (ans.length() - 1 + n - i >= k) &&
                   (ans.back() != letter || letters_in_stack - 1 + rem_letters >= repetition))
            {
                if (ans.back() == letter)
                {
                    letters_in_stack--;
                }
                ans.pop_back();
            }

            if (ans.length() < k)
            {
                if (c == letter)
                {
                    ans.push_back(c);
                    letters_in_stack++;
                }
                else if (k - ans.length() > max(0, repetition - letters_in_stack))
                {
                    ans.push_back(c);
                }
            }

            if (c == letter)
            {
                rem_letters--;
            }
        }

        return ans;
    }
};

int main()
{
    Solution solver;

    cout << "\"" << solver.smallestSubsequence("leet", 3, 'e', 1) << "\"\n";
    cout << "\"" << solver.smallestSubsequence("leetcode", 4, 'e', 2) << "\"\n";
    cout << "\"" << solver.smallestSubsequence("bb", 2, 'b', 2) << "\"\n";

    return 0;
}