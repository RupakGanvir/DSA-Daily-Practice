#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
private:
    long long getCombinations(int n, int r, long long limit)
    {
        if (r > n - r)
            r = n - r;

        long long res = 1;

        for (int i = 1; i <= r; i++)
        {
            if (res > limit)
                return limit + 1;

            res = res * (n - i + 1) / i;

            if (res > limit)
                return limit + 1;
        }

        return res;
    }

    long long getPermutations(const vector<int> &counts, long long limit)
    {
        long long perms = 1;
        int len = 0;

        for (int c : counts)
        {
            if (c == 0)
                continue;

            long long ways = getCombinations(len + c, c, limit);

            if (ways > limit)
                return limit + 1;

            if (perms > limit / ways)
                return limit + 1;

            perms *= ways;
            len += c;
        }

        return perms;
    }

public:
    string smallestPalindrome(string s, int k)
    {
        vector<int> counts(26, 0);

        for (char c : s)
            counts[c - 'a']++;

        int oddCount = 0;
        char midChar = 0;

        for (int i = 0; i < 26; i++)
        {
            if (counts[i] % 2)
            {
                oddCount++;
                midChar = char('a' + i);
            }
            counts[i] /= 2;
        }

        if (oddCount > 1)
            return "";

        if (getPermutations(counts, k) < k)
            return "";

        int halfLen = s.size() / 2;
        string firstHalf;

        for (int pos = 0; pos < halfLen; pos++)
        {
            for (int ch = 0; ch < 26; ch++)
            {
                if (counts[ch] == 0)
                    continue;

                counts[ch]--;

                long long cnt = getPermutations(counts, k);

                if (cnt >= k)
                {
                    firstHalf.push_back(char('a' + ch));
                    break;
                }

                k -= cnt;
                counts[ch]++;
            }
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        if (oddCount)
            return firstHalf + midChar + secondHalf;

        return firstHalf + secondHalf;
    }
};

int main()
{
    Solution solver;

    cout << solver.smallestPalindrome("aabbcc", 2) << "\n";
    cout << solver.smallestPalindrome("abc", 1) << "\n";
    cout << solver.smallestPalindrome("aaaa", 1) << "\n";
    cout << solver.smallestPalindrome("aabbb", 3) << "\n";
    cout << solver.smallestPalindrome("abacaba", 1) << "\n";

    return 0;
}