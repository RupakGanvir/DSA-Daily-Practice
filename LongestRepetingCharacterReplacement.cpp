#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> count(26, 0);
        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++)
        {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k)
            {
                count[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main()
{
    Solution solver;

    string s1 = "ABAB";
    int k1 = 2;

    string s2 = "AABABBA";
    int k2 = 1;

    cout << "--- Longest Repeating Character Replacement Tests ---" << endl;
    cout << "Test 1: " << solver.characterReplacement(s1, k1) << endl;
    cout << "Test 2: " << solver.characterReplacement(s2, k2) << endl;

    return 0;
}