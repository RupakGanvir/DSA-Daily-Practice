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
        int ans = 0, mx = 0, pre = 0;
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
                mx = max(mx, pre + cur);
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

    string s1 = "0100";
    cout << sol.maxActiveSectionsAfterTrade(s1) << "\n";

    string s2 = "1000100";
    cout << sol.maxActiveSectionsAfterTrade(s2) << "\n";

    string s3 = "01010";
    cout << sol.maxActiveSectionsAfterTrade(s3) << "\n";

    string s4 = "111";
    cout << sol.maxActiveSectionsAfterTrade(s4) << "\n";

    string s5 = "000";
    cout << sol.maxActiveSectionsAfterTrade(s5) << "\n";

    string s6 = "001110000111";
    cout << sol.maxActiveSectionsAfterTrade(s6) << "\n";

    return 0;
}