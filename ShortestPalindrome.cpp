#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        if (s.empty())
        {
            return "";
        }

        string reversedString = s;
        reverse(reversedString.begin(), reversedString.end());

        string combinedString = s + "#" + reversedString;
        vector<int> lps(combinedString.length(), 0);

        for (int i = 1; i < combinedString.length(); i++)
        {
            int j = lps[i - 1];

            while (j > 0 && combinedString[i] != combinedString[j])
            {
                j = lps[j - 1];
            }

            if (combinedString[i] == combinedString[j])
            {
                j++;
            }

            lps[i] = j;
        }

        int longestPalindromicPrefixLength = lps.back();
        string suffixToAdd = s.substr(longestPalindromicPrefixLength);
        reverse(suffixToAdd.begin(), suffixToAdd.end());

        return suffixToAdd + s;
    }
};

int main()
{
    Solution solver;

    cout << solver.shortestPalindrome("aacecaaa") << "\n";
    cout << solver.shortestPalindrome("abcd") << "\n";
    cout << solver.shortestPalindrome("") << "\n";
    cout << solver.shortestPalindrome("a") << "\n";
    cout << solver.shortestPalindrome("racecar") << "\n";
    cout << solver.shortestPalindrome("abcbabcab") << "\n";

    return 0;
}