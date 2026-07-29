#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
private:
    long long getPermutations(const vector<int> &counts)
    {
        long long perms = 1;
        int currentLen = 0;
        for (int c : counts)
        {
            if (c > 0)
            {
                for (int i = 1; i <= c; ++i)
                {
                    currentLen++;
                    perms = (perms * currentLen) / i;
                }
            }
        }
        return perms;
    }

public:
    string getKthPalindromicString(string s, long long k)
    {
        vector<int> counts(26, 0);
        for (char c : s)
        {
            counts[c - 'a']++;
        }

        int oddCount = 0;
        char midChar = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (counts[i] % 2 != 0)
            {
                oddCount++;
                midChar = (char)(i + 'a');
            }
            counts[i] /= 2;
        }

        if (oddCount > 1)
        {
            return "";
        }

        int halfLen = s.length() / 2;
        string firstHalf = "";

        for (int i = 0; i < halfLen; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                if (counts[j] > 0)
                {
                    counts[j]--;
                    long long perms = getPermutations(counts);

                    if (k <= perms)
                    {
                        firstHalf += (char)(j + 'a');
                        break;
                    }
                    else
                    {
                        k -= perms;
                        counts[j]++;
                    }
                }
            }
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        if (oddCount == 1)
        {
            return firstHalf + midChar + secondHalf;
        }
        return firstHalf + secondHalf;
    }
};

int main()
{
    Solution solver;

    cout << solver.getKthPalindromicString("aabbcc", 2) << "\n";
    cout << solver.getKthPalindromicString("abc", 1) << "\n";
    cout << solver.getKthPalindromicString("aaaa", 1) << "\n";
    cout << solver.getKthPalindromicString("aabbb", 3) << "\n";
    cout << solver.getKthPalindromicString("abacaba", 1) << "\n";

    return 0;
}