#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string smallestPalindromicRearrangement(string s)
    {
        vector<int> charCount(26, 0);
        for (char c : s)
        {
            charCount[c - 'a']++;
        }

        string leftHalf = "";
        string middle = "";

        for (int i = 0; i < 26; i++)
        {
            if (charCount[i] % 2 != 0)
            {
                middle = string(1, i + 'a');
            }
            leftHalf.append(charCount[i] / 2, i + 'a');
        }

        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        return leftHalf + middle + rightHalf;
    }
};

int main()
{
    Solution solver;

    cout << solver.smallestPalindromicRearrangement("babab") << "\n";
    cout << solver.smallestPalindromicRearrangement("cbaabc") << "\n";
    cout << solver.smallestPalindromicRearrangement("z") << "\n";
    cout << solver.smallestPalindromicRearrangement("racecar") << "\n";
    cout << solver.smallestPalindromicRearrangement("aabbc") << "\n";

    return 0;
}