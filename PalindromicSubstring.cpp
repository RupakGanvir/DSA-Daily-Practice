#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int countFromCenter(string s, int left, int right)
    {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s)
    {
        int totalPalindromes = 0;

        for (int i = 0; i < s.length(); i++)
        {
            totalPalindromes += countFromCenter(s, i, i);

            totalPalindromes += countFromCenter(s, i, i + 1);
        }

        return totalPalindromes;
    }
};

int main()
{
    Solution sol;
    string s = "aaa";
    cout << "Total palindromic substrings in '" << s << "': " << sol.countSubstrings(s) << endl;

    return 0;
}