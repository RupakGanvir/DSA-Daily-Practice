#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.length();
        int m = needle.length();

        if (m == 0)
            return 0;

        if (m > n)
            return -1;

        for (int i = 0; i <= n - m; i++)
        {
            int j = 0;

            while (j < m && haystack[i + j] == needle[j])
            {
                j++;
            }

            if (j == m)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;

    string haystack1 = "sadbutsad";
    string needle1 = "sad";
    cout << "Test 1 - Haystack: " << haystack1 << ", Needle: " << needle1 << endl;
    cout << "Result: " << sol.strStr(haystack1, needle1) << " (Expected: 0)" << endl
         << endl;

    string haystack2 = "leetcode";
    string needle2 = "leeto";
    cout << "Test 2 - Haystack: " << haystack2 << ", Needle: " << needle2 << endl;
    cout << "Result: " << sol.strStr(haystack2, needle2) << " (Expected: -1)" << endl
         << endl;

    string haystack3 = "hello";
    string needle3 = "ll";
    cout << "Test 3 - Haystack: " << haystack3 << ", Needle: " << needle3 << endl;
    cout << "Result: " << sol.strStr(haystack3, needle3) << " (Expected: 2)" << endl;

    return 0;
}