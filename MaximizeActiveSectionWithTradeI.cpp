#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        int n = s.length();
        int ans = 0, mx = 0, pre = -1;
        int i = 0;

        while (i < n)
        {
            int j = i;
            while (j < n && s[j] == s[i])
            {
                j++;
            }
            int cur = j - i;
            if (s[i] == '1')
            {
                ans += cur;
            }
            else
            {
                if (pre != -1)
                {
                    mx = max(mx, pre + cur);
                }
                pre = cur;
            }
            i = j;
        }

        return ans + mx;
    }
};

int main()
{
    Solution sol;

    cout << sol.maxActiveSectionsAfterTrade("01") << "\n";
    cout << sol.maxActiveSectionsAfterTrade("0100") << "\n";
    cout << sol.maxActiveSectionsAfterTrade("1000100") << "\n";
    cout << sol.maxActiveSectionsAfterTrade("01010") << "\n";
    cout << sol.maxActiveSectionsAfterTrade("000") << "\n";
    cout << sol.maxActiveSectionsAfterTrade("111") << "\n";
    cout << sol.maxActiveSectionsAfterTrade("101") << "\n";
    cout << sol.maxActiveSectionsAfterTrade("001110000111") << "\n";

    return 0;
}