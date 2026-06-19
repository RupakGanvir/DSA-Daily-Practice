#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty() || s.length() < t.length())
        {
            return "";
        }

        vector<int> targetCount(128, 0);
        for (char c : t)
        {
            targetCount[c]++;
        }

        vector<int> windowCount(128, 0);
        int left = 0;
        int minLen = INT_MAX;
        int minStart = 0;
        int matched = 0;
        int required = 0;

        for (int i = 0; i < 128; i++)
        {
            if (targetCount[i] > 0)
            {
                required++;
            }
        }

        for (int right = 0; right < s.length(); right++)
        {
            char c = s[right];
            if (targetCount[c] > 0)
            {
                windowCount[c]++;
                if (windowCount[c] == targetCount[c])
                {
                    matched++;
                }
            }

            while (matched == required)
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];
                if (targetCount[leftChar] > 0)
                {
                    if (windowCount[leftChar] == targetCount[leftChar])
                    {
                        matched--;
                    }
                    windowCount[leftChar]--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

int main()
{
    Solution solver;

    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";

    string s2 = "a";
    string t2 = "a";

    string s3 = "a";
    string t3 = "aa";

    cout << "--- Minimum Window Substring Tests ---" << endl;
    cout << "Test 1: " << solver.minWindow(s1, t1) << endl;
    cout << "Test 2: " << solver.minWindow(s2, t2) << endl;
    cout << "Test 3: " << solver.minWindow(s3, t3) << endl;

    return 0;
}